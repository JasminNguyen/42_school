
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int picoshell(char **cmds[])
{
    //count commands
    int number_of_commands = 0;
    while(cmds[number_of_commands])
    {
        number_of_commands++;
    }

    //create pipes for number of commands - 1
    int pipe_array[number_of_commands -1][2];
    for(int i = 0; i < number_of_commands - 1; i++)
    {
        if(pipe(pipe_array[i]) == -1)
        {
            perror("pipe creation");
            return -1;
        }
    }

    //looping through all the commands
    int child_process_index = 0;
    int first_command = 0;
    int last_command = number_of_commands - 1;
    while(child_process_index < number_of_commands)
    {
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
            for(int i = 0; i < number_of_commands - 1; i++)
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

    for(int i = 0; i < number_of_commands - 1; i++)
    {
        close(pipe_array[i][0]);
        close(pipe_array[i][1]);
    }
    for(int i = 0; i < number_of_commands; i++)
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