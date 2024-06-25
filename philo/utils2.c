/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:59:34 by jasnguye          #+#    #+#             */
/*   Updated: 2024/06/25 15:03:32 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t get_current_time_in_ms() 
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

void print_message(char *message_to_print, t_philo *philo, int philo_id)
{
    size_t time;
    pthread_mutex_lock(philo->write_lock);
    time = get_current_time() - philo->start_time;
    if(!is_dead(philo))
    {
       printf("%zu %d %s\n", time, philo_id, message_to_print); 
    }
    pthread_mutex_unlock(philo->write_lock);
    
}