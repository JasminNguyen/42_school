/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:55:55 by jasnguye          #+#    #+#             */
/*   Updated: 2024/03/11 14:55:38 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	i; 
	int	is_word;

	count = 0;
	i = 0;
	is_word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && is_word == 0)
		{
			is_word = 1;
			count++;
		}
		else if (s[i] == c)
		{
			is_word = 0;
		}
		i++;
	}
	return (count);
}

static char	*fill_word(char *s, int start, int end)
{
	int		len;
	int		i;
	char	*word;

	len = end - start;
	i = 0;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (word == NULL)
	{
		return (NULL);
	}
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**wordarray;

	i = 0;
	j = 0;
	index = -1;
	wordarray = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (wordarray == NULL || s == NULL)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			wordarray[j] = fill_word(s, index, i);
			index = -1;
			j++;
		}
		i++;
	}
	wordarray[j] = NULL;
	return (wordarray);
}
