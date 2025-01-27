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

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int picoshell(char **cmds[])
{
    int i = 0;
    int fd[2];
    int prev_fd = 0;
    pid_t pid;

    while(cmds[i])
    {
        if(cmds[i+1])
        {
            if(pipe(fd) == -1)
            {
                return -1;
            }
        }
        pid = fork();
        if(pid == -1)
        {
            close(fd[0]);
            close(fd[1]);
            return -1;
        }
        if(pid == 0)
        {
            if(prev_fd != 0)
            {
                if(dup2(prev_fd, STDIN_FILENO) == -1)
                {
                    return -1;
                } 
                close(prev_fd);
            }
            if(cmds[i+1])
            {
                close(fd[0]);
                if(dup2(fd[1], STDOUT_FILENO) == -1)
                {
                    return -1;
                }
                close(fd[1]);
            }
            if(execvp(cmds[i][0], cmds[i]) == -1)
            {
                exit(1);
            }
        }
        else
        {
             if(prev_fd != 0)
            {
                close(prev_fd);
            }
            if(cmds[i+1])
            {
                close(fd[1]);
                prev_fd = fd[0];
            }
        }
        i++;
    }
    while(wait(NULL) > 0)
    ;
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


