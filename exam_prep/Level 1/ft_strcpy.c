/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:45:06 by jasnguye          #+#    #+#             */
/*   Updated: 2024/01/13 12:57:46 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
char *ft_strcpy(char *s1, char *s2)
{
	int i = 0;
	
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s2[i] = '\0';
	return (s1);
}
/*
int main(void)
{
	char *sourceString = "Hello";
	char destinationString[100];
	ft_strcpy(destinationString, sourceString);
	printf("%s\n", destinationString);
}*/
