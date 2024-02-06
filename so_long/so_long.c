/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:13:26 by jasnguye          #+#    #+#             */
/*   Updated: 2024/02/06 10:43:02 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	if(argc == 2)
	{
	t_game *game;

	game = malloc(sizeof(t_game));

	calculate_map_dimensions(argv[1], game);	
	read_map(argv[1], game);	
	if(map_check(game))
	{
		open_window(game);
		load_img(game);
		iterate_through_map(game);
		mlx_loop(game->mlx);
	}
	free(game);
	
	}
	else
	ft_printf("Invalid number of arguments!");

}