/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:37:05 by jasnguye          #+#    #+#             */
/*   Updated: 2024/03/15 13:50:29 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <signal.h>
#include <unistd.h>
#include "Libft/libft.h"

int main(int argc, char *argv[])
{
    pid_t pid_id;

    (void)argv;
    if(argc != 1)
    {
        ft_printf("Error! Program does not take any arguments\n");
    }
    pid_id = getpid();
    ft_printf("PID: %d\n", pid_id);
}