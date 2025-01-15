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


/* Was ist der Typ von cmds?
cmds ist ein dreifacher Zeiger (char ***), was bedeutet:
cmds: Ein Zeiger auf ein Array von char **.
cmds[i]: Jedes Element des Arrays ist ein char **, also ein Zeiger auf ein Array von Strings (char *).
cmds[i][j]: Ein String (char *). */
/* 
cmds = {
    {"ls", "-l", "-a", NULL},    // Erster Befehl
    {"grep", "main", NULL},     // Zweiter Befehl
    {"wc", "-l", NULL},         // Dritter Befehl
    NULL                        // Ende des Arrays
}; */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int picoshell(char ***cmds)
{
    //counting the commands
    int number_of_commands = 0;
    while(cmds[number_of_commands]) // DON'T FORGET TO INDEX HERE
    {
        number_of_commands++;
    }
    printf("number of commands: %d\n", number_of_commands);
    //creating pipes
    int i = 0;
    int pipe_array[number_of_commands - 1][2];
    while(i < number_of_commands - 1)
    {
        if(pipe(pipe_array[i]) == -1)
        {
            perror("pipe creation");
            return -1;
        }
        i++;
    }
    //going through commands and forking childs for each command
    int childprocess_index = 0;
    int first_command = 0;
    int last_command = number_of_commands - 1;
    while(childprocess_index < number_of_commands)
    {
        pid_t pid = fork();
        if(pid == -1)
        {
            perror("fork");
            exit (-1);
        }
        if(pid == 0) //child
        {
            //make sure it's not the first command
            if(childprocess_index != first_command)
            {
                if(dup2(pipe_array[childprocess_index - 1][0], STDIN_FILENO) == -1) //DON'T FORGET TO INDEX THE PIPE BEFORE THE COMMAND (childprocess_index - 1) //second parameter will be overwritten by first
                {
                    perror("dup2 infile");
                    exit (-1);
                }
            }
            //make sure it's not the last command
            if(childprocess_index != last_command)
            {
                if(dup2(pipe_array[childprocess_index][1], STDOUT_FILENO) == -1)
                {
                    perror("dup2 outfile");
                    exit (-1);
                }
            }
            for(int i = 0; i < number_of_commands - 1; i++)
            {
                close(pipe_array[i][0]);
                close(pipe_array[i][1]);
            }
            if(execvp(cmds[childprocess_index][0], cmds[childprocess_index]) == -1)
            {
                perror("execvp");
                exit(-1);
            }
        }
        childprocess_index++;
    }

    //parent
    //close pipes
     for(int i = 0; i < number_of_commands - 1; i++) //NUMBER OF COMMANDS - 1
    {
        close(pipe_array[i][0]);
        close(pipe_array[i][1]);
    }
     for(int i = 0; i < number_of_commands; i++) //NUMBER OF COMMANDS
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

