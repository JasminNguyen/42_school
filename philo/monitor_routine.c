/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:20:55 by jasnguye          #+#    #+#             */
/*   Updated: 2024/06/25 15:33:18 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_dead(t_philo *philo, size_t time_to_die)
{
    int dead = 0;
    pthread_mutex_lock(philo->meal_lock);
    if(get_current_time_in_ms - philo->last_meal >= philo->time_to_die && philo->eating == 0)
    {
        dead = 1;
    }
    pthread_mutex_unlock(philo->meal_lock);
    return(dead);
}
int set_dead(t_philo *philo) //goes through every philo thread and checks for dead philos, sets the dead flag if necessary
{
    int i = 0;
    while(i < philo[0].nbr_of_philos)
    {
        if(check_dead(philo, philo->time_to_die) == 1)
        {
            //my version here
            print_message("died", &philo[i], philo[i].id);
            pthread_mutex_lock(philo[i].dead_lock);
            *philo->dead = 1;
            pthread_mutex_unlock(philo[i].dead_lock);
            return(1); 
        }
        i++;
    }
    return(0);
}



void *monitor_routine(void *pointer) //infinite loop (= checks constantly), sets the dead flag to 1 to get the philo routine to stop 
{
    t_philo *philo = (t_philo *)pointer;
    while(1)
    {
        if(set_dead(philo) == 1)
        {
            break;
        }
    }
    return(pointer);
}