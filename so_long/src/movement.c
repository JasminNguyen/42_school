/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:29:15 by jasnguye          #+#    #+#             */
/*   Updated: 2024/02/14 13:20:50 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_player(t_game *game, int new_player_x, int new_player_y)
{
	if (game->map[new_player_y][new_player_x] != 'E' 
			|| game->exit_accessible == 1)
	{
		if (game->map[new_player_y][new_player_x] == 'C')
		{
			(game->collectibles_collected)++;
			game->map[new_player_y][new_player_x] = '0';
		}
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->image.background, game->player_x * 48,
			game->player_y * 48);
		game->player_x = new_player_x;
		game->player_y = new_player_y;
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->image.player, game->player_x * 48, game->player_y * 48);
		(game->moves)++;
		ft_printf("Moves: %d\n", game->moves);
		open_exit(game);
	}
}

void	press_key(int keycode, t_game *game)
{
	int	new_player_position_x;
	int	new_player_position_y;

	new_player_position_x = game->player_x;
	new_player_position_y = game->player_y;
	if (keycode == 65362 || keycode == 65361 
		|| keycode == 65364 || keycode == 65363)
	{
		if (keycode == 65362)
			new_player_position_y -= 1;
		else if (keycode == 65361)
			new_player_position_x -= 1;
		else if (keycode == 65364)
			new_player_position_y += 1;
		else if (keycode == 65363)
			new_player_position_x += 1;
	}
	if (new_player_position_x >= 0 && new_player_position_x < game->map_width 
		&& new_player_position_y >= 0 
		&& new_player_position_y < game->map_height 
		&& game->map[new_player_position_y][new_player_position_x] != '1')
	{
		move_player(game, new_player_position_x, new_player_position_y);
	}
}
