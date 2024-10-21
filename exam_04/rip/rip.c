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
#include <string.h>


/* my first approach: 
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
	
} */



int ft_strlen(char *string)
{
	int i = 0;
	while(string[i] != '\0')
	{
		i++;
	}
	return(i);
}
/* For the string "((()))", as we traverse the string, balance will go up initially due to the opening parentheses (, 
but it will later return to zero as the closing parentheses ) are processed.
Thus, a positive balance is not inherently invalid during traversal, but it is necessary to ensure that by the 
end of the string, the balance is exactly zero. This means the number of opening and closing parentheses matches. */
int valid_solution(char *str)
{
	int i = 0;
	int balance = 0;
	while(str[i] != '\0')
	{
		if(str[i] == '(')
		{
			balance++;
		}
		else if(str[i] == ')')
		{
			balance--;
		}
		 if (balance < 0)
        {
            return -1;  // Invalid solution
        }
		i++;
	}
	if(balance == 0)
	{
		return (1);
	}
	else
	{
		return(-1);
	}
}

void remove_function(char *string, char *result_string, int i, int to_remove, int removed, int left, int right)
{
    // Base case: if we have traversed the entire string or removed enough parentheses
    if (string[i] == '\0')
    {
        if (removed == to_remove && valid_solution(result_string) == 1)
        {
            result_string[i] = '\0'; // Null-terminate the result string
            printf("result string is:: %s\n", result_string); // Print one possible solution
			puts(result_string);
        }
        return;
    }
	
	//exclude
  	if(string[i] == '(' && left > right && to_remove > removed)
	{
		result_string[i] = '_';
		remove_function(string, result_string, i + 1, to_remove, removed +1, left -1, right);
	}
	else if(string[i] == ')' && right > left && to_remove > removed)
	{
		result_string[i] = '_';
		remove_function(string, result_string, i + 1, to_remove, removed +1, left, right -1);
	}

	//include 
	result_string[i] = string[i];
	if(string[i] == '(')
	{
		remove_function(string, result_string, i + 1, to_remove, removed, left, right);
	}
	else if(string[i] == ')')
	{
		remove_function(string, result_string, i + 1, to_remove, removed, left, right);
	}
	else 
	{
		remove_function(string, result_string, i + 1, to_remove, removed, left, right);
	}
		
		
		
}



/*
the system automatically allocates memory for argv[1] which I don't have to free,
but for any other string that I create I need to either allocate memory dynamically 
or define the size otherwise I don't have a valid memory space for it and it will segfault*/
int main(int argc, char *argv[])
{
	(void)argc;
	char *string = argv[1];
	char result_string[100];
	int len = ft_strlen(string);
	printf("len is: %d\n", len);
	
	int i = 0;
	int invalid_left = 0;
	int invalid_right = 0;
	int to_remove = 0;
	int balance = 0;

	while(string[i] != '\0')
	{
		if(string[i] == '(')
		{
			balance++;
		}
		else if(string[i] == ')')
		{
			balance--;
		}
		if(balance < 0)
		{
			invalid_right++;
		}
		else if(balance > 0)
		{
			invalid_left++;
		}
		i++;
	}
	printf("invalid lefts: %d\n", invalid_left);
	printf("invalid rights: %d\n", invalid_right);
	printf("to_remove is: %d\n", to_remove);

	//check for same amount of left and right parenthesis and no open parethesis (correct nesting)
	if(to_remove == 0 && valid_solution(string) == 1)
	{
		printf("no changes to string: %s\n", string);
		puts(string);
	}
	else
	{
		remove_function(string, result_string, 0, to_remove, 0, left, right);
	}
	
	

}


