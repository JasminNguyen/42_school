/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:38:29 by jasnguye          #+#    #+#             */
/*   Updated: 2024/01/10 14:51:33 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
char *ft_strdup(char *src)
{
	int i = 0;
	int len = ft_strlen(src);
	char *result;

	result = (char*)malloc(sizeof(char) * len + 1);
	if (!result)
	{
		return(NULL);
	}
	while(src[i] != '\0')
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	return(result);
}
/*
int main(void)
{
	char *sourceString = "hello";
	printf("%s\n", ft_strdup(sourceString));
}*/
