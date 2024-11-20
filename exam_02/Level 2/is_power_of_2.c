/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:35:50 by jasnguye          #+#    #+#             */
/*   Updated: 2024/01/19 11:52:11 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


int is_power_of_2(unsigned int n)
{
	if (n == 0)
	{
		return(0);
	}
	while (n != 1)
	{
		if (n % 2 != 0)
		{
			return(0);
		}
		n = n / 2;	
	}
	return (1);
}
/*
int main(void)
{
	unsigned int nbr = 17;
	printf("%d\n", is_power_of_2(nbr));
	
}*/
