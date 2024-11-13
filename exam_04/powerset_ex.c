#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>




void create_subset(int first_number, int *array, int len, int *result_array, int current_sum, int current_index, int current_len)
{
	//base case
	if(current_sum == first_number && current_len > 0)
	{
		int i = 0;
		while(i < current_len)
		{
			fprintf(stdout, "%i ", result_array[i]);
			i++;
		}
		fprintf(stdout, "\n");
		return;
	}
	if(current_index == len) //making sure I don't go out of bounds
	{
		return ;
	}
	result_array[current_len] = array[current_index];
	create_subset(first_number, array, len, result_array, current_sum + array[current_index], current_index + 1, current_len + 1);
	create_subset(first_number, array, len, result_array, current_sum, current_index + 1, current_len);
	
}
int main(int argc, char *argv[])
{
	int first_number = atoi(argv[1]);
	printf("first number: %d\n", first_number);
	int *array;
	int len = 0;
	int i = 2;
	//find array len
	while(i < argc)
	{
		i++;
		len ++;
	}
	printf("len is: %d\n", len);
	//allocate memory for array
	array = malloc(sizeof(int) *len);
	if(!array)
	{
		fprintf(stdout, "memory allocation failed");
	}

	i = 0;
	int j = 2;
	//populate array
	while(i < len)
	{
		array[i] = atoi(argv[j]);
		printf("array[%d]: %d\n", i, atoi(argv[j]));
		i++;
		j++;
	}

	//create result_array
	int *result_array = malloc(sizeof(int) * len);
	create_subset(first_number, array, len, result_array, 0, 0, 0);
}