/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:37:05 by jasnguye          #+#    #+#             */
/*   Updated: 2024/03/16 21:27:02 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "Libft/libft.h"
#define LSB 0x01

void	signal_handler(int signal_received)
{
	static int	bit_position;
	static int	character;
	int			bit;	

	if (signal_received == SIGUSR1)
	{
		bit = (LSB << bit_position);
		character = character | bit;
	}
	bit_position++;
	if (bit_position == 8)
	{
		ft_printf("%c", character);
		character = 0;
		bit_position = 0;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid_id;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error! Program does not take any arguments. Try: ./server\n");
	}
	pid_id = getpid();
	ft_printf("PID: %d\n", pid_id);
	while (1)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		pause();
	}
	return (0);
}
