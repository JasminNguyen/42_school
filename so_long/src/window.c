/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:04:22 by jasnguye          #+#    #+#             */
/*   Updated: 2024/02/12 20:13:20 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	open_window(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->map_width * TILE_SIZE_X, 
			game->map_height * TILE_SIZE_X, "My MiniLibX Window");
	mlx_hook(game->mlx_win,
		KeyPress, KeyPressMask, &handle_key_press, game);
	mlx_hook(game->mlx_win, 17, 0, &close_window, game);
}

int	handle_key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		free_exit(game);
		exit(0);
	}
	move_player(keycode, game);
	return (0);
}

int	close_window(t_game *game)
{
	free_exit(game);
	exit(0);
	return (0);
}
