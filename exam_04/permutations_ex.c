#include <stdio.h>
#include <stdlib.h>
int ft_strlen(char *string)
{
    int i = 0;
    while(string[i] != '\0')
    {
        i++;
    }
    return(i);
}
void sort_string(char *string)
{
    int len = ft_strlen(string);
    char temp;

    while(len > 0)
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
char *create_new_string(char *string, int exclude_index)
{
    int len = ft_strlen(string);
    char *new_string = malloc(sizeof(char) * len); //no + 1 necessary since we have one char less 
    if(!new_string)
    {
        puts("memory allocation failed");
    }
    int i = 0;
    int j = 0;
    while(string[i] != '\0')
    {
        if(i != exclude_index)
        {
            new_string[j] = string[i];
            j++;
        }
        i++;
    }
    new_string[j] = '\0';
    return(new_string);
}
void build_permutations(char *return_string, char *string, int return_string_index)
{
    if(ft_strlen(string) == 1)
    {
        return_string[return_string_index] = string[0];
        return_string[return_string_index + 1] = '\0';
        puts(return_string);
        return;
    }
    int string_index = 0;
    while(string[string_index] != '\0')
    {
        return_string[return_string_index] = string[string_index];
        char *new_string = create_new_string(string, string_index);
        build_permutations(return_string, new_string, return_string_index + 1);
        string_index++;
        free(new_string);
    }
}
int main(int argc, char *argv[])
{
    char *string = argv[1];
    sort_string(string);
    printf("sorted string: %s\n", string);

    int len = ft_strlen(string);
    char *return_string = malloc(sizeof(char) *len + 1);
    if(!return_string)
    {
        puts("memory allocation failed");
    }
    int return_string_index = 0;
    build_permutations(return_string, string, return_string_index);
}