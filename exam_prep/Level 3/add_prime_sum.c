/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:57:21 by jasnguye          #+#    #+#             */
/*   Updated: 2024/01/22 15:05:35 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_atoi(char *str)
{
    int i = 0;
    int sign = 1;
    int result = 0;
    while(str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
    {
        i++;
    }
    while (str[i] == '-' || str[i] == '+')
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

int prime(int nbr)
{
    int i = 2;
    if(nbr == 1)
    {
        return (0);
    }
    while(i < nbr)
    {
        if(nbr % i == 0)
        {
            return (0);
        }
        i++;
    }
    return (1);

}
void ft_putchar(char c)
{
    write(1, &c, 1);
}
void ft_putnbr(int nbr)
{
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
        if(nbr > 9)
        {
            ft_putnbr(nbr / 10);
            nbr = nbr % 10;
        }
        ft_putchar(nbr + '0');
    }
}

int main(int argc, char *argv[])
{
    if(argc == 2) 
    {
        int result = 0;
        int max_value = ft_atoi(argv[1]);
        int i = 0;
        while(i <= max_value)
        {
            if(prime(i) == 1)
            {
                result = result + i;
            }
            i++;
        }
        ft_putnbr(result);
        write(1, "\n", 1);
    }
    else
    {
        write(1, "0\n", 2);
    }
}
