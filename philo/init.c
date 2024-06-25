/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:28:37 by jasnguye          #+#    #+#             */
/*   Updated: 2024/06/25 12:31:00 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void initialize_program(char *argv[], t_program *program)
{
    //initialize data in t_program
    program->dead = 0;
    pthread_mutex_init(&program->dead_lock, NULL);
    pthread_mutex_init(&program->meal_lock, NULL);
    pthread_mutex_init(&program->write_lock, NULL);

    //initialize array for x philos
    program->philo = malloc(ft_atol(argv[1]) * sizeof(t_philo));
    if (program->philo == NULL) 
    {
        perror("Failed to allocate memory for philosophers");
        exit(1);
    }
    //allocate memory for forks
    program->forks = malloc(ft_atol(argv[1]) * sizeof(pthread_mutex_t));
    if(program->forks == NULL)
    {
        perror("Failed to allocate memory for forks!");
        exit(1);
    }
    //initialize each fork 
    int i = 0;
    while(i < ft_atol(argv[1]))
    {
        pthread_mutex_init(&program->forks[i], NULL);
        i++;
    }
}

void initialize_philos(int argc, char *argv[], t_program *program)
{
    int i = 0;
    int nbr_of_philos = ft_atol(argv[1]);
    size_t time_to_die  = ft_atol(argv[2]);
    size_t time_to_eat = ft_atol(argv[3]);
    size_t time_to_sleep = ft_atol(argv[4]);
    size_t start_time = get_current_time_in_ms();
    int nbr_of_times_to_eat;
    if(argc == 6)
    {
       nbr_of_times_to_eat = ft_atol(argv[5]);
    }
    else
    { 
       nbr_of_times_to_eat = -1;
    }

    while(i < nbr_of_philos)
    {
        t_philo *philo = &program->philo[i];
        philo->id = i + 1;
        philo->nbr_of_philos = nbr_of_philos;
        philo->time_to_die = time_to_die;
        philo->time_to_eat = time_to_eat;
        philo->time_to_sleep = time_to_sleep;
        philo->nbr_of_times_to_eat = nbr_of_times_to_eat;
        philo->dead = &program->dead; 
        philo->eating = 0;
        philo->last_meal = 0;
        philo->meals_eaten = 0;
        philo->dead_lock = &program->dead_lock;
        philo->meal_lock = &program->meal_lock;
        philo->write_lock = &program->write_lock;
        philo->l_fork = &program->forks[i];
        philo->r_fork = &program->forks[(i + 1) % nbr_of_philos];
        philo->start_time = start_time;
        i++;
    }
}