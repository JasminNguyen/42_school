/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:59:34 by jasnguye          #+#    #+#             */
/*   Updated: 2024/06/26 15:06:01 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t get_current_time_in_ms() 
{
    struct timeval tv;
    if(gettimeofday(&tv, NULL) == -1)
    {
        perror("Couldn't get time\n");
    }
    return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

int ft_usleep(size_t milliseconds)
{
    size_t start;

    start = get_current_time_in_ms();
    while((get_current_time_in_ms() - start) < milliseconds)
    {
        usleep(100);
    }
    return(0);
}

void print_message(char *message_to_print, t_philo *philo, int philo_id)
{
    size_t time;
    pthread_mutex_lock(philo->write_lock);
    time = get_current_time_in_ms() - philo->start_time;
    if(!is_dead(philo))
    {
       printf("%zu %d %s\n", time, philo_id, message_to_print); 
    }
    pthread_mutex_unlock(philo->write_lock);
    
}