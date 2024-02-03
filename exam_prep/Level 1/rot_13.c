/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:04:26 by jasnguye          #+#    #+#             */
/*   Updated: 2024/01/06 15:16:11 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}
int main(int argc, char *argv[])
{
	int i = 0;

	if (argc >= 1)
	{
		ft_putchar('\n');
	}
	if (argc > 1)
	{
		while(argv[1][i] != '\0')
		{
			if(argv[1][i] >= 'a' && argv[1][i] <= 'm')
			{
				argv[1][i] = argv[1][i] + 13;
			}
			else if(argv[1][i] >= 'n' && argv[1][i] <= 'z')
			{
				argv[1][i] = argv[1][i] - 13;
			}
			else if(argv[1][i] >= 'A' && argv[1][i] <= 'M')
			{
				argv[1][i] = argv[1][i] + 13;
			}
			else if(argv[1][i] >= 'N' && argv[1][i] <= 'Z')
			{
				argv[1][i] = argv[1][i] - 13;
			}
			ft_putchar(argv[1][i]);
			i++;
		}
	}

}


