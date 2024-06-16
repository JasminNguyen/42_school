/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:19:15 by jasnguye          #+#    #+#             */
/*   Updated: 2024/06/16 18:00:36 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_numerical(char *argument)
{
    int i = 0;
    while(argument[i] != '\0')
    {
        if(!(argument[i] >= '0' && argument[i] <= '9'))
        {
            return(0);
        }
        i++;
    }
    return (1);
}
int check_greater_zero(char *argument)
{
    int number = ft_atol(argument);
    if(!(number > 0))
    {
        printf("Error: Input needs to be greater than zero!\n");
        return(-1);
    }
    return(0);
}
int check_input(char *argument)
{
   if(is_numerical(argument) != 1)
   {
        printf("Error: Invalid input!\n");
        return(-1);
   }
   return(0);
}

int error_check(int argc, char *argv[])
{
    if(argc != 5 && argc != 6)
    {
        printf("Error: Invalid number of arguments!\n");
        return (-1);
    }
    else 
    {
        int i = 1;
        int j = 1;
        if(!(ft_atol(argv[1]) >= 1 && ft_atol(argv[1]) <= 200))
        {
            printf("Error: Invalid number of philosophers!\n");
            return(-1);
        }
        while(i < argc)
        {
            if(check_input(argv[i]) != 0)
            {
                return (-1);
            }
            if(j != argc - 1)
            {
                if(check_greater_zero(argv[j]) != 0)
                {
                    return (-1);
                }
            }
            i++;
            j++;
        }
    }
    return(0);
}

void initialize_program(char *argv[], t_program *program)
{
    //initialize data in t_program
    program->dead = 0;
    pthread_mutex_init(&program->dead_lock, NULL);
    pthread_mutex_init(&program->eat_lock, NULL);
    pthread_mutex_init(&program->write_lock, NULL);

    //initialize array for philos
    program->philo = malloc(ft_atol(argv[1]) * sizeof(t_philo));
    if (program->philo == NULL) 
    {
        perror("Failed to allocate memory for philosophers");
        exit(1);
    }
}

void initialize_philos(int argc, char *argv[], t_program *program, t_philo *philo)
{
    //needs adjusting
    philo->nbr_of_philos = ft_atol(argv[1]);
    philo->time_to_die = ft_atol(argv[2]);
    philo->time_to_eat = ft_atol(argv[3]);
    philo->time_to_sleep = ft_atol(argv[4]);

    if(argc == 6)
    {
        philo->nbr_of_times_to_eat = ft_atol(argv[5]);
    }
    else
    { 
        philo->nbr_of_times_to_eat = -1;
    }

}

int main(int argc, char *argv[])
{
    t_program *program = malloc(sizeof(t_program));
    if (program == NULL) {
        perror("Failed to allocate memory for program");
        return 1;
    }
    t_philo *philo;
    if (error_check(argc, argv) == 0) 
    {
         initialize_program(argv, program);
         initialize_philos(argc, argv, program, philo);
        
    }
   
    return (0);
}