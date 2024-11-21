/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:37:03 by jasnguye          #+#    #+#             */
/*   Updated: 2024/01/13 15:47:12 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/* can output a combination of both strings*/
int check(int c, char *str, int index)
{
	int i = 0;
	while (i < index)
	{
		if (str[i] == c)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int main(int argc, char *argv[])
{
	int i = 0;
	int j = 0;
	int k = 0;

	if (argc == 3)
	{
		while(argv[1][i] != '\0')
		{
			i++;
		}
		while(argv[2][j] != '\0')
		{
			argv[1][i] = argv[2][j];
			i++;
			j++;
		}
		i--;
		while (k <= i)
		{
			if (check(argv[1][k], argv[1], k) == 1)
			{
				write (1, &argv[1][k], 1);
			}
			k++;
		}
	}
	write (1, "\n", 1);
}
