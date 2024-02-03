/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:57:07 by jasnguye          #+#    #+#             */
/*   Updated: 2024/01/15 11:40:05 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void ft_putchar_n(char c, int x)
{
	int i = 0;
	while (i < x)
	{
		write(1, &c, 1);
		i++;
	}
}
int main(int argc, char *argv[])
{
	if(argc == 2)
	{
		int i = 0;
		while (argv[1][i] != '\0')
		{
			if(argv[1][i] >= 'a' && argv[1][i] <= 'z')
			{
				ft_putchar_n(argv[1][i], argv[1][i] + 1 - 'a');
			}
			else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			{
				ft_putchar_n(argv[1][i], argv[1][i] + 1 - 'A');
			}
			else 
			{
				write(1, &argv[1][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
}
