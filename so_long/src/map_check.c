/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:50:27 by jasnguye          #+#    #+#             */
/*   Updated: 2024/02/13 18:47:34 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_ber_file(const char *filename)
{
	int	file_len;

	file_len = ft_strlen(filename);
	if (file_len >= 4)
	{
		if (ft_strncmp(filename + file_len - 4, ".ber", 4) == 0)
		{
			return (1);
		}
	}
	return (0);
}

/* int	is_rectangular(t_game *game)
{
	game->is_rect_colums = 0;
	game->is_rect_colums_first_row = 0;
	game->is_rect_i = 0;
	while (game->map[0][game->is_rect_colums_first_row] != '\n' 
		&& game->map[0][game->is_rect_colums_first_row] != '\0')
		game->is_rect_colums_first_row++;
	while (game->is_rect_i < game->map_height)
	{
		game->is_rect_colums = 0;
		while (game->map[game->is_rect_i][game->is_rect_colums] != '\n' 
		&& game->map[game->is_rect_i][game->is_rect_colums] != '\0')
			game->is_rect_colums++;
		if (game->is_rect_colums != game->is_rect_colums_first_row)
			return (0); 
		game->is_rect_i++;
	}
	while (game->is_rect_i < game->map_height)
	{
		if (game->map[game->is_rect_i][0] != '\n')
			return (0); 
		game->is_rect_i++;
	}
	return (1);
} */
int	is_rectangular(t_game *game)
{
	int	colums;
	int	colums_in_first_row;
	int	i;

	colums = 0;
	colums_in_first_row = 0;
	i = 0;
	while (game->map[0][colums_in_first_row] != '\n' 
		&& game->map[0][colums_in_first_row] != '\0')
		colums_in_first_row++;
	while (i < game->map_height)
	{
		colums = 0;
		while (game->map[i][colums] != '\n' && game->map[i][colums] != '\0')
			colums++;
		if (colums != colums_in_first_row)
			return (0);
		i++;
	}
	while (i < game->map_height)
	{
		if (game->map[i++][0] != '\n')
			return (0);
	}
	return (1);
}

int	is_valid_char(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (!(game->map[i][j] == '0' || game->map[i][j] == '1' || 
					game->map[i][j] == 'P' || game->map[i][j] == 'E' 
							|| game->map[i][j] == 'C'))
			{
				return (0); 
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_surrounded_by_walls(t_game *game)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (j < game->map_width)
	{
		if ((game->map[0][j] != '1') || 
				(game->map[game->map_height - 1][j] != '1'))
		{
			return (0);
		}
		j++;
	}
	while (i < game->map_height)
	{
		if (game->map[i][game->map_width -1] != '1' || game->map[i][0] != '1')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	map_check(t_game *game)
{
	find_player(game);
	count_collectibles(game);
	printf("x:%d\n", game->player_pos_x);
	printf("y:%d\n", game->player_pos_y);
	flood_fill(game->map, game->player_pos_x, game->player_pos_y, game);
	read_map(game->input_file, game);
	if (!(is_rectangular(game)) || !(is_valid_char(game)) 
		|| !(is_surrounded_by_walls(game)) || !(element_check(game))
		|| (game->flooded_exit != 1) 
		|| (game->flooded_collectibles != game->collectibles_nbr))
	{
		ft_printf("Error\nInvalid map!\n");
		if (!(is_rectangular(game)))
			ft_printf("Map is not rectangular!\n");
		else if (!(is_valid_char(game)))
			ft_printf("Map contains unknown char!\n");
		else if (!(is_surrounded_by_walls(game)))
			ft_printf("Map is not entirely surrounded by walls!\n");
		else if (!(element_check(game)))
			ft_printf("Map does not contain all the required elements!\n");
		else if ((game->flooded_collectibles != game->collectibles_nbr))
			ft_printf("No valid path found!\n");
		return (0);
	}
	return (1);
}
