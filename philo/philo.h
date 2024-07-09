/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:57:17 by jasnguye          #+#    #+#             */
/*   Updated: 2024/06/26 15:07:54 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdlib.h>

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
    pthread_mutex_t *meal_lock;
    pthread_mutex_t *write_lock;
}   t_philo;

typedef struct s_program{
    t_philo *philo; //array of philos
    int     dead;
    pthread_mutex_t dead_lock;
    pthread_mutex_t meal_lock;
    pthread_mutex_t write_lock;
    pthread_mutex_t *forks; //array of forks
}   t_program;

//utils functions
long ft_atol(const char *str);
int is_numerical(char *argument);
int check_greater_zero(char *argument);
int check_input(char *argument);
int error_check(int argc, char *argv[]);

size_t get_current_time_in_ms();
void print_message(char *message_to_print, t_philo *philo, int philo_id);
//int ft_usleep(size_t milliseconds);

//initialization functions 
void initialize_program(char *argv[], t_program *program);
void initialize_philos(int argc, char *argv[], t_program *program);

//monitor_routine functions
void *monitor_routine(void *pointer);
int set_dead(t_philo *philo);
int check_dead(t_philo *philo, size_t time_to_die);

//philo_routine functions
void *philosopher_routine(void *pointer);
void eat(t_philo *philo);
void sleep_and_think(t_philo *philo);
int is_dead(t_philo *philo);

