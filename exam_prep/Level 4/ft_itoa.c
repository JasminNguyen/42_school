#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa(int nbr)
{
    int copy = nbr; 
    int len = 0; 
    char *result; 
    int i = 0; 
    if(nbr == -2147483648)
    {
        return("-2147483648\0"); 
    }
    if(nbr <= 0)
    {
        len++; 
    }
    while(copy != 0)
    {
        copy /= 10; 
        len++; 
    }
    result = (char *)malloc(sizeof(char) * len + 1);  
   result[len] = '\0'; 
    if(nbr == 0)
    {
        result[i] = '0'; 
        return(result); 
    }
    if(nbr < 0)
    {
        result[i] = '-'; 
        nbr = -nbr; 
    }
    while(nbr)
    {
        result[--len] = (nbr % 10) + '0'; 
        nbr = nbr / 10; 
    }
   
    return(result); 
} 
/*
int main(void)
{
    int nbr = 1234567890; 
    printf("%s\n", ft_itoa(nbr)); 
}*/