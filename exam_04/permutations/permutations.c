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



#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int find_length(char *string)
{
    int i = 0;
    while(string[i] != '\0')
    {
        i++;
    }
    return(i);
}
//using bubble sort
void sort_string(char *string)
{
	
	int len = find_length(string);
	char temp;
	while (len > 0)
	{	
		int i = 0;
		while(i < len - 1)
		{
			if(string[i] > string[i + 1])
			{
				temp = string[i + 1];
				string[i + 1] = string[i];
				string[i] = temp;
			}
			i++;
		}
		len--;
	}
}


//we create a new array that excludes only the char that we already put in the return_string 
char *create_new_array(char *string, int exclude_index)
{
	int len = find_length(string);
    char *new_array = malloc(sizeof(char) * len); 
    if(!new_array)
    {
        puts("memory allocation failed");
	
    }
	int i = 0;
	int j = 0;
	while(i < len)
	{
		if(i != exclude_index)
		{
			new_array[j] = string[i];
			j++;
		}
		i++;
		
	}
	new_array[j] = '\0';
    return(new_array);
}


void traverse_tree(char *return_string, char *string, int return_string_index)
{
    char *new_array;
  
	int len = find_length(string);
    if(find_length(string) == 1)
    {
        return_string[return_string_index] = string[0];
		return_string[return_string_index + 1] = '\0';//// don't forget to null-terminate the string
        puts(return_string);	
        return ;
    }
	int string_index = 0;
    while(string[string_index] != '\0')
    {
        return_string[return_string_index] = string[string_index];
        new_array = create_new_array(string, string_index);
        traverse_tree(return_string, new_array, return_string_index + 1);
       	string_index++;
    
 		free(new_array);
    }
}




int main(int argc, char *argv[])
{
    char *string = argv[1];
    sort_string(string);
	printf("sorted string: %s\n", string);

  
    int len = find_length(string);

    
    char *return_string = malloc(sizeof(char) * len + 1);
    if(!return_string)
    {
        puts("memory allocation failed");
    }

    int return_string_index = 0;
    traverse_tree(return_string, string, return_string_index);

}

