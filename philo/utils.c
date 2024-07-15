/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:23:44 by jasnguye          #+#    #+#             */
/*   Updated: 2024/07/15 15:27:40 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_numerical(char *argument)
{
	int	i;

	i = 0;
	while (argument[i] != '\0')
	{
		if (!(argument[i] >= '0' && argument[i] <= '9'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_greater_zero(char *argument)
{
	int	number;

	number = ft_atol(argument);
	if (!(number > 0))
	{
		printf("Error: Input needs to be greater than zero!\n");
		return (-1);
	}
	return (0);
}

int	check_input(char *argument)
{
	if (is_numerical(argument) != 1)
	{
		printf("Error: Invalid input!\n");
		return (-1);
	}
	return (0);
}

int	error_check(int argc, char *argv[])
{
	int	j;
	int	i;

	j = 1;
	i = 1;
	if (!(ft_atol(argv[1]) >= 1 && ft_atol(argv[1]) <= 200))
	{
		printf("Error: Invalid number of philosophers!\n");
		return (-1);
	}
	while (i < argc)
	{
		if (check_input(argv[i]) != 0)
			return (-1);
		if (j != argc - 1)
		{
			if (check_greater_zero(argv[j]) != 0)
				return (-1);
		}
		i++;
		j++;
	}
	return (0);
}

int	check_arguments(int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
	{
		printf("Error: Invalid number of arguments!\n");
		return (-1);
	}
	else 
	{
		if (error_check(argc, argv) == -1)
		{
			return (-1);
		}
	}
	return (0);
}
