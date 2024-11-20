/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:53:57 by jasnguye          #+#    #+#             */
/*   Updated: 2024/01/08 10:49:10 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char *argv[])
{
	int i = 0;
	if(argc == 4 && !argv[2][1] && !argv[3][1])
	{
		while(argv[1][i] != '\0')
		{
			if(argv[1][i] == argv[2][0])
			{
				argv[1][i] = argv[3][0];

			}  
		       	write(1, &argv[1][i], 1);
			i++;
		}

	}
	write(1, "\n", 1);

}


