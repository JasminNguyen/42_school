/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:22:20 by jasnguye          #+#    #+#             */
/*   Updated: 2024/02/08 11:33:58 by jasnguye         ###   ########.fr       */
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
	game->image.exit_closed = mlx_xpm_file_to_image(game->mlx, "img/closed_door48.xpm", &width, &height);
	game->image.exit_open = mlx_xpm_file_to_image(game->mlx, "img/open_door48.xpm", &width, &height);
	
	if(game->image.background == NULL || game->image.wall == NULL)
	{
		free_sprites(game);
	}

} 


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
		(game->collectibles_nbr)++;
	}
	else if (game->map[height][width] == 'P')
	{
		game->player_y = height;
		game->player_x = width;
		//printf("x: %d\n", game->player_x);
		//printf("y: %d\n", game->player_y);
		//saving the players position??
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->image.player, width * 48, height * 48);
	}
	else if (game->map[height][width] == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->image.exit_closed, width * 48, height * 48);
		game->exit_y = height;
		game->exit_x = width;
		//printf("exit width: %d\n", game->exit_x);
		//printf("exit height: %d\n", game->exit_y);
		//saving the exits position to later change the tile to an open door
	}

/* 	else 
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->image.background, width * 48, height * 48);
	} */
 				
}

void open_exit(t_game *game)
{

	int i = 0;
	int j = 0;
	//game->exit_accessible = 1;

	while(i < game->map_height)
	{
		
		while(j < game->map_width)
		{
			
			if(game->map[i][j] == 'C')
			{
				(game->collectibles_nbr)++;
			}
			j++;
		}
		i++;
	}
	//printf("collectibles_nbr: %d\n", game->collectibes_nbr);
	if (game->collectibles_nbr == game->collectibles_collected)
	{	
		game->exit_accessible = 1;
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->image.exit_open, game->exit_x * 48, game->exit_y * 48);
		//printf("exit width: %d\n", game->exit_x);
		//printf("exit height: %d\n", game->exit_y);
		/* move_player_to_exit(game); */
		if(game->player_x == game->exit_x && game->player_y == game->exit_y)
		{
			close_window(game);
		}
	}
}
