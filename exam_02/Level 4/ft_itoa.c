#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa(int nbr)
{
    int copy = nbr; //put nbr in copy variable
    int len = 0; //important for malloc
    char *result; // string to be returned 
    int i = 0; //to iterate through result
    if(nbr == -2147483648) 
    {
        return("-2147483648\0"); //edge case 
    }
    if(nbr <= 0) // <= to get len if nbr is smaller or equal 0
    {
        len++; 
    }
    while(copy != 0) //get len
    {
        copy /= 10; 
        len++; 
    }
    result = (char *)malloc(sizeof(char) * len + 1);  //allocate memory
   result[len] = '\0'; //put null-terminator
    if(nbr == 0) 
    {
        result[i] = '0'; //put 0
        return(result); // return immediately
    }
    if(nbr < 0)
    {
        result[i] = '-'; //if nbr is negative
        nbr = -nbr; // make it positive
    }
    while(nbr) //while nbr exists
    {
        result[--len] = (nbr % 10) + '0'; //start filling up the string from the end and turning it into ascii -> [--len] to get the actual last position (indexing) 
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
