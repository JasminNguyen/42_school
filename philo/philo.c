/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:19:15 by jasnguye          #+#    #+#             */
/*   Updated: 2024/06/26 18:28:12 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void create_threads(t_program *program)
{
    int i = 0;
    pthread_t monitor;
    
    //create threads for each philosopher
    while(i < program->philo[0].nbr_of_philos)
    {
        if(pthread_create(&program->philo[i].philosopher, NULL, &philosopher_routine, &program->philo[i]) != 0)
        {
            perror("Failed to create philosopher thread!");
            exit(1);
        }
        i++;
    }
    //printf("Philos successfully created\n");
    //create the monitor thread
    if(pthread_create(&monitor, NULL, &monitor_routine, program) != 0) //passing different args here now
    {
        perror("Failed to create the monitor thread!");
        exit(1);
    }
    if(pthread_join(monitor, NULL) != 0)
    {
        perror("Failed to join monitor thread!");
        exit(1);
    }
}

void join_philosopher_threads(t_program *program)
{
    int i = 0;
    while(i < program->philo[0].nbr_of_philos)
    {
        if(pthread_join(program->philo[i].philosopher, NULL) != 0)
        {
            perror("Failed to join philosopher thread!");
            exit(1);
        }
        i++;
    }
}

int main(int argc, char *argv[])
{
    t_program *program = malloc(sizeof(t_program));
    if (program == NULL) 
    {
        perror("Failed to allocate memory for program");
        return 1;
    }
    if (error_check(argc, argv) == 0) 
    {
        initialize_program(argv, program);
        initialize_philos(argc, argv, program);
         printf("Program initialization completed.\n");
      /*   //let's print the first philo
        t_philo *philo = &program->philo[0];
        printf("Number of philosophers: %d\n", philo->nbr_of_philos);
        printf("Time to die: %zu\n", philo->time_to_die);
        printf("Time to eat: %zu\n", philo->time_to_eat);
        printf("Time to sleep: %zu\n", philo->time_to_sleep);
        printf("Amount of meals: %d\n", philo->nbr_of_times_to_eat); */

        create_threads(program);
        join_philosopher_threads(program);  
    }
    return (0);
}