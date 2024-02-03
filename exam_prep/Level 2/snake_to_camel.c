/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:15:56 by jasnguye          #+#    #+#             */
/*   Updated: 2024/01/16 12:14:21 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int count_underscore(char *str)
{
	int i = 0;
	int underscores = 0;
	while(str[i] != '\0')
	{
		if(str[i] == '_')
		{
			underscores++;
		}
		i++;
	}
	return(underscores);
	
}
void snake_to_camel(char *str)
{
	int len = ft_strlen(str);
	int underscores = count_underscore(str);
	char *result;
	int i = 0;
	int j = 0;

	result = (char*)malloc(sizeof(char) *(len - underscores + 1));
	while(i < (len - underscores))
	{
		if(str[j] == '_')
		{
			j++;
			str[j] = str[j] - 32;
		}
		result[i] = str[j];
	       	i++;	
		j++;
	}
	result[i] = '\0';

	i = 0;
	while (result[i] != '\0')
	{
		write(1, &result[i], 1);
		i++;
	}
}
int main(int argc, char *argv[])
{
	if(argc == 2)
	{
		snake_to_camel(argv[1]);
	}
	write(1, "\n", 1);
}
