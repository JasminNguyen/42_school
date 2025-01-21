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


#include <stdio.h>
#include <unistd.h>


int ft_popen(const char *file, const char *argv[], char type)
{
    if(type != 'r' && type != 'w')
    {
        return -1;
    }
    //create always pipes first
    int fd[2];
    if(pipe(fd) == -1)
    {
        perror("pipe creation");
        return -1;
    }

    //forking
    __pid_t pid = fork();
    if(pid == -1)
    {
        perror("forking");
        close(fd[0]);
        close(fd[1]);
        return -1;
    }
   
    if(pid == 0) //child -bypassing the terminal by redirecting input/output and executing the command
    {
        if(type == 'r') //parent reads, child writes
        {
            close(fd[0]); //close parents read fd
            if(dup2(fd[1], STDOUT_FILENO) == -1)
            {
                perror("dup2 outfile");
                exit(1);
            }
            close(fd[1]); //close redirected write fd
        }
        if(type == 'w')//parent writes, child reads
        {
            close(fd[1]); //close parents write fd
            if(dup2(fd[0], STDIN_FILENO) == -1)
            {
                perror("dup2 infile");
                exit(1);
            }
            close(fd[0]); //close redirected read fd
        }
        //execute
        if(execvp(file, argv) == -1)
        {
            perror("execvp");
            exit(1);
        }
    }
    else //parent
    {
        if(type == 'r')
        { 
            close (fd[1]);
           return fd[0];
        }
        if(type == 'w')
        {
            close(fd[0]);
            return fd[1];
        }
    }
    return -1; //no fd returned
}

int main()
{
    int fd = ft_popen("ls", (const char *[]) {"ls", NULL}, 'r');
    char *line;
    while ((line = get_next_line(fd)))
        ft_putstr(line);
}