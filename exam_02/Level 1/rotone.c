/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:18:40 by jasnguye          #+#    #+#             */
/*   Updated: 2024/01/06 15:38:58 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char *argv[])
{
	int i = 0;

	if (argc > 1)
	{
		while(argv[1][i] != '\0')
		{
			if(argv[1][i] >= 'a' && argv[1][i] <= 'y')
			{
				argv[1][i] = argv[1][i] + 1;
			}
			else if(argv[1][i] == 'z')
			{
				argv[1][i] = 'a';
			}
			else if(argv[1][i] >= 'A' && argv[1][i] <= 'Y')
			{
				argv[1][i] = argv[1][i] + 1;
			}
			else if(argv[1][i] == 'Z')
			{
				argv[1][i] = 'A';
			}
			write(1, &argv[1][i], 1);
			i++;
		}

	}
	write(1, "\n", 1);
}
