#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return (i);
}

int main(int argc, char *argv[])
{
    if(argc == 2)
    {
        int len = ft_strlen(argv[1]) - 1;
        int start = 0;
        while((argv[1][len] == ' ' || argv[1][len] == '\t') && (len > 0))
        {
            len--;
        }
        while(argv[1][len] != ' ' && argv[1][len] != '\t' && len > 0)
        {
            len--; 
        }
        len++; //index for start needs to be adjusted because we did len-- until the first letter of the last word which means that we are at a space, but we want to be at the first letter of the last word again
        start = len; 
        while(argv[1][start] != ' ' && argv[1][start] != '\t' && argv[1][start] != '\0')
        {
            write(1, &argv[1][start], 1);
            start++;
        }
    }
    write(1, "\n", 1);
}