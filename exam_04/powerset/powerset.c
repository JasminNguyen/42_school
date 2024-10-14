/*
functions allowed: atoi, fprintf, malloc, calloc, realloc, free, stdout, stderr, write

Write a program that will take as an argument an integer n followed by a set s of integers.
Your program should display all the subsets of s whose sum of elements is n.
The order of the lines is not important, but the order of the element in a subset is. 
You must not have any duplicates (e.g. '1 2' and '2 1'). In case of malloc error your program will exit with code 1.
We will not test with invalid sets('1 1 2').


Examples:

./a.out 3 1 0 2 4 5 3
3 $
0 3 $
1 2 $
1 0 2 $

./a.out 12 5 2 1 8 4 3 7 11
8 4 $
1 11 $
1 4 7 $
1 8 3 $
2 3 7 $
5 7 $
5 4 3 $
5 2 1 4 $


./a.out 0 1 -1
1 -1 $

./a.out 7 3 8 2
$
*/

# include "stdio.h"
# include "stdlib.h"

int	main(int argc, char **argv)
{
	//first number
	int first_number = atoi(argv[1]);
	printf("first number is: %d\n", first_number);

	//put following numbers in array
	int array[100];
	int i = 2;
	int j = 0;
	while(i <= argc - 1)
	{
		array[j] = atoi(argv[i]);
		printf("array[%d]: %d\n", j, atoi(argv[i]));
		i++;
		j++;
	}
	//go through the array
	j = 0;
	while(!array[j])
	{
		
		j++;
	}

}

