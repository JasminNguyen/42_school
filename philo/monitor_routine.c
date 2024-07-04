/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:20:55 by jasnguye          #+#    #+#             */
/*   Updated: 2024/06/26 15:07:00 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_dead(t_philo *philo, size_t time_to_die)
{
    int dead = 0;
    pthread_mutex_lock(philo->meal_lock);

    if(get_current_time_in_ms() - philo->last_meal >= time_to_die && philo->eating == 0)
    {
        dead = 1;
    }
    pthread_mutex_unlock(philo->meal_lock);
    return(dead);
}

int set_dead(t_philo *philo) //goes through every philo thread and checks for dead philos, sets the dead flag if necessary
{
    int i = 0;
    //printf("error: philo[0].nbr_of_philos %d\n", philo[0].nbr_of_philos);
    while(i < philo[0].nbr_of_philos)
    {
        if(check_dead(philo, philo->time_to_die) == 1)
        {
            //my version here
            print_message("died", &philo[i], philo[i].id);
            pthread_mutex_lock(philo->dead_lock);//didn't lock and unlock individually here...
            *philo->dead = 1;
            pthread_mutex_unlock(philo->dead_lock);//
            return(1); 
        }
        i++;
    }
    return(0);
}

int set_all_meals_eaten(t_philo *philo)
{
    int i = 0;
    int meals_done = 0;
    while(i < philo[0].nbr_of_philos)
    {    
        pthread_mutex_lock(philo->meal_lock);//didn't lock and unlock individually here...
        if(philo->nbr_of_times_to_eat <= philo[i].meals_eaten)
        {
            meals_done += 1;
        }
        pthread_mutex_unlock(philo->meal_lock);//
        i++;
    }
    if(meals_done == philo->nbr_of_philos)
    {
        pthread_mutex_lock(philo[0].dead_lock);
        *philo[0].dead = 1;
        pthread_mutex_unlock(philo[0].dead_lock);
        return (1);
    }
    else
    {
        return(0);
    }
}


void *monitor_routine(void *pointer) //infinite loop (= checks constantly), sets the dead flag to 1 to get the philo routine to stop 
{
    t_program *program = (t_program *)pointer;
    while(1)
    {
        if(set_dead(program->philo) == 1 || set_all_meals_eaten(program->philo) == 1) //if I leave this in then it segfaults
        {
            break;
        }
    }
    return(pointer);
}