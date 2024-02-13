/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:13:08 by jasnguye          #+#    #+#             */
/*   Updated: 2024/02/13 18:41:12 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	flood_fill(char **map, int p_x, int p_y, t_game *game)
{
	int	rows;
	int	cols;

	rows = game->map_height;
	cols = game->map_width;
	map[p_y][p_x] = 'F';
	if ((p_y > 0 && (map[p_y - 1][p_x] == '0' || 
			map[p_y - 1][p_x] == 'C' || 
		map[p_y - 1][p_x] == 'E'))
		|| (p_y < rows - 1 && (map[p_y + 1][p_x] == '0' 
		|| map[p_y + 1][p_x] == 'C' || map[p_y + 1][p_x] == 'E')))
	{
		check_path_up_and_down(map, p_x, p_y, game);
	}
	if ((p_x > 0 && (map[p_y][p_x - 1] == '0' 
			|| map[p_y][p_x - 1] == 'C' || map[p_y][p_x - 1] == 'E'))
		|| (p_x < cols - 1 && (map[p_y][p_x + 1] == '0' 
		|| map[p_y][p_x + 1] == 'C' || map[p_y][p_x + 1] == 'E')))
	{
		check_path_right_and_left(map, p_x, p_y, game);
	}
}

void	check_path_up_and_down(char **map, int p_x, int p_y, t_game *game)
{
	int	rows;
	int	cols;

	rows = game->map_height;
	cols = game->map_width;
	if (p_y > 0 && (map[p_y - 1][p_x] == '0' || 
		map[p_y - 1][p_x] == 'C' || 
			map[p_y - 1][p_x] == 'E'))
	{
		if (map[p_y - 1][p_x] == 'C')
			game->flooded_collectibles++;
		if (map[p_y - 1][p_x] == 'E')
			game->flooded_exit++;
		flood_fill(map, p_x, p_y - 1, game);
	}
	if (p_y < rows - 1 && (map[p_y + 1][p_x] == '0' 
		|| map[p_y + 1][p_x] == 'C' || map[p_y + 1][p_x] == 'E'))
	{
		if (map[p_y + 1][p_x] == 'C')
			game->flooded_collectibles++;
		if (map[p_y + 1][p_x] == 'E')
			game->flooded_exit++;
		flood_fill(map, p_x, p_y + 1, game);
	}
}

void	check_path_right_and_left(char **map, int p_x, int p_y, t_game *game)
{
	int	rows;
	int	cols;

	rows = game->map_height;
	cols = game->map_width;
	if (p_x > 0 && (map[p_y][p_x - 1] == '0' 
		|| map[p_y][p_x - 1] == 'C' || map[p_y][p_x - 1] == 'E'))
	{
		if (map[p_y][p_x - 1] == 'C')
			game->flooded_collectibles++;
		if (map[p_y][p_x - 1] == 'E')
			game->flooded_exit++;
		flood_fill(map, p_x - 1, p_y, game);
	}
	if (p_x < cols - 1 && (map[p_y][p_x + 1] == '0' 
		|| map[p_y][p_x + 1] == 'C' || map[p_y][p_x + 1] == 'E'))
	{
		if (map[p_y][p_x + 1] == 'C')
			game->flooded_collectibles++;
		if (map[p_y][p_x + 1] == 'E')
			game->flooded_exit++;
		flood_fill(map, p_x + 1, p_y, game);
	}
}
