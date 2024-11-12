/* #include <stdio.h>
int valid_solution(char *string)
{
	int i = 0;
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
			return -1;
		}
		i++;
	}
	if(balance == 0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

void remove_parenthesis(char *string, char *result_string, int to_remove, int invalid_left, int invalid_right, int removed, int index)
{
	//base case: we have traversed the entire string and removed enough parenthesis
	if(string[index] == '\0')
	{ 
		if(to_remove == removed && valid_solution(result_string) == 1)
		{
			result_string[index] = '\0'; //dont forget to NULL-terminate the result_string!!!!
			puts(result_string);
			
		}
		return;
	}
	//exclude 
	if(string[index] == '(' && to_remove > removed)
	{
		result_string[index] = '_';
		remove_parenthesis(string, result_string, to_remove, invalid_left -1, invalid_right, removed + 1, index + 1);
	}
	else if(string[index] == ')'  && to_remove > removed)
	{
		result_string[index] = '_';
		remove_parenthesis(string, result_string, to_remove, invalid_left, invalid_right - 1, removed + 1, index + 1);
	}

	//include 
	result_string[index] = string[index];
	if(string[index] == '(')
	{
		remove_parenthesis(string, result_string, to_remove, invalid_left, invalid_left, removed, index + 1);
	}
	else if(string[index] == ')')
	{
		remove_parenthesis(string, result_string, to_remove, invalid_left, invalid_left, removed, index + 1);
	}
	else 
	{
		remove_parenthesis(string, result_string, to_remove, invalid_left, invalid_right, removed, index + 1);
	}

}


int main(int argc, char *argv[])
{
	(void)argc;
	char *string = argv[1];
	char result_string[100];

	int i = 0;
	int invalid_left = 0;
	int invalid_right = 0;

	//calculate invalid rights and lefts
	int left = 0;
	while(string[i] != '\0')
	{
		if(string[i] == '(')
		{
			left++;
		}
		else if(string[i] == ')')
		{
			if(left > 0)
			{
				left--;
			}
			else
			{
				invalid_right++;
			}
		}
		i++;
	}
	invalid_left = left;
	printf("invalid rights: %d\n", invalid_right);
	printf("invalid lefts: %d\n", invalid_left);
	//adding them
	int to_remove = invalid_left + invalid_right;

	//check for already valid input
	if(to_remove == 0 && valid_solution(string) == 1)
	{
		puts(string);
	}
	else
	{
		remove_parenthesis(string, result_string, to_remove, invalid_left, invalid_right, 0, 0); //int removed, int i
	}
} */

#include <stdio.h>
int valid_solution(char *string)
{
	int i = 0;
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
		if (balance < 0)
		{
			return (-1);
		}
		i++;
	}
	if(balance == 0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
	
}
void build_permutations(char *return_string, char *string, int to_remove, int invalid_left, int invalid_right, int removed, int index)
{

	if(string[index] == '\0')
	{
		if(to_remove == 0 && valid_solution(return_string))
		{
			return_string[index] = '\0';
			puts(return_string);
		}
		return;
	}
	
	if(string[index] == '(' && to_remove > 0)
	{
		return_string[index] = '_';
		build_permutations(return_string, string, to_remove - 1, invalid_left - 1, invalid_right, removed + 1, index + 1);
	}
	else if(string[index] == ')' && to_remove > 0)
	{
		return_string[index] = '_';
		build_permutations(return_string, string, to_remove - 1, invalid_left, invalid_right - 1, removed + 1, index + 1);
	}
	
	return_string[index] = string[index];
	if(string[index] == '(')
	{
		build_permutations(return_string, string, to_remove, invalid_left, invalid_right, removed, index + 1);
	}
	else if(string[index] == ')')
	{
		build_permutations(return_string, string, to_remove, invalid_left, invalid_right, removed, index + 1);
	}
}

int main(int argc, char *argv[])
{
	char *string = argv[1];

	int left = 0;
	int invalid_left = 0;
	int invalid_right = 0;
	int i = 0;
	while(string[i] != '\0')
	{
		if(string[i] == '(')
		{
			left++;
		}
		else if(string[i] == ')')
		{
			if(left > 0)
			{
				left--;
			}
			else
			{
				invalid_right++;
			}
		}
		i++;
	}
	invalid_left = left;

	int to_remove = invalid_left + invalid_right;
	char return_string[100];
	printf("invalid left: %d\n", invalid_left);
	printf("invalid right: %d\n", invalid_right);
	if(to_remove == 0 && valid_solution(string))
	{
		puts(string);
	}
	else
	build_permutations(return_string, string, to_remove, invalid_left, invalid_right, 0, 0);
}