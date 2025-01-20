#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int ft_popen(const char *file, const char *argv[], char type)
{
    if(type != 'r' && type != 'w')
    {
        return -1;
    }
    int fd[2];
    if(pipe(fd) == -1)
    {
       perror("piping");
       return -1; 
    }
    pid_t pid = fork();
    if(pid == -1)
    {
        close(fd[0]);
        close(fd[1]);
        perror("forking");
        return -1;
    }
    if(pid == 0)
    {
        if(type == 'r')
        {
            close(fd[0]);
            if(dup2(fd[1], STDOUT_FILENO) == -1)
            {
                perror("dup2 outfile");
                exit(1);
            }
            close(fd[1]);
        }
        if(type == 'w')
        {
            close(fd[1]);
            if(dup2(fd[0], STDIN_FILENO) == -1)
            {
                perror("dup2 infile");
                exit(1);
            }
            close(fd[0]);
        }
        if(execvp(file, (char * const *)argv) == -1)
        {
            perror("execvp");
            exit(1);
        }
    }
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
    return -1;
}

