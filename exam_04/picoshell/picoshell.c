#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
const int RETURN_SUCCESS = 0;
const int RETURN_FAILURE = 1;

int picoshell(char **cmds[])
{
    if(!cmds || !cmds[0])
    {
        return RETURN_SUCCESS;
    }

    char **first_command = cmds[0];
	char **second_command = cmds[1];
	int status;
	int array[2];
	if(pipe(array) != 0)
	{
		return RETURN_FAILURE;
	}
	printf("before dup2\n");

	
	printf("after dup2\n");
	pid_t child_pid = fork();
	
    if(child_pid == 0)//write
    {	
		dup2(array[1], 1); //second argument is going to be overwritten by first argument
		close(array[0]);
		execvp(first_command[0], first_command);

    }
    else
    {
		child_pid = fork();
		if(child_pid == 0) //read
		{
			dup2(array[0], 0);
			close(array[1]);
			printf("closed write end\n");
			printf("%s\n", second_command[0]);
			execvp(second_command[0], second_command);
		}
		printf("before wait\n");
		wait(&status);
		printf("after first wait\n");
		wait(&status);
		close(array[0]);
		close(array[1]);
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