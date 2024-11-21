#include <stdio.h>

int	ft_atoi(const char *str)
{
    int flag = 1; 
    int result = 0; 
    int i = 0; 
    while (str[i] >= 9 && str[i] <= 13)
    {
        i++; 
    }
    while (str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
        {
            flag = -1; 
        }
        i++; 
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + str[i] - '0'; 
        i++; 
    }
    return(result * flag); 
}
/*

int main(void)
{
    char string[] = "1234567890"; 
    printf("%d\n", ft_atoi(string)); 
}*/