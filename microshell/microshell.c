/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:53:00 by jasnguye          #+#    #+#             */
/*   Updated: 2024/08/16 18:01:19 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int cd(char *argv[], int i)
{
	int status;
	///bla bla

	return(status);
}

int set_pipe(int pipes_present, int *fd, int which_end)
{
	if(pipes_present && dup2(fd[which_end], which_end) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1)
	{
		//error message
	}
}
int ft_execve(char *argv[], int i, char **envp)
{
	int fd[2];
	int status;
	int pipes_present;
	int pid;

	//check for pipes
	pipes_present = !strcmp(argv[i], "|") && argv[i];
	
	//check for cd
	if(strcmp(argv[i], "cd") == 0 && !pipes_present) //my version
	{
		return(cd(argv, i));
	}

	//create pipes
	if(pipes_present && pipe(fd) == -1)
	{
		//error function
	}

	pid = fork();
	if(pid == 0) //in the child
	{
		argv[i] = NULL; //break the argument string apart
		set_pipe(pipes_present, fd, 1);//child writes
		if(strcmp(argv[i], "cd") == 0)
		{
			return (cd(argv, i));
		}
		if(execve(argv, i, envp) == -1) //execute
		{
			//error message
		}
		waitpid(pid, &status, 0);//waiting for child to finish
		set_pipe(pipes_present, fd, 0); //parent reads
		return(WIFEXITED(status) && WEXITSTATUS(status)); // macros check wheter exited normally and the exit status
	}
	
}
int main(int argc, char *argv[], char **envp) //my version
{
	int i = 1; // to skip the first argument which is the executable
	int status = 0;

	while(argv[i])
	{
		argv += i;
		i = 0;
		while(argv[i] && strcmp(argv[i], "|") != 0 && strcmp(argv[i], ";") != 0) // only increments when there is no pipe or semicolon
		{
			i++;
		}
		if(i != 0) // checks if there is something to be executed
		{
			status = ft_execve(argv, i, envp);
		}
		if(argv[i] != NULL) //increments once to skip over pipes and semicolons, but only if we are not at the end of the argument string
		{
			i++;
		}
	}
	return (status);
}