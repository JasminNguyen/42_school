/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:37:14 by jasnguye          #+#    #+#             */
/*   Updated: 2024/03/16 21:26:23 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "Libft/libft.h"

void	send_message(int pid, char *message)
{
	int	i;
	int	character;
	int	bit_position;
	int	bit;

	i = 0;
	while (message[i] != '\0')
	{
		character = message[i];
		bit_position = 0;
		while (bit_position < 8)
		{
			bit = (character >> bit_position) & 1;
			if (bit == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(2000);
			bit_position++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*message;

	if (argc != 3)
	{
		ft_printf("Wrong amount of arguments! Try: ./client <PID> <MESSAGE>\n");
	}
	else
	{
		pid = ft_atoi(argv[1]);
		if (pid < 0 || pid < 2000)
		{
			ft_printf("Non valid PID.\n");
		}
		else
		{
			message = argv[2];
			send_message(pid, message);
		}
	}
}
