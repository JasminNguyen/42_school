
#include <stdio.h>

int ft_strlen(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return(i);
}

char    *ft_strrev(char *str)
{
    int start = 0;
    int end = ft_strlen(str) - 1;
    char temp = 0;
    while(start < end)
    {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
    return(str);
}

/* int main(void)
{
    char string[] = "hello my name is jasmin .";
    ft_strrev(string);
    printf("%s\n", string);
} */
