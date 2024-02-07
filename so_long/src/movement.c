/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:29:15 by jasnguye          #+#    #+#             */
/*   Updated: 2024/02/07 17:29:56 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void move_player(int keycode, t_game *game)
{
	
	int new_player_position_x = game->player_x;
    int new_player_position_y = game->player_y;
	
	if(keycode == 65362 || keycode == 65361 || keycode == 65364 || keycode == 65363)
	{
		
    	if (keycode == 65362) // Up arrow key
   	 	{
        	new_player_position_y -= 1;
    	}
    	else if (keycode == 65361) // Left arrow key
    	{
        	new_player_position_x -= 1;
   	 	}
    	else if (keycode == 65364) // Down arrow key
    	{
        	new_player_position_y += 1;
    	}
    	else if (keycode == 65363) // Right arrow key
    	{
        	new_player_position_x += 1;
    	}
	
	}
	
    // Check if the new position is within bounds and not hitting a wall
    if (new_player_position_x >= 0 && new_player_position_x < game->map_width &&
        new_player_position_y >= 0 && new_player_position_y < game->map_height &&
        game->map[new_player_position_y][new_player_position_x] != '1')
    {
		if(game->map[new_player_position_y][new_player_position_x] == 'C')
		{
			(game->collectibles_collected)++;
			ft_printf("Collectibles collected: %d/%d\n", game->collectibles_collected, game->collectibes_nbr);
		}
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->image.background, game->player_x * 48, game->player_y * 48); // background
        game->player_x = new_player_position_x;
        game->player_y = new_player_position_y;
		
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->image.player, game->player_x * 48, game->player_y * 48);//player	
		(game->moves)++;
		ft_printf("Moves: %d\n", game->moves);
		open_exit(game);
    }
}


