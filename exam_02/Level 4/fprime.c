#include <unistd.h>
#include <stdlib.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
void ft_putnbr(int nbr)
{
    int result = 0;
    if(nbr == -2147483648)
    {
        write(1, "-2147483648", 11);
    }
    else
    {
        if(nbr < 0)
        {
            write(1, "-", 1);
            nbr = -nbr;
        }
        if (nbr > 9)
        {
           ft_putnbr(nbr / 10);
           nbr = nbr % 10; 
        }
        result = result * 10 + nbr;
        ft_putchar(result + '0');
    }
}
int main(int argc, char *argv[])
{
    if(argc == 2 && atoi(argv[1]) > 0)
    {
        int i = 2;
        int number = atoi(argv[1]);
        if(number == 1)
        {
            write(1, "1", 1);
        }
        while(i != number)
        {
            if(number % i == 0)
            {
                ft_putnbr(i); 
                if(i == number)
                {
                    break ;
                }
                write(1, "*", 1); 
                number = number / i;//number gets smaller with each iteration, takes value of found prime factor
                i = 1; 
            }
            i++;//i is being incremented
        } 
        if(number != 1)// to find last prime facor(must be outside of loop)
        {
            ft_putnbr(i);
        }

    }
    write(1, "\n", 1);
}