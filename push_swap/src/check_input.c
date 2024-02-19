/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:04:17 by jasnguye          #+#    #+#             */
/*   Updated: 2024/02/19 15:34:34 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int input_checker(char *argv[])
{
	int numbers = ft_atoi
	if(check_underflow_and_overflow(argv[1]) && check_for_doubles(argv[1]) && (check_for_character(argv[1])))
	{
		return (1);
	}
}
//what happens if I have a mixture of strings and ints
//what if I have several numbers

int check_underflow_and_overflow(char *argv[])
{
	if (argv[1] < -2147483648 || argv[1] > 2147483647)
	{
		return(0);
	}
	return (1);
}

int check_for_doubles(char *argv[])
{
	int i = 0;
	while(argv[i] != '\0')
	{
		
	}
}
