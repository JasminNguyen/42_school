#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


void sort_array(char *string)
{

}

int find_length(char *string)
{
    int i = 0;
    while(string[i] != '\0')
    {
        i++;
    }
    return(i);
}

char *create_new_array(char *string, int string_index)
{
    char *new_array = malloc(sizeof(char) * find_length(string));
    if(!new_array)
    {
        puts("memory allocation failed");
    }
    return(new_array);
}
void traverse_tree(char *return_string, char *string, int return_string_index)
{
    char *new_array;
    int string_index = 0;

    if(find_length(string) == 1)
    {
        printf("hello\n");
        return_string[return_string_index] = string[0];
        puts(return_string);
        return ;
    }
    while(string[string_index] != '\0')
    {
        return_string[return_string_index] = string[string_index];
        new_array = create_new_array(string, string_index);
        traverse_tree(return_string, new_array, ++return_string_index);
        string_index++;
        free(new_array);
        printf("hello1\n");
    }
}
int main(int argc, char *argv[])
{
    char *string = argv[1];
    sort_array(string);
  

  
    int len = find_length(string);

    
    char *return_string = malloc(sizeof(char) * len + 1);
    if(!return_string)
    {
        puts("memory allocation failed");
    }

    int return_string_index = 0;
    traverse_tree(return_string, string, return_string_index);
}