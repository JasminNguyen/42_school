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
        //t_philo *philo = &program->philo[i];
        program->philo[i].id = i + 1;
        program->philo[i].nbr_of_philos = nbr_of_philos;
        program->philo[i].time_to_die = time_to_die;
        program->philo[i].time_to_eat = time_to_eat;
        program->philo[i].time_to_sleep = time_to_sleep;
        program->philo[i].nbr_of_times_to_eat = nbr_of_times_to_eat;
        program->philo[i].dead = &program->dead; 
        program->philo[i].eating = 0;
        program->philo[i].last_meal = get_current_time_in_ms();
        program->philo[i].meals_eaten = 0;
        program->philo[i].dead_lock = &program->dead_lock;
        program->philo[i].meal_lock = &program->meal_lock;
        program->philo[i].write_lock = &program->write_lock;
        program->philo[i].l_fork = &program->forks[i];
        program->philo[i].r_fork = &program->forks[(i + 1) % nbr_of_philos];
        program->philo[i].start_time = start_time;
        i++;
    }
}