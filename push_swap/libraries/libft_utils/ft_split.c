/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:55:55 by jasnguye          #+#    #+#             */
/*   Updated: 2024/03/10 13:06:07 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

///////
/* static int	count_words(char *s, char c) //Define a function that returns the substrings count in a string seperated by a delimiter
{
	int		count; //To store the substring count
	bool	inside_word; //A flag to indicate whether we are inside a substring or a delimeter

	count = 0;
	while (*s) //Loop until the end of the string is reached
	{
		inside_word = false; //Set the bool to false to start the loop
		while (*s == c) //While the current character is the delimeter
			++s; //Move to the next character
		while (*s != c && *s) //While the current character is not a deilimeter and the end of the string is not reached, 
		{
			if (!inside_word) //If we are not currently inside the substring
			{
				++count; //Increment the count as we are about to move inside a substring
				inside_word = true; //Set the bool to true, indicating we've found a substring
			}
			++s; //Move to the next character of the string
		}
	}
	return (count);
}

static char	*get_next_word(char *s, char c) //Define a function that returns the new substring found within a string
{
	static int	cursor = 0; //To keep track of the position within the string `s` across multiple function calls, needed to continue processing the string from where we left off in previous calls, essential for tokenizing a string
	char		*next_word; //To store a pointer of the new substring
	int			len; //To store the length of the substring being extracted
	int			i; //Used for indexing characters in the new substring

	len = 0;
	i = 0;
	while (s[cursor] == c) //Skip past any consecutive delimiter characters at the current position in the string
		++cursor;
	while ((s[cursor + len] != c) && s[cursor + len]) //Calculate the length of the substring by counting characters until either a delimiter or the end of the string is encountered
		++len;
	next_word = malloc((size_t)len * sizeof(char) + 1); //Allocate memory for new substring based on its length plus one byte for the null terminator
	if (!next_word) //Check for unsuccessful memory allocation
		return (NULL);
	while ((s[cursor] != c) && s[cursor]) //Loop until a delimeter is encountered and the end of the string is reached
		next_word[i++] = s[cursor++]; //Copy each character from the string to the new substring and increment `i` and `cursor` after each character
	next_word[i] = '\0'; //Properly null terminate the newly created substring
	return (next_word);
}

char **ft_split(char *s, char c) //Define a function that returns the substrings in a string seperated by a delimiter
{
	int		words_count; //Used to keep track of the number of substrings in the string
	char	**result_array; //To store a pointer to pointers, the array of all the substrings
	int		i; //Used to iterate through the array

	i = 0;
	words_count = count_words(s, c);
	if (!words_count) //Check for `0` words
		exit(1);
	result_array = malloc(sizeof(char *) * (size_t)(words_count + 2)); //Allocate memory for the result_array based on the number of words (words_count) plus two additional slots to account for the null terminator at the end of the last string, and to null terminate the entire array
	if (!result_array) //Check for unsuccessful memory allocation
		return (NULL);
	while (words_count-- >= 0) //Iterates through the words to be split all words have been processed
	{
		if (i == 0) //Check if the first character of the input string is the delimiter
		{
			result_array[i] = malloc(sizeof(char)); //Allocate memory for an empty string (a single null terminator)
			if (!result_array[i]) ////Check for unsuccessful memory allocation
				return (NULL);
			result_array[i++][0] = '\0'; //Include in the result array as distinct elements
			continue ;
		}
		result_array[i++] = get_next_word(s, c); //If the first character of the string is not a delimeter, extract the substring and copy it into the result array
	}
	result_array[i] = NULL; //Properly null terminate the array
	return (result_array);
} */
//////
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


/*  int main(void)
{
	char *string = "My name is Jasmin hehe";
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
