/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:19:15 by jasnguye          #+#    #+#             */
/*   Updated: 2024/06/21 17:00:45 by jasnguye         ###   ########.fr       */
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

size_t get_current_time_in_ms() 
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
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
        t_philo *philo = &program->philo[i];
        philo->id = i + 1;
        philo->nbr_of_philos = nbr_of_philos;
        philo->time_to_die = time_to_die;
        philo->time_to_eat = time_to_eat;
        philo->time_to_sleep = time_to_sleep;
        philo->nbr_of_times_to_eat = nbr_of_times_to_eat;
        philo->dead = &program->dead; 
        philo->eating = 0;
        philo->last_meal = 0;
        philo->meals_eaten = 0;
        philo->dead_lock = &program->dead_lock;
        philo->eat_lock = &program->eat_lock;
        philo->write_lock = &program->write_lock;
        philo->l_fork = &program->forks[i];
        philo->r_fork = &program->forks[(i + 1) % nbr_of_philos];
        philo->start_time = start_time;
        i++;
    }
}

void *monitor_routine(void *pointer)
{

}

int is_dead(t_philo *philo)
{
    pthread_mutex_lock(philo->dead_lock);
    int dead_value = *(philo->dead); //dereferce to get the value
    pthread_mutex_unlock(philo->dead_lock);
    return(dead_value); 
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
void sleep_and_think(t_philo *philo)
{
    print_message("is sleeping", philo, philo->id);
    usleep(philo->time_to_sleep);
    print_message("is thinking", philo, philo->id);
}
void *philosopher_routine(void *pointer)
{
    t_philo *philo = (t_philo *)pointer;
    if(philo->id % 2 == 0)
    {
        usleep(1);//custom function needed???
    }
    while(!is_dead(philo) && (philo->nbr_of_times_to_eat == -1 || philo->meals_eaten < philo->nbr_of_times_to_eat))
    {
        eat(philo);
        sleep_and_think(philo);
    }

}

void create_threads(t_program *program)
{
    int i = 0;
    pthread_t monitor;
    //create the monitor thread
    if(pthread_create(&monitor, NULL, &monitor_routine, NULL) != 0)
    {
        perror("Failed to create the monitor thread!");
        exit(1);
    }
    //create threads for each philosopher
    while(i < program->philo[0].nbr_of_philos)
    {
        if(pthread_create(&program->philo[i].philosopher, NULL, &philosopher_routine, NULL) != 0)
        {
            perror("Failed to create philosopher thread!");
            exit(1);
        }
        i++;
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
        
        //let's print the first philo
        t_philo *philo = &program->philo[0];
        printf("Number of philosophers: %d\n", philo->nbr_of_philos);
        printf("Time to die: %zu\n", philo->time_to_die);
        printf("Time to eat: %zu\n", philo->time_to_eat);
        printf("Time to sleep: %zu\n", philo->time_to_sleep);
        printf("Amount of meals: %d\n", philo->nbr_of_times_to_eat);

        create_threads(program);
        join_philosopher_threads(program);
      
        
    }
    

   
    return (0);
}