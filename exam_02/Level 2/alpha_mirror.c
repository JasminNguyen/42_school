/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:27:00 by jasnguye          #+#    #+#             */
/*   Updated: 2024/01/09 10:36:39 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int main(int argc, char *argv[])
{
	int i = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			if(argv[1][i] >= 'a' && argv[1][i] <= 'z')
			{
				argv[1][i] = 122 - argv[1][i] + 97;
			}
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			{
				argv[1][i] = 90 - argv[1][i] + 65;
			}
			write(1, &argv[1][i], 1);
			i++;

		}
	}
	write(1, "\n", 1);
}
