/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:13:26 by jasnguye          #+#    #+#             */
/*   Updated: 2024/02/14 15:00:41 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	launch_game(t_game *game)
{
	open_window(game);
	load_img(game);
	iterate_through_map(game);
	mlx_loop(game->mlx);
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc == 2 && is_ber_file(argv[1]))
	{
		game = malloc(sizeof(t_game));
		game->input_file = argv[1];
		calculate_map_dimensions(argv[1], game);
		read_map(game->input_file, game);
		game->moves = 0;
		game->collectibles_collected = 0;
		if (map_check(game))
		{
			launch_game(game);
		}
		else
			free_map(game, 1);
		free(game);
	}
	else
	{
		if (argc != 2)
			ft_printf("Error\nInvalid number of arguments!");
		else if (!(is_ber_file(argv[1])))
			ft_printf("Error\nNot a .ber file!");
	}
}
