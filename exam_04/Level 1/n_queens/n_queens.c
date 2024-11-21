#include <stdlib.h>
#include <stdio.h>
/*moves along the specified direction from the start position to the end position and checks for collisions*/
int find_collisions(int *return_array, int input_len, int start_y, int end_y, int direction) 
{
    int current_x = 0; //makes us start at the start of the return_array
    int current_y = start_y;
    while(current_x != input_len -1 && current_y != end_y - 1)
    { 
        current_x++; //moving one to the right
        current_y += direction; //moving one up or down depending on the direction given
        if(current_y == return_array[current_x]) //check for collisions
        {
            return -1;
        }
    }
    return 0;
}

/* goes through the return_array and checks whether there are collisions 
by calling find_collisions and specifying the direction (1 = up, -1 = down) */
void check_permutation(int *return_array, int input_len) 
{
    int x = 0;
    while(x < input_len)
    {
        int start_y = return_array[x];
        int end_y = input_len;
        int direction = 1;
        
        if(find_collisions(return_array + x , input_len - x, start_y, end_y, direction) != 0)
        {
            return ;
        }
        end_y = -1;
        direction = -1;
        if(find_collisions(return_array + x, input_len - x , start_y, end_y, direction) != 0)
        {
            return ;
        }        
        x++;

    }
    int i = 0;
    while(i < input_len)
    {
        printf("%d ", return_array[i]);
        i++;
    }
    printf("\n");
}

/* new array is a copy of the original array without the numbers 
that were already put into the return_array */
int *create_new_array(int *array, int array_index, int len)
{
    int *new_array = malloc(sizeof(int) * len);
    if(!new_array)
    {
        return NULL;
    }
    int i = 0;
    int j = 0;
    while (i < len)
    {
        if(i != array_index)
        {
            new_array[j] = array[i];
            j++;
        }
        i++;
    }
    return new_array;
}
void build_permutations(int *return_array, int *array, int return_array_index, int current_len, int input_len)
{
    if(current_len == 1)
    {
        return_array[return_array_index] = array[0];
        check_permutation(return_array, input_len);
        return;
    }
    int array_index = 0;
    while(array_index < current_len)
    {
        return_array[return_array_index] = array[array_index];
        int *new_array = create_new_array(array, array_index, current_len);
        if(!new_array)
        {
            puts("memory allocation failed");
            return ;
        }
        build_permutations(return_array, new_array, return_array_index + 1, current_len - 1, input_len);
        array_index++;
    }
   
}
int main(int argc, char *argv[])
{
    (void)argc;
    int n = atoi(argv[1]);
    int *array = malloc(sizeof(int) * n);
    if(!array)
    {
        puts("memory allocation failed");
        return -1;
    }
    int i = 0;
    while(i < n)
    {
        array[i] = i;
        i++;
    }
    int *return_array = malloc(sizeof(int) * n);
    if(!return_array)
    {
        puts("memory allocation failed");
        return -1;
    }
    int current_len = n;
    int input_len = n;
    build_permutations(return_array, array, 0, current_len, input_len);
}
