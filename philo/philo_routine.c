/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:25:27 by jasnguye          #+#    #+#             */
/*   Updated: 2024/06/26 18:26:24 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_dead(t_philo *philo)
{
    pthread_mutex_lock(philo->dead_lock);
    int dead_value = *(philo->dead); //dereferce to get the value
    pthread_mutex_unlock(philo->dead_lock);
    return(dead_value); 
}

void sleep_and_think(t_philo *philo)
{
    print_message("is sleeping", philo, philo->id);
    usleep(philo->time_to_sleep * 1000);
    print_message("is thinking", philo, philo->id);
}

void eat(t_philo *philo)
{
    if(philo->id % 2 == 0) // even philos take first right fork, then left
    {
        pthread_mutex_lock(philo->r_fork);
        print_message("has taken a fork", philo, philo->id);
      /*   if(philo->nbr_of_philos == 1)
        {
            //special case not needed here, right?
        } */
        pthread_mutex_lock(philo->l_fork);
        print_message("has taken a fork", philo, philo->id);
    }
    else //odd philos take first left fork, then right
    {
        pthread_mutex_lock(philo->l_fork);
        print_message("has taken a fork", philo, philo->id);
        if(philo->nbr_of_philos == 1) //special case with one philo
        {
            usleep(philo->time_to_die * 1000);
            pthread_mutex_unlock(philo->l_fork);
            return; //makes sure there are no further actions, exits the function early to prevent further execution of code
        }
        pthread_mutex_lock(philo->r_fork);
        print_message("has taken a fork", philo, philo->id);
    }
    //print eating action
    philo->eating = 1;
    print_message("is eating", philo, philo->id);

    //safely update last meal and nbr of meals eaten
    pthread_mutex_lock(philo->meal_lock);
    philo->meals_eaten++;
    philo->last_meal = get_current_time_in_ms();
    pthread_mutex_unlock(philo->meal_lock);

    //actually simulate eating
    usleep(philo->time_to_eat * 1000); //turn milliseconds into microseconds
    //finished eating
    philo->eating = 0;

    //unlock forks
    pthread_mutex_unlock(philo->r_fork);
    pthread_mutex_unlock(philo->l_fork);
}

void *philosopher_routine(void *pointer)
{
    t_philo *philo = (t_philo *)pointer;
    if(philo->id % 2 == 0)
    {
        
        usleep(1000);//custom function needed???(1)
    }
    while(is_dead(philo) != 1  && (philo->nbr_of_times_to_eat == -1 || philo->meals_eaten < philo->nbr_of_times_to_eat)) ///
    {
        eat(philo);
        sleep_and_think(philo);
    }
    return(pointer);
}