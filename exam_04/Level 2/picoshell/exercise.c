/* TASK:
Allowed functions: close, fork, wait, exit, execvp, dup2, pipe
--------------------------------------------------------------------------------
Write the followingfunction

int picoshell(char **cmds[]);

The goal of this function is to execute a pipeline.
It must execute each commands of cmds and connect the output of one to the input
of the next command (just like a shell)

Cmds contains a null-terminated list of valid commands.
Each rows of cmds are an argv array directly useable for a call to execvp.
The first arguments of each command is the command name or path and can be
passed directly as the first argument of execvp.

If any error occur, the function must return 1 (you must of course close all the
open fds before), otherwise the function must wait all child processes and return 0

You will find in this directory a file main.c which contain something to help you
test your function.

For example this should work:
$>./picoshell /bin/ls "|" /usr/bin/grep picoshell
picoshell

$>./picoshell echo 'squalala!' "|" cat "|" sed 's/a/b/g'
squblblb!

Hints:
Do not leak file descriptors
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int picoshell(char **cmds[])
{
    //couting commands
    int nbr_of_commands = 0;
    while(cmds[nbr_of_commands])
    {
        nbr_of_commands++;
    }

    //creating pipes for nbr_of_commands -1
    int pipe_array[nbr_of_commands -1][2];
    for(int i = 0; i < nbr_of_commands -1; i++)
    {
        if(pipe(pipe_array[i]) == -1)
        {
            perror("pipe creation");
            return -1;
        }
    }

    //looping through all commands and forking
    int child_process_index = 0;
    int first_command = 0;
    int last_command = nbr_of_commands - 1;
    while(child_process_index < nbr_of_commands)
    { 
        //forking 
        pid_t pid = fork();
        if(pid == -1)
        {
            perror("forking");
            return -1;
        }
        if(pid == 0)
        {
            if(child_process_index != first_command)
            {
                if(dup2(pipe_array[child_process_index - 1][0], STDIN_FILENO) == -1)
                {
                    perror("dup2 infile");
                    exit(1);
                }
            }
            if(child_process_index != last_command)
            {
                if(dup2(pipe_array[child_process_index][1], STDOUT_FILENO) == -1)
                {
                    perror("dup2 outfile");
                    exit(1);
                }
            }
            for(int i = 0; i < nbr_of_commands -1; i++)
            {
                close(pipe_array[i][0]);
                close(pipe_array[i][1]);
            }
            if(execvp(cmds[child_process_index][0], cmds[child_process_index]) == -1)
            {
                perror("execvp");
                exit(1);
            }

        }
        child_process_index++;
    } 
    for(int i = 0; i < nbr_of_commands - 1; i++)
    {
        close(pipe_array[i][0]);
        close(pipe_array[i][1]);
    }
    for(int i = 0; i < nbr_of_commands; i++)
    {
        wait(NULL);
    }

   return 0;
}


int main(int argc, char **argv)
{
	int cmd_size = 1;

	for (int i = 1; i < argc; i++)
	{
		if (!strcmp(argv[i], "|"))
			cmd_size++;
	}

	char ***cmds = calloc(cmd_size + 1, sizeof(char ***));
	cmds[0] = argv + 1;
	int cmds_i = 1;
	for (int i = 1; i < argc; i++)
	{
		if (!strcmp(argv[i], "|"))
		{
			cmds[cmds_i] = argv + i + 1;
			argv[i] = NULL;
			cmds_i++;
		}
	}
	int ret = picoshell(cmds);
	if (ret)
		perror("picoshell");
	free(cmds);
	return ret;
}

