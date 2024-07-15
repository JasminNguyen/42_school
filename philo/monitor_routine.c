/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:20:55 by jasnguye          #+#    #+#             */
/*   Updated: 2024/07/15 15:50:14 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead(t_philo *philo, size_t time_to_die)
{
	int	dead;

	dead = 0;
	pthread_mutex_lock(philo->meal_lock);
	if (get_current_time_in_ms() - philo->last_meal >= time_to_die 
		&& philo->eating == 0)
	{
		dead = 1;
	}
	pthread_mutex_unlock(philo->meal_lock);
	return (dead);
}

int	set_dead(t_philo *philo) //goes through every philo thread and checks for dead philos, sets the dead flag if necessary
{
	int	i;

	i = 0;
	while (i < philo[0].nbr_of_philos)
	{
		if (check_dead(philo, philo->time_to_die) == 1)
		{
			print_message("died", &philo[i], philo[i].id);
			pthread_mutex_lock(philo[0].dead_lock);
			*philo[i].dead = 1;
			pthread_mutex_unlock(philo[0].dead_lock);
			return (1); 
		}
		i++;
	}
	return (0);
}

int	set_all_meals_eaten(t_philo *philo)
{
	int		i;
	int		meals_done;

	meals_done = 0;
	i = 0;
	while (i < philo[0].nbr_of_philos)    // Check each philosopher's meal count
	{
		pthread_mutex_lock(philo[i].meal_lock); // Lock each philosopher's meal lock
		if (philo[i].nbr_of_times_to_eat != -1 
			&& philo[i].meals_eaten >= philo[i].nbr_of_times_to_eat)
		{
			meals_done += 1;
		}
		pthread_mutex_unlock(philo[i].meal_lock); // Unlock the meal lock
		i++;
	}
	if (meals_done == philo[0].nbr_of_philos)    // If all philosophers have eaten the required number of meals
	{
		pthread_mutex_lock(philo[0].dead_lock); // Lock the dead lock
		*philo[0].dead = 1;
		pthread_mutex_unlock(philo[0].dead_lock); // Unlock the dead lock
		return (1);
	}
	else
		return (0);
}

void	*monitor_routine(void *pointer) //infinite loop (= checks constantly), sets the dead flag to 1 to get the philo routine to stop 
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	while (1)
	{
		if (set_dead(philo) == 1 || set_all_meals_eaten(philo) == 1)
		{
			break ;
		}
		usleep(1000);
	}
	return (pointer);
}
