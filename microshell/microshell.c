/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:53:00 by jasnguye          #+#    #+#             */
/*   Updated: 2024/08/15 17:34:59 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int execve(char **argv, int i, char **envp)
{
	//check for pipes
	//create pipes
	
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