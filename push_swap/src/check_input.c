/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:04:17 by jasnguye          #+#    #+#             */
/*   Updated: 2024/02/23 16:51:14 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/* 
int input_checker(char *argv[])
{
	if (check_underflow_and_overflow(argv) && check_for_doubles(argv) && (check_for_character(argv)))
	{
		return (1);
	}
}
//what if I have several numbers

int check_underflow_and_overflow(char *argv[])
{
	int i = 0;
	while(argv[i])
	{	
		long nbr = ft_atol(argv[i]);
		if (nbr < -2147483648 || nbr > 2147483647)
		{
			return(0);
		}
		i++;
	}
	return (1);
}

int check_for_doubles(char *argv[])
{
	int i = 0;
	
	while(argv[i])
	{	
		long nbr = ft_atol(argv[i]);
		if(argv[i], argv[i])
		i++;
	}
}
 */

int	check_valid_argument(char *nbr)
{
	if (!(*nbr == '+' || *nbr == '-' || (*nbr >= '0' && *nbr <= '9')))
	{
		return (1);
	}
	if ((*nbr == '+' || *nbr == '-') && !(nbr[1] >= '0' && nbr[1] <= '9'))
	{
		return (1);
	}
	while (*++nbr)
	{
		if (!(*nbr >= '0' && *nbr <= '9'))
		{
			return (1);
		}
	}
	return (0);
}


int	check_doubles(t_list *stack_a, int nbr)
{
	if (!stack_a)
	{
		return (0);
	}
	while (stack_a)
	{
		if (stack_a->content == nbr)
		{
			return (1);
		}
		stack_a = stack_a->next;
	}
	return (0);
}


