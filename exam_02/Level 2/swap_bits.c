/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:20:48 by jasnguye          #+#    #+#             */
/*   Updated: 2024/01/16 18:53:59 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
unsigned char swap_bits(unsigned char octet)
{
	return((octet >> 4) | (octet << 4));
}
/*
int main(void)
{
	unsigned char byte = 1;
	printf("%d\n", swap_bits(byte));
}*/
