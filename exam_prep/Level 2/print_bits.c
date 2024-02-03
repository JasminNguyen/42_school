/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:42:14 by jasnguye          #+#    #+#             */
/*   Updated: 2024/01/11 14:09:02 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void print_bits(unsigned char octet)
{
    int i = 8; // Initialize a counter variable i to 8
    unsigned char bit = 0; // Initialize a variable bit to 0

    while (i--) // Loop through each bit of octet
    {
        bit = (octet >> i & 1) + '0'; // Shift the bit of octet to the right i times and use the bitwise AND operator with 1 to get the bit value. Then add 48 or '0' to convert the bit value to its ASCII representation ('0' or '1')
        write (1, &bit, 1); // Write the ASCII representation of the bit to the standard output (stdout)
    }
}

/*void print_bits(unsigned char octet)
{
	int i = 128;
	while (i > 0)
	{
		if (octet & i)
		{
			write(1, "1", 1);
		}
		else 
		{
			write(1, "0", 1);
		}
		i = i / 2;
	}
}*/
/*
int main(void)
{
	unsigned char byte = 1;
	print_bits(byte);
}*/
