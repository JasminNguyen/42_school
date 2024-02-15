/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:29:15 by jasnguye          #+#    #+#             */
/*   Updated: 2024/02/15 11:32:27 by jasnguye         ###   ########.fr       */
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
		which_key(keycode, &new_player_position_x, &new_player_position_y);
	}
	if (new_player_position_x >= 0 && new_player_position_x < game->map_width 
		&& new_player_position_y >= 0 
		&& new_player_position_y < game->map_height 
		&& game->map[new_player_position_y][new_player_position_x] != '1' 
		&& (new_player_position_x != game->player_x 
		|| new_player_position_y != game->player_y))
	{
		count_moves(game, new_player_position_x, new_player_position_y);
	}
}

void	which_key(int keycode, int *x, int *y)
{
	if (keycode == 65362)
		(*y) -= 1;
	else if (keycode == 65361)
		(*x) -= 1;
	else if (keycode == 65364)
		(*y) += 1;
	else if (keycode == 65363)
		(*x) += 1;
}

void	count_moves(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'E' 
		&& game->exit_accessible != 1)
	{
		return ;
	}
	(game->moves)++;
	move_player(game, x, y);
	ft_printf("Moves: %d\n", game->moves);
}
