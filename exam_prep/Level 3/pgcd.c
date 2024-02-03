/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:52:41 by jasnguye          #+#    #+#             */
/*   Updated: 2024/02/01 15:07:33 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if(argc == 3)
	{
		int first_a = atoi(argv[1]);
		int second_a = atoi(argv[2]);
		
		while(first_a != second_a)
		{
			if(first_a > second_a)
			{
				first_a = first_a - second_a;
			}
			else 
			{
				second_a = second_a - first_a;
			}
		}
		printf("%d\n", first_a);
	}
	else
	write(1, "\n", 1);
}
