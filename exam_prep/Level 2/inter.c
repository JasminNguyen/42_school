/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:05:25 by jasnguye          #+#    #+#             */
/*   Updated: 2024/01/22 13:50:49 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*prints the hidden string in another string*/
int inter(char *str, char c, int len)
{
	int i = 0;
	while (str[i] != '\0' && (i < len || len == -1))
	{
		if (str[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int main(int argc, char *argv[])
{
	int i;

	if (argc == 3)
	{
		i = 0;
		while(argv[1][i] != '\0')
		{
			if(!inter(argv[1], argv[1][i], i) && inter(argv[2], argv[1][i], -1))
			{
				write(1, &argv[1][i], 1);
			}
			i++;
		}
	}
	write (1, "\n", 1);
}
