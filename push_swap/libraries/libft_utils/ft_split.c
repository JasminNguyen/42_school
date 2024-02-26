/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:55:55 by jasnguye          #+#    #+#             */
/*   Updated: 2024/02/26 14:40:26 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/* static int	count_words(const char *s, char c)
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

static char	*fill_word(const char *s, int start, int end)
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

char	**ft_split(const char *s, char c)
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
 int main(void)
{
	const char *string = "My name is Jasmin hello";
	char c = ' ';
	char **array = ft_split(string, c);
	int i = 0;
	while (i < count_words(string, c))
	{
		printf("array[%d]: %s\n", i, array[i]);
		i++;
	}
	free(array);
} */ 

static void	init_va(size_t *i, int *j, int *x)
{
	*i = 0;
	*j = 0;
	*x = -1;
}
static void	*f_fr(char **strs, int count)
{
	int	i;
	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}
static char	*fill_word(const char *str, int start, int end)
{
	char	*word;
	int		i;
	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = 0;
	return (word);
}
static int	word_count(const char *str, char c)
{
	int	count;
	int	x;
	count = 0;
	x = 0;
	while (*str)
	{
		if (*str != c && x == 0)
		{
			x = 1;
			count++;
		}
		else if (*str == c)
			x = 0;
		str++;
	}
	return (count);
}
char	**ft_split(char const *s, char c)
{
	char	**n;
	size_t	i;
	int		j;
	int		x;
	init_va(&i, &j, &x);
	n = ft_calloc((word_count(s, c) + 1), sizeof(char *));
	if (!n)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && x < 0)
			x = i;
		else if ((s[i] == c || i == ft_strlen(s)) && x >= 0)
		{
			n[j] = fill_word(s, x, i);
			if (!(n[j]))
				return (f_fr(n, j));
			x = -1;
			j++;
		}
		i++;
	}
	return (n);
}
