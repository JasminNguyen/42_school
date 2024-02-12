/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:13:26 by jasnguye          #+#    #+#             */
/*   Updated: 2024/02/12 19:04:20 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	if(argc == 2 && is_ber_file(argv[1]))
	{
	t_game *game;

	game = malloc(sizeof(t_game));
	game->input_file = argv[1];
	calculate_map_dimensions(argv[1], game);	
	read_map(game->input_file, game);

		
	if(map_check(game))
	{
		
		//free the old map?
		//read_map(argv[1], game);
		
		open_window(game);
		load_img(game);
		iterate_through_map(game);
		mlx_loop(game->mlx);
	}
	free(game);
	
	}
	else
	{
		if(argc != 2)
		{
			ft_printf("Error\nInvalid number of arguments!");
		}
		else if(!(is_ber_file(argv[1])))
		{
			ft_printf("Error\nNot a .ber file!");
		}
	}
	

}