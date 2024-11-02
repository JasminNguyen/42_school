/*allowed functions: malloc, calloc, realloc*/
#include <unistd.h>
#include <stdio.h>
int is_valid(int n, int *solutions_array) 
{

}
int solve_n_queen(int n, int *solutions_array, int column)
{
	if()
	{
		
	}
}
int main(int argc, char *argv[])
{
	int n = atoi(argv[1]);
	int *solutions_array = malloc(sizeof(int) * n);
	int i = 0;
	while(i < n)
	{
		solutions_array[i] = -1;
		i++;
	}
	solve_n_queen(n, solutions_array, 0);
}