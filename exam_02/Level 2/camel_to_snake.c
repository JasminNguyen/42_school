/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:46:48 by jasnguye          #+#    #+#             */
/*   Updated: 2024/01/17 11:38:41 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int ft_strlen(char *str)
{
	int i = 0;
	while(str[i] != '\0')
	{
		i++;
	}
	return(i);
}
int count_uppercase(char *str)
{
	int i = 0;
	int count = 0;
	while(str[i] != '\0')
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
		{
			count++;
		}
		i++;
	}
	return(count);
}
char *make_lowercase(char *str)
{
	int i = 0;
	while(str[i] != '\0')
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}
void print_result(char *str)
{
	int i = 0;
	while(str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}
void camel_to_snake(char *str)
{
	int len = ft_strlen(str);
	int uppercase = count_uppercase(str);
	char *result;
	int i = 0;
	int j = 0;

	result = (char*)malloc(sizeof(char) * (len + uppercase + 1));
	
	while(i < (len + uppercase))
	{
		if(str[j] >= 'A' && str[j] <= 'Z')
		{
			result[i] = '_'; // put an underscore whenever we encounter an uppercase letter in the original string
			i++; // jump one further in the result string
		}
		result[i] = str[j];
		i++;
		j++;
	}
	result[i] = '\0';
	make_lowercase(result);
	print_result(result);
}
int main(int argc, char *argv[])
{
	if(argc == 2)
	{
		camel_to_snake(argv[1]);
	}
	write(1, "\n", 1);

}
