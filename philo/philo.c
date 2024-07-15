/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:19:15 by jasnguye          #+#    #+#             */
/*   Updated: 2024/07/15 16:33:15 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_program *program)
{
	int			i;
	pthread_t	monitor;

	i = 0;
	if (pthread_create(&monitor, NULL, &monitor_routine, program->philo) != 0) //passing the philo struct here
	{
		perror("Failed to create the monitor thread!");
		exit(1);
	}
    //create threads for each philosopher
	while (i < program->philo[0].nbr_of_philos)
	{
		if (pthread_create(&program->philo[i].philosopher, NULL, &philosopher_routine, &program->philo[i]) != 0) //passing the the individual philo structs here
		{
			perror("Failed to create philosopher thread!");
			exit(1);
		}
		i++;
	}
	if (pthread_join(monitor, NULL) != 0)
	{
		perror("Failed to join monitor thread!");
		exit(1);
	}
}

void	join_philosopher_threads(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->philo[0].nbr_of_philos)
	{
		if (pthread_join(program->philo[i].philosopher, NULL) != 0)
		{
			perror("Failed to join philosopher thread!");
			exit(1);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_program	*program;

	program = malloc(sizeof(t_program));
	if (program == NULL) 
	{
		perror("Failed to allocate memory for program");
		return (1);
	}
	program->philo = malloc(ft_atol(argv[1]) * sizeof(t_philo));
	if (program->philo == NULL) 
	{
		perror("Failed to allocate memory for philo");
		return (1);
	}
	if (check_arguments(argc, argv) == 0) 
	{
		initialize_program(argv, program);
		initialize_philos(argv, program, program->philo);
		create_threads(program);
		join_philosopher_threads(program);
		free_all(program);
	}
	return (0);
}
