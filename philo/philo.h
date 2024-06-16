/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:57:17 by jasnguye          #+#    #+#             */
/*   Updated: 2024/06/16 16:32:25 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>

typedef struct s_philo{
    pthread_t philosopher;
    int         id;
    int         eating;
    int         meals_eaten;
    int         *dead;
    int         nbr_of_times_to_eat;
    int         nbr_of_philos;
    size_t      start_time;
    size_t      last_meal;
    size_t      time_to_eat;
    size_t      time_to_die;
    size_t      time_to_sleep;
    
    
    pthread_mutex_t *r_fork;
    pthread_mutex_t *l_fork;
    pthread_mutex_t *dead_lock;
    pthread_mutex_t *eat_lock;
    pthread_mutex_t *write_lock;
}   t_philo;

typedef struct s_program{
    t_philo *philo;
    int     dead;
    pthread_mutex_t dead_lock;
    pthread_mutex_t eat_lock;
    pthread_mutex_t write_lock;
}   t_program;


long ft_atol(const char *str);