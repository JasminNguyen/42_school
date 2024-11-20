/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:43:11 by jasnguye          #+#    #+#             */
/*   Updated: 2024/02/01 14:50:24 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int i = 0;
	int j = 0;
	while(s[i] != '\0')
	{	
		j = 0;
		while(reject[j] != '\0')
		{
			if(s[i] == reject[j])
			{
				return(i);
			}
			j++;
		}
		i++;
	}
	return (i);
}
/*
int main(void)
{
	const char *string1 = "abcdefg12345";
	const char *string2 = "123";
	printf("%zu\n", ft_strcspn(string1, string2));
}*/
