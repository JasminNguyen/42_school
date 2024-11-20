#include <stdlib.h>
#include <unistd.h>
const int RETURN_SUCCESS = 0;
const int RETURN_FAILURE = 1;

int picoshell(char **cmds[])
{
    if(!cmds || !cmds[0])
    {
        return RETURN_SUCCESS;
    }

    char *first_arrray = *cmds[0];
    pid_t child_pid = fork();
    if(child_pid == 0)
    {
        execvp(first_arrray, )
    }
    else
    {

    }
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