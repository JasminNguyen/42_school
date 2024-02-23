/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:06:48 by jasnguye          #+#    #+#             */
/*   Updated: 2024/02/23 13:06:57 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int i = 0;
	while(str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}
int	main(int argc, char *argv[])
{
	if(argc == 3)
	{
		int i = 0;
		int j = 0;

		while(argv[2][j] != '\0')
		{
			if(argv[2][j] == argv[1][i])
			{
				i++;
			}
			j++;
		}
		if(argv[1][i] == '\0')
		{
			ft_putstr(&argv[1][0]);
		}
	}
	write(1, "\n", 1);
}
