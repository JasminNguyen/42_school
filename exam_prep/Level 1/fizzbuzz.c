/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:56:27 by jasnguye          #+#    #+#             */
/*   Updated: 2024/01/08 14:21:51 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putnbr(int nbr)
{
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		nbr = nbr % 10;
	}
	nbr = nbr + '0';
	write (1, &nbr, 1);
}
void fizzbuzz(void)
{
	int i = 1;
	while (i <= 100)
	{
		if (i % 5 == 0 && i % 3 == 0)
		{
			write (1, "fizzbuzz\n", 9);
		}
		else if (i % 3 == 0)
		{
			write (1, "fizz\n", 5);
		}
		else if (i % 5 == 0)
		{
			write (1, "buzz\n", 5);
		}
		else 
		{
		ft_putnbr(i);
		write (1, "\n", 1);
		}
		i++;
	}

}

int main(void)
{
	fizzbuzz();
}

