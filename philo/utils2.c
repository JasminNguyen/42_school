/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:59:34 by jasnguye          #+#    #+#             */
/*   Updated: 2024/07/15 15:31:40 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	if (str[i] == '-' || str[i] == '+')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

size_t	get_current_time_in_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
	{
		perror("Couldn't get time\n");
	}
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time_in_ms();
	while ((get_current_time_in_ms() - start) < milliseconds)
	{
		usleep(100);
	}
	return (0);
}

void	print_message(char *message_to_print, t_philo *philo, int philo_id)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_current_time_in_ms() - philo->start_time;
	if (!is_dead(philo))
	{
		printf("%zu %d %s\n", time, philo_id, message_to_print); 
	}
	pthread_mutex_unlock(philo->write_lock);
}

void	free_all(t_program *program)
{
	free (program->philo);
	free (program->forks);
	free (program);
}
