/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:23:44 by jasnguye          #+#    #+#             */
/*   Updated: 2024/06/25 12:27:28 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atol(const char *str)
{
	int	i;
	int	sign;
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