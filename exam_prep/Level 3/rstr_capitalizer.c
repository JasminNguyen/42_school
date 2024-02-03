/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:14:09 by jasnguye          #+#    #+#             */
/*   Updated: 2024/01/15 16:01:48 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i] != '\0')
	{
		i++;
	}
	return (i);
}
void ft_transform_char(char *str, char c, int index)
{
	if ((index == (ft_strlen(str) - 1)) || ((str[index + 1] == ' ' || str[index + 1] == '\t') && (str[index] >= 'a' && str[index] <= 'z')))
	{

		c = c - 32;
	}
	write(1, &c, 1);
}
int main(int argc, char *argv[])
{
	if(argc > 1)
	{
		int i = 0;
		int j = 1;
		while(j < argc)
		{	
			i = 0;
			while(argv[j][i] != '\0')
			{	
				
				if(argv[j][i] >= 'A' && argv[j][i] <= 'Z')
				{
					argv[j][i] = argv[j][i] + 32;
				}
				ft_transform_char(argv[j], argv[j][i], i);
				i++;
			}
			j++;
			write (1, "\n", 1);
		}

	}
	else 
	write(1, "\n", 2);
}
