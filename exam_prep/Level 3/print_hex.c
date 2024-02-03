/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:54:40 by jasnguye          #+#    #+#             */
/*   Updated: 2024/01/12 15:19:30 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
void print_hex(int nbr)
{
	int base = 16;
	char *symbols = "0123456789abcdef";
	if (nbr >= base)
	{
		print_hex(nbr / base);
	}
	nbr = symbols[nbr % base];
	write (1, &nbr, 1);
}
int ft_atoi(char *str)
{
	int i = 0;
	int sign = 1;
	int number = 0;
	
	while(str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign = -1;
		}
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + str[i] - '0';
		i++;
	}
	return (number * sign);


}

int main(int argc, char *argv[])
{
        if (argc != 2)
        {
                write(1, "\n", 1);
        }
        if (argc == 2)
        {
                int number = ft_atoi(argv[1]);
               // printf("%d", number);
	       	print_hex(number);
        }

}
