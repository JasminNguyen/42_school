/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:28:37 by jasnguye          #+#    #+#             */
/*   Updated: 2024/07/15 16:34:16 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initialize_program(char *argv[], t_program *program)
{
	int	i;

	i = 0;
	program->dead = 0;
	pthread_mutex_init(&program->dead_lock, NULL);//initialize data in t_program
	pthread_mutex_init(&program->meal_lock, NULL);
	pthread_mutex_init(&program->write_lock, NULL);
	program->forks = malloc(ft_atol(argv[1]) * sizeof(pthread_mutex_t));
	if (program->forks == NULL)
	{
		perror("Failed to allocate memory for forks!");
		exit(1);
	}
	while (i < ft_atol(argv[1]))
	{
		pthread_mutex_init(&program->forks[i], NULL);
		i++;
	}
}

void	initialize_input(t_philo *philo, char *argv[])
{
	philo->time_to_die = ft_atol(argv[2]);
	philo->time_to_eat = ft_atol(argv[3]);
	philo->time_to_sleep = ft_atol(argv[4]);
	philo->nbr_of_philos = ft_atol(argv[1]);
	if (argv[5])
		philo->nbr_of_times_to_eat = ft_atol(argv[5]);
	else
		philo->nbr_of_times_to_eat = -1;
}

void	initialize_philos(char *argv[], t_program *program, t_philo *philo)
{
	int		i;
	size_t	start_time; 

	i = 0;
	start_time = get_current_time_in_ms();
	while (i < ft_atol(argv[1]))
	{
		program->philo[i].id = i + 1;
		initialize_input(&philo[i], argv);
		program->philo[i].dead = &program->dead; 
		program->philo[i].eating = 0;
		program->philo[i].last_meal = get_current_time_in_ms();
		program->philo[i].meals_eaten = 0;
		program->philo[i].dead_lock = &program->dead_lock;
		program->philo[i].meal_lock = &program->meal_lock;
		program->philo[i].write_lock = &program->write_lock;
		program->philo[i].l_fork = &program->forks[i];
		program->philo[i].r_fork = &program->forks[(i + 1) % ft_atol(argv[1])];
		program->philo[i].start_time = start_time;
		i++;
	}
}
