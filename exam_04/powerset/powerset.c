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

/* # include "stdio.h"
# include "stdlib.h"





int	main(int argc, char **argv)
{
	//first number
	int first_number = atoi(argv[1]);
	printf("first number is: %d\n", first_number);

	//variables needed
	int current_sum = 0;
	int start_index = 0;

	//put following numbers in array and determine array len
	int array[100];
	int i = 2;
	int j = 0;
	int len = 0;
	while(i <= argc - 1)
	{
		array[j] = atoi(argv[i]);
		printf("array[%d]: %d\n", j, atoi(argv[i]));
		i++;
		j++;
		len++;
	}
	//go through the array
	j = 0;
	while(!array[j])
	{
		
		j++;
	}

}


 */

#include <stdio.h>
#include <stdlib.h>

// Recursive function to find subsets that sum to first_number
void find_subsets(int first_number, int array[], int len, int current_set[], int current_len, int current_sum, int start_index) 
{
    // Base case: If the current sum equals first_number and we have added at least one element to current_set, print the subset
    if (current_sum == first_number && current_len > 0) 
	{
		int i = 0;
        while (i < current_len)
		{
			printf("%d ", current_set[i]);  // Print elements of the subset 
			i++;
		}
        printf("$\n");  // End the subset output with a $
        return;
    }

    // If we've gone through all elements, return
    if (start_index == len ) 
	{
        return;
    }

    // Include the current element (array[start_index])
    current_set[current_len] = array[start_index]; // Add element to the current subset
    find_subsets(first_number, array, len, current_set, current_len + 1, current_sum + array[start_index], start_index + 1);

    // Exclude the current element and move to the next element
    find_subsets(first_number, array, len, current_set, current_len, current_sum, start_index + 1);
}

int main(int argc, char **argv) 
{
   
    // First number (target sum)
    int first_number = atoi(argv[1]);

    // Array to hold the rest of the numbers
    int array[100];
    int len = 0;  // To track the len of the array

	// Populate the array with numbers from argv
	int i = 2;
    while (i < argc) 
	{
        array[len] = atoi(argv[i]);
		printf("array[%d]: %d\n", len, atoi(argv[i]));
        len++;
		i++;
    }

    // Array to hold the current subset
    int current_set[100];

    // Start finding subsets
    find_subsets(first_number, array, len, current_set, 0, 0, 0); //1. first_number, 2. array, 3. len, 4, current_set, 5.current_len, 6.current_sum, 7.start_index

    return 0;
}
