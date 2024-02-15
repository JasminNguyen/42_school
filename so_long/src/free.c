/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:57:34 by jasnguye          #+#    #+#             */
/*   Updated: 2024/02/15 15:05:27 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_exit(t_game *game)
{
	mlx_destroy_image(game->mlx, game->image.background);
	mlx_destroy_image(game->mlx, game->image.collectible);
	mlx_destroy_image(game->mlx, game->image.player);
	mlx_destroy_image(game->mlx, game->image.exit_closed);
	mlx_destroy_image(game->mlx, game->image.exit_open);
	mlx_destroy_image(game->mlx, game->image.wall);
	mlx_loop_end(game->mlx_win);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game, 0);
	free(game);
}

void	free_sprites(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_ptr);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
}

void	free_map(t_game *game, int flag)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	if (flag == 0)
		game->map = NULL;
}
