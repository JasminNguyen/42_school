/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:57:39 by jasnguye          #+#    #+#             */
/*   Updated: 2024/01/22 16:08:54 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


int max(int *tab, unsigned int len)
{
	unsigned int i = 0;
	int result = tab[i];
	while (i < len)
	{
		if(result < tab[i])
		{
			result = tab[i];
		}
		i++;
	}
	return (result);
}/*
int main(void)
{
	int tab[] = {1, 2, 3, 4};
	unsigned int len = 4;
	printf("%d\n", max(tab, len));
}*/
