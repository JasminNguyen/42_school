#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
const int RETURN_SUCCESS = 0;
const int RETURN_FAILURE = 1;
const int STD_IN = 0;
const int STD_OUT = 1;

int picoshell(char **cmds[])
{
    if(!cmds || !cmds[0])
    {
        return RETURN_SUCCESS;
    }

	int cmd_count = 0;
	while(cmds[cmd_count] != NULL)
	{
		cmd_count++;
	}
	printf("number of commands:%d\n", cmd_count);

	int first_child = 0;
	int last_child = cmd_count - 1;
	int childprocess_index = 0;
	int pipe_array[cmd_count - 1][2]; // 2D-Array für Pipes: jede Pipe hat zwei Enden
                                 // pipe_array[i][0] -> Lese-Ende der i-ten Pipe
                                 // pipe_array[i][1] -> Schreib-Ende der i-ten Pipe

	//creating the pipes before any forking
	while (childprocess_index < cmd_count - 1)
	{
		if(pipe(pipe_array[childprocess_index]) == -1)
		{
			perror("pipe");
			return RETURN_FAILURE;
		}
		childprocess_index++;
	}
	
	//going through the commands
	childprocess_index = 0;
	while(childprocess_index < cmd_count)
	{
		pid_t pid = fork();
		if( pid == -1)
		{
			perror("fork");
			return RETURN_FAILURE;
		}
		if(pid == 0) //child
		{
			if(childprocess_index != first_child)
			{
				if(dup2(pipe_array[childprocess_index - 1][0], STD_IN) == -1)
				{
					perror("dup 2 infile");
					exit (RETURN_FAILURE);
				}
			}
			if(childprocess_index != last_child)
			{
				if(dup2(pipe_array[childprocess_index][1], STD_OUT) == -1)
				{
					perror("dup2 outfile");
					exit (RETURN_FAILURE);
				}
			}
			// Schließe alle unbenutzten Enden
        	for (int j = 0; j < cmd_count - 1; j++) 
			{
            	close(pipe_array[j][0]);
            	close(pipe_array[j][1]);
        	}
			execvp(cmds[childprocess_index][0], cmds[childprocess_index]);
			perror ("execvp");
			exit (RETURN_FAILURE);
		}
		childprocess_index++;
	}


	// Elternprozess: Schließe alle Enden
	for (int i = 0; i < cmd_count - 1; i++) 
	{
    	close(pipe_array[i][0]);
    	close(pipe_array[i][1]);
	}
	// Warten auf Kindprozesse
	for (int i = 0; i < cmd_count; i++) 
	{
    	if(wait(NULL) == -1)
		{
			perror("wait");
			return RETURN_FAILURE;
		}
	}
	int return_value = RETURN_SUCCESS;
	return return_value;

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