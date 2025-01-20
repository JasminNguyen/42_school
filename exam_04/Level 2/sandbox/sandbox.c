/* TASK:
Assignment name:    sandbox
Expected files:     sandbox.c
Allowed functions:  fork, waitpid, exit, alarm, sigaction, kill, printf, strsignal, errno
--------------------------------------------------------------------------------
Write the following function:

#include <stdbool.h>
int sandbox(void(*f)(void), unsigned int timeout, bool verbose);

This function must test if the function f is a nice function or a bad function,
you will return 1 if it is nice, 0 if f is bad or -1 in case of an error in your
function.

A function is considered bad if it is terminated or stopped by a signal
(segfault, abort...), if it exits with any other exit code than 0 or if it times
out.

If verbose is true, you must write the appropriate message among the following:
"Nice function!\n"
"Bad function: exited with code <exit_code>\n"
"Bad function: <signal_description>\n"
"Bad function: timed out after <timeout> seconds\n"

You must not leak processes (even in zombie state, this will be checked using
wait).

We will test your code with very bad functions.
*/

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>

int	g_to; //global variable to find out if there was a timeout

void	handle_timeout(int sig) //sets g_to to 1 if we get the SIGALARM signal
{
	if (sig == SIGALRM)
		g_to = 1;
}

int	sandbox(void (*f)(void), unsigned int timeout, bool verbose)
{
	int pid;
	int status;
	struct sigaction sa_to; //sigaction timeout struct

	if ((pid = fork()) == -1) //forking
		return (-1);
	if (pid == 0) //executing the f() in the child process and exiting sucessfully with 0
	{
		f();
		exit(0);
	}
	sa_to.sa_handler = handle_timeout; //uses a part of the sa_to struct "sa_handler" and sets it to our handle_timeout function
	sigaction(SIGALRM, &sa_to, NULL); //like a "listener" listening for the SIGALARM signal and connecting it to our function via a pointer to the struct
	alarm(timeout); //actual timer
	if (waitpid(pid, &status, 0) == -1) //while waiting for the child to finish, we encounter an error
	{
		while (1) //infinite loop
		{
			if (errno == EINTR) //errno saves the error code -> is it an interrupted systemcall?
			{
				if (g_to) //is g_to set to 1 (timeout)
				{
					if (verbose) //is verbose set to true
					{
                        printf("Bad function: timed out after %u seconds\n", timeout); //output
                    }	
					kill(pid, SIGKILL); //end this child process
					if (waitpid(pid, &status, 0) == -1) //important to wait for the child to end after we called kill
					{
                        return (-1); //return -1 for error
                    }	
					return (0); //return 0 for bad function
				}
				continue; //continuing to see if g_to will be 1
			}
			else //no interrupted systemcall but error
				return (-1); //return -1 for an error
		}
	}
	if (WIFSIGNALED(status)) //check signals received by child
	{
		int signum = WTERMSIG(status); //gets status 
		if (verbose) //if verbose is set to true
		{
            printf("Bad function: %s\n", strsignal(signum)); //output error with signal
        }	
		return (0); //return 0 for bad function
	}
	if (WIFEXITED(status)) //check exit status given back by child
	{
		int exit_code = WEXITSTATUS(status); //putting it in a variable
		if (exit_code) //if exit code > 0
		{
			if (verbose) //is verbose set to true
            {
                printf("Bad function: exited with code %d\n", exit_code); //output
            }
			return (0); //return 0 for bad function
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
	return (-1); //internal sandbox problem returns -1
}