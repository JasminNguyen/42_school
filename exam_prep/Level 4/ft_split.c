
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
int count_words(char *str)
{
	int i = 0;
	int in_word = 0;
	int count = 0;
	while (str[i] != '\0')
	{
		if(str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			if(in_word == 0)
			{
				in_word = 1;
				count++;
			}
		}
		else
		{
			in_word = 0;
		}
		i++;
	}
	return(count);
}

char	*fill_word(char *str, int start, int end)
{
	int len = end - start;
	int i = 0;
	char *word;
	
	word = (char *)malloc(sizeof(char) * (len + 1));
	if(!word)
	{
		return(NULL);
	}
	while (start < end) //start < end
	{
		word[i] = str[start]; //str[start]
		start++;
		i++;
	}
	word[i] = '\0';
	return(word);
}


char    **ft_split(char *str)
{
	int words = count_words(str);
	int i = 0;
	int j = 0;
	int index = -1;
	char **wordarray = (char **)malloc(sizeof(char*) * (words + 1));
	if(!wordarray || !str)
	{
		return (NULL);
	}
	while(i <= ft_strlen(str)) // <=
	{
		if(str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && index < 0)
		{
			index = i;
		}
		else if(((index >= 0) && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')) || (i == ft_strlen(str)))
		{
			wordarray[j] = fill_word(str, index, i); //achtung auf reihenfolge
			index = -1;
			j++;
		}
		i++;
	}
	wordarray[j] = NULL;
	return(wordarray);

}

/*  int main(void)
{
	int i = 0;
	char string[] = "Hello my name is Jasmin";
	char **wordarray = ft_split(string);

	while(wordarray[i] != NULL)
	{
		printf("Array %d: %s", i, wordarray[i]);
		printf("\n");
		i++;
	}
}  */
