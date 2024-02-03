/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:10:03 by jasnguye          #+#    #+#             */
/*   Updated: 2024/01/22 15:39:39 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i] != '\0')
	{
		i++;
	}
	return (i);
}
int main(int argc, char *argv[])
{
	if(argc == 2)
	{
		int len = ft_strlen(argv[1]);
		while(len > 0)
		{
			write(1, &argv[1][len -1], 1);
			len--;
		}
	}
	write(1, "\n", 1);
}
