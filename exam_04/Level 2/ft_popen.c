/* TASK:
Name: ft_popen
Allowed functions: pipe, fork, dup2, execvp, close, exit
--------------------------------------------------------------------------------
Write the following function:

int ft_popen(const char *file, const char *argv[], char type);

The function must launch the executable file with the arguments argv (using execvp).
If type is 'r' the function must return a file descriptor connected to the output of the command.
If type is 'w' the function must return a file descriptor connected to the input of the command.
In case of error or invalid parameter the function must return -1.

For example the function could be used like that:

int main()
{
    int fd = ft_popen("ls", (const char *[]) {"ls", NULL}, 'r');
    char *line;
    while ((line = get_next_line(fd)))
        ft_putstr(line);
}

Hints:
Do not leak file descriptors.
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ft_popen(const char *file, const char *argv[], char type)
{
    if(!file || (type != 'r' && type != 'w'))
    {
        return -1;
    }
    int fd[2];
    pid_t pid;
    if(pipe(fd) == -1)
    {
        return -1;
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
        if(type == 'r')
        {
            close(fd[0]);
            if(dup2(fd[1], STDOUT_FILENO) == -1)
            {
                return -1;
            }
            close(fd[1]);
        }
        if(type == 'w')
        {
            close(fd[1]);
            if(dup2(fd[0], STDIN_FILENO) == -1)
            {
                return -1;
            }
            close(fd[0]);
        }
        if(execvp(file, (char *const*)argv) == -1)
        {
            exit(1);
        }
    }
    if(type == 'r')
    {
        close(fd[1]);
        return(fd[0]);
    }
    if(type == 'w')
    {
        close(fd[0]);
        return(fd[1]);
    }
    
    return -1;
}
int main(void)
{
    int fd = ft_popen("cat", (const char *[]) {"cat", NULL}, 'w');
    const char *message = "hello\n";
    write(fd, message, strlen(message));
    close(fd);
}

