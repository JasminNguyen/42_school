#include <unistd.h>
#include <stdio.h>
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
            nbr = -nbr;
            write(1, "-", 1);
        }
        if(nbr > 9)
        {
            ft_putnbr(nbr / 10);
            nbr = nbr % 10;
        }
        result = result * 10 + nbr;
    }
    ft_putchar(result + '0');    
}
void do_op(int i, int number)
{
    int result = 0;
    result = i * number;
    ft_putnbr(result);
}

int ft_atoi(char *str)
{
    int i = 0;
    int sign = 1;
    int result = 0;
    while(str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
    {
        i++;
    }
    while(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
        {
            sign = -1;
        }
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + str[i] - '0';
        i++;
    }
    return (result * sign);
}
int main(int argc, char *argv[])
{
    if(argc == 2)
    {
        int i = 1;
        int argument = ft_atoi(argv[1]); // turn argument into int first!!
        while(i < 10)
        {
            ft_putnbr(i);
            write(1, " x ", 3); 
            ft_putnbr(argument);
            write(1, " = ", 3);
            do_op(i, argument);
            i++;
            write(1, "\n", 1);
        }
    }
    else
    write(1, "\n", 1);
}  

