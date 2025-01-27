#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_popen(const char *file, const char *argv[], char type)
{
    if(!file || (type != 'r' && type != 'w'))
	{
		return -1;
	}
	int fd[2];
	if(pipe(fd) == -1)
	{
		return -1;
	}
	pid_t pid = fork();
	if(pid == -1)
	{
		close(fd[0]);
		close(fd[1]);
		return -1;
	}
	if(pid == 0)
	{
		if(type == 'r')
		{
			close(fd[0]);
			if(dup2(fd[1], STDOUT_FILENO) == -1)
			{
				exit(1);
			}
			close(fd[1]);
		}
		if(type == 'w')
		{
			close(fd[1]);
			if(dup2(fd[0], STDIN_FILENO) == -1)
			{
				exit(1);
			}
		}
		if(execvp(file, (char * const *)argv) == -1)
		{
			exit(1);
		}
	}
	else
	{
		if(type == 'r')
		{
			close(fd[1]);
			return (fd[0]);
		}
		if(type == 'w')
		{
			close(fd[0]);
			return(fd[1]);
		}
	}
	return -1;
}


int main()
{
    int fd = ft_popen("ls", (const char *[]) {"ls", NULL}, 'r');
    char *line;
    while ((line = get_next_line(fd)))
        ft_putstr(line);
}