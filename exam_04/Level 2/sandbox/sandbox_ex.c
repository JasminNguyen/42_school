#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
int g_to;

void handle_signal(int signal)
{
    if(signal == SIGALRM)
    {
        g_to = 1;
    }
}
int	sandbox(void (*f)(void), unsigned int timeout, bool verbose)
{
    pid_t pid;
    int status;
    struct sigaction sa_to;

    pid = fork();
    if(pid == -1)
    {
        return -1;
    }
    if(pid == 0)
    {
        f();
        exit(0);
    }
    sa_to.sa_handler = handle_signal;
    sigaction(SIGALRM, &sa_to, NULL);
    alarm(timeout);
    if(waitpid(pid, &status, 0) == -1)
    {
        while(1)
        {
            if(errno == EINTR)
            {
                if(g_to)
                {
                    if(verbose)
                    {
                        printf("Bad function: timed out after %u seconds\n", timeout);
                    }
                    kill(pid, SIGKILL);
                    if(waitpid(pid, &status, 0) == -1)
                    {
                        return -1;
                    }
                    return 0;
                }
                continue;
            }
            else
            {
                return -1;
            }
        }
    }

    if(WIFSIGNALED(status))
    {
        int signal = WTERMSIG(status);
        if(verbose)
        {
            printf("Bad function: %s\n", strsignal(signal));
        }
        return 0;
    }
    if(WEXITSTATUS(status))
    {
        int exit_code = WEXITSTATUS(status);
        if(exit_code)
        {
            if(verbose)
            {
                printf("Bad function: exited with code %d\n", exit_code); //output
            }
            return 0;
        }
        else
        {
            if (verbose) //is verbose set to true
            {
                printf("Nice function!\n");  //output
            }
			return (1); //return 1 for nice function
        }
    }
    return -1;
}
void good_function()
{
    printf("this is a good function\n");
}
void segfault_function()
{
    int *i = NULL;
    *i = 42;
}
void timeout_function()
{
    sleep(10);
}

int main()
{
    sandbox(good_function, 2, true);
    sandbox(segfault_function, 2, true);
    sandbox(timeout_function, 2, true);

}