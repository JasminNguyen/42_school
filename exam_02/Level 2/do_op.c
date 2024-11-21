/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:21:13 by jasnguye          #+#    #+#             */
/*   Updated: 2024/01/16 15:26:26 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_atoi(char *str)
{
	int i = 0;
	int sign = 1;
	int result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	while(str[i] == '-' || str[i] == '+')
	{
		if(str[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return(result *sign);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else 
	{
		if(nbr < 0)
		{
			nbr *= -1;
			write(1, "-", 1);
		}
        	if (nbr > 9)
        	{
               		ft_putnbr(nbr / 10);
                	nbr = nbr % 10;
        	}
	}
	ft_putchar(nbr + '0');

}
int main(int argc, char *argv[])
{
	if (argc == 4)
	{
		int result = 0;
		int i = 0;
		int first_a = ft_atoi(argv[1]);
		int third_a = ft_atoi(argv[3]);

		if (argv[2][i] == '+')
		{
			result = first_a + third_a;
		}
		else if (argv[2][i] == '-')
		{
			result = first_a - third_a;
		}
		else if(argv[2][i] == '*')
		{
			result = first_a * third_a;
		}
		else if(argv[2][i] == '/') 
		{
			result = first_a / third_a;
		}
		ft_putnbr(result);
	}
	write (1, "\n", 1);
}

