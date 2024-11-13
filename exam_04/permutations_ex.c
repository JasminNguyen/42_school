/*Assignment name: permutations
Expected files: *.c, *.h
Allowed functions: puts, malloc, calloc, realloc, free, write

Write a program that will print all the permutations of a string given as argument.

The solution must be given in alphabetical order. 

We will not try your program with strings containing duplicates (eg: 'abccd').

for example this should work:

./a.out a | cat -e
a$


./a.out ab | cat -e
ab$
ba$

./a.out abc | cat -e
abc$
acb$
bac$
bca$
cab$
cba$
*/

#include <stdio.h>
#include  <stdlib.h>
int ft_strlen(char *string)
{
	int i = 0;
	while(string[i] != '\0')
	{
		i++;
	}
	return (i);
}
void sort_string(char *string)
{
	int size = ft_strlen(string);

	char temp;
	while(size > 0)
	{	
		int i = 0;
		while(i < size - 1)
		{
			if(string[i] > string[i + 1])
			{
				temp = string[i + 1];
				string[i + 1] = string[i];
				string[i] = temp;
			}
			i++;
		}
		size--;
	}
}

char *create_new_string(char *string, int string_index)
{
	char *new_string;
	int len = ft_strlen(string);
	new_string = malloc(sizeof(int) *len); //no +1 needed since we have one less char
	if(!new_string)
	{
		puts("memory allocation failed");
	}
	int i = 0;
	int j = 0;
	while(string[i] != '\0')
	{
		if(i != string_index)
		{
			new_string[j] = string[i];
			j++;
		}
		i++;
	}
	new_string[i] = '\0';
	//printf("new string: %s\n", new_string);
	return(new_string);

}
void build_permutations(char *return_string, char *string, int return_string_index)
{
	
	if(ft_strlen(string) == 1)
	{
		return_string[return_string_index] = string[0];
		return_string[return_string_index + 1] = '\0';
		puts(return_string);

		return;
	}
	int string_index = 0;
	while(string[string_index] != '\0')
	{
		return_string[return_string_index] =  string[string_index];
		char *new_string = create_new_string(string, string_index);
		build_permutations(return_string, new_string, return_string_index + 1);
		string_index++;
		
	}
}
int main(int argc, char *argv[])
{
	char *string = argv[1];
	printf("unsorted string: %s\n", string);
	sort_string(string);
	printf("sorted string: %s\n", string);

	int len = ft_strlen(string);
	char *return_string = malloc(sizeof(char) * len + 1);
	if(!return_string)
	{
		puts("memory allocation failed");
	}

	int return_string_index = 0;
	build_permutations(return_string, string, return_string_index);
}