/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:22:20 by jasnguye          #+#    #+#             */
/*   Updated: 2024/02/05 17:35:17 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


 void load_img(t_game *game)
{
	int width;
	int height;
	
	
	game->image.background = mlx_xpm_file_to_image(game->mlx, "img/Grass2.xpm", &width, &height);
	game->image.wall = mlx_xpm_file_to_image(game->mlx, "img/Wall.xpm", &width, &height);
	game->image.player = mlx_xpm_file_to_image(game->mlx, "img/Snail_Player.xpm", &width, &height);
	game->image.collectible = mlx_xpm_file_to_image(game->mlx, "img/Apple.xpm", &width, &height);

	if(game->image.background == NULL || game->image.wall == NULL)
	{
		free_sprites(game);
	}

} 
/*
void dispay_img(t_game *game)
{
	int i = 0;
	int j = 0;
	
	while (j < game->map_height)
	{
		i = 0;
		while (i < game->map_width)
		{
			
			if(game->map[j][i] == '0')
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->image.background, i * 48, j * 48);
			}
			else if(game->map[j][i] == '1')
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->image.wall, i * 48, j *48);
			}
			else
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->image.background, i * 48, j * 48);
			j++;
		}
		i++;
	}
}
*/

void iterate_through_map(t_game *game)
{
    int width;
    int height;

    height = 0;
    while (height < game->map_height)
    {
        width = 0;
        while(width < game->map_width)
        {
            put_tile(game, width, height);
            width++;
        }
        height++;
    }
}
void    put_tile(t_game *game, int width, int height)//puts the right tile
{	
	
	if (game->map[height][width] == '1')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->image.wall, width * 48, height * 48);
	}
	else if (game->map[height][width] == '0')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->image.background, width * 48, height * 48);
	}
	else if (game->map[height][width] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->image.collectible, width * 48, height * 48);
	}
	else if (game->map[height][width] == 'P')
	{
		game->player_y = height;
		game->player_x = width;
		printf("x: %d\n", game->player_x);
		printf("y: %d\n", game->player_y);
		//saving the players position??
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->image.player, width * 48, height * 48);
	}
	else 
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->image.background, width * 48, height * 48);
	}
 				
}
