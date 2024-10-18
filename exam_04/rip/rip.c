/* Expected files: *.c *.h
Allowed functions: puts, write

Write a program that will take as argument a string containing only parenthesis.
If parenthesis are unbalanced (for example "())") your program shall remove the minimum number of parenthesis for the expression to be balanced.
By removing we mean replacing by spaces.
You will print all the solutions (can be more than one).
The order of the solutions is not important.
For example this should work:
(For readability reasons the '_' means space and the spaces are for readability only.)
$> ./rip '( ( )' | cat -e
_ ( ) $
( _ ) $
$> ./rip '( ( ( ) ( ) ( ) ) ( ) )' | cat -e
( ( ( ) ( ) ( ) ) ( ) ) $
$> ./rip '( ) ( ) ) ( )' | cat -e
( ) ( ) _ ( ) $
( ) ( _ ) ( ) $
( _ ( ) ) ( ) $
$> ./rip '( ( ) ( ( ) (' | cat -e
( ( ) _ _ ) _ $
( _ ) ( _ ) _ $
( _ ) _ ( ) _ $
_ ( ) ( _ ) _ $
_ ( ) _ ( ) _ $ */


#include <stdio.h> 

int ft_strlen(char *string)
{
	int i = 0;
	while(string[i] != '\0')
	{
		i++;
	}
	return(i);
}


void remove_function(char *string, char *result_string, int left, int right, int to_remove)
{
	int i = 0;
	int j = 0;
	
	if (left == right)
	{
		return;
	}
	if(left > right)
	{
	
		while(string[i] != '\0')
		{
			if(string[i] == '(' && j < to_remove)
			{
				result_string[i] = '_';
				j++;
			}
			else
			{
				result_string[i] = string[i];
			}
			i++;
		}
	}
	else 
	{
		while(string[i] != '\0')
		{
			if(string[i] == ')' && j < to_remove)
			{
				result_string[i] = '_';
				j++;
			}
			else
			{
				result_string[i] = string[i];
			}
			i++;
		}
	}
			printf("result string is: %s\n", result_string);
	
}

/*
the system automatically allocates memory for argv[1] which I don't have to free, but for any other string that I create I need to either allocate memory dynamically or define the size otherwise I don't have a valid memory space for it and it will segfault*/
int main(int argc, char *argv[])
{
	(void)argc;
	char *string = argv[1];
	char result_string[100];
	int len = ft_strlen(string);
	printf("len is: %d\n", len);
	
	int i = 0;
	int left = 0;
	int right = 0;
	int to_remove = 0;
	while(string[i] != '\0')
	{
		if(string[i] == '(')
		{
			left++;
		}
		else if (string[i] == ')')
		{
			right++;
		}
		i++;
	}
	if(left > right)
	{
		to_remove = left - right;
	}
	else
	{
		to_remove = right - left;
	}
	printf("left is: %d\n", left);
	printf("right is: %d\n", right);
	printf("to_remove is: %d\n", to_remove);
	
	remove_function(string, result_string, left, right, to_remove);
	
}
