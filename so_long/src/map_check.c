/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:50:27 by jasnguye          #+#    #+#             */
/*   Updated: 2024/02/12 20:30:17 by jasnguye         ###   ########.fr       */
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
			return (1); //valid
		}
	}
	return (0);
}


int		is_rectangular(t_game *game)
{
	int	colums;
	int	colums_in_first_row;
	int	i;

	colums = 0;
	colums_in_first_row = 0;
	i = 0;

	while (game->map[0][colums_in_first_row] != '\n' 
		&& game->map[0][colums_in_first_row] != '\0')
	{
		colums_in_first_row++;
	}
	while (i < game->map_height)
	{
		colums = 0;
		while (game->map[i][colums] != '\n' && game->map[i][colums] != '\0')
		{
			colums++;
		}
		if (colums != colums_in_first_row)
		{
			return (0); //invalid
		}
		i++;
	}

	// Check for extra characters beyond the defined height of the map
	while (i < game->map_height)
	{
		if (game->map[i][0] != '\n')
		{
			return (0); // Not rectangular
		}
		i++;
	}
	return (1);

}

int	is_valid_char(t_game *game)
{
	int i;
	int j;

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
				return (0); //not valid
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

int	element_check(t_game *game)
{
	int	i;
	int	j;
	int	collectible;
	int	exit;
	int	player;

	i = 0;
	j = 0;
	collectible = 0;
	exit = 0;
	player = 0;

	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'C' )
			{
				collectible++;
			}
			else if (game->map[i][j] == 'E' )
			{
				exit++;
			}
			else if (game->map[i][j] == 'P')
			{
				player++;
			}
			j++;
		}
		i++;
	}
	if (exit == 1 && collectible >= 1 && player == 1)
	{
		return (1);
	}
	return (0);
}

void	find_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < game->map_height)
	{
		i = 0;
		while (i < game->map_width)
		{
			if (game->map[j][i] == 'P')
			{
				game->player_pos_x = i;
				game->player_pos_y = j;
			}
			i++;
		}
		j++;
	}
}
void	count_collectibles(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < game->map_height)
	{
		i = 0;
		while (i < game->map_width)
		{
			if (game->map[j][i] == 'C')
			{
				game->collectibles_nbr++;
			}
			i++;
		}
		j++;
	}
}

void    flood_fill(char **map, int p_x, int p_y, t_game *game)
{
	int rows = game->map_height;
	int cols = game->map_width;

    map[p_y][p_x] = 'F';
    if (p_y > 0 && (map[p_y - 1][p_x] == '0' || map[p_y - 1][p_x] == 'C' || map[p_y - 1][p_x] == 'E'))
    {
        if (map[p_y - 1][p_x] == 'C')
            game->flooded_collectibles++;
        if (map[p_y - 1][p_x] == 'E')
            game->flooded_exit++;
        flood_fill(map, p_x, p_y - 1, game);
    }
    if (p_y < rows - 1 && (map[p_y + 1][p_x] == '0' || map[p_y + 1][p_x] == 'C' || map[p_y + 1][p_x] == 'E'))
    {
        if (map[p_y + 1][p_x] == 'C')
            game->flooded_collectibles++;
        if (map[p_y + 1][p_x] == 'E')
            game->flooded_exit++;
        flood_fill(map, p_x, p_y + 1, game);
    }
    if (p_x > 0 && (map[p_y][p_x - 1] == '0' || map[p_y][p_x - 1] == 'C' || map[p_y][p_x - 1] == 'E'))
    {
        if (map[p_y][p_x - 1] == 'C')
            game->flooded_collectibles++;
        if (map[p_y][p_x - 1] == 'E')
            game->flooded_exit++;
        flood_fill(map, p_x - 1, p_y, game);
    }
    if (p_x < cols - 1 && (map[p_y][p_x + 1] == '0' || map[p_y][p_x + 1] == 'C' || map[p_y][p_x + 1] == 'E'))
    {
        if (map[p_y][p_x + 1] == 'C')
            game->flooded_collectibles++;
        if (map[p_y][p_x + 1] == 'E')
            game->flooded_exit++;
        flood_fill(map, p_x + 1, p_y, game);
    }

} 


int map_check(t_game *game)
{
	
	find_player(game);
	count_collectibles(game);
	printf("x:%d\n", game->player_pos_x);
	printf("y:%d\n", game->player_pos_y);
	flood_fill(game->map, game->player_pos_x, game->player_pos_y, game);
	read_map(game->input_file, game);
	printf("collected collectibles: %d of %d\n", game->flooded_collectibles, game->collectibles_nbr);
	printf("exit: %d of 1", game->flooded_exit);

	if(!(is_rectangular(game)) || !(is_valid_char(game)) || !(is_surrounded_by_walls(game))  || !(element_check(game)) || (game->flooded_exit != 1) || (game->flooded_collectibles != game->collectibles_nbr))
	{
		ft_printf("Error\nInvalid map!");
		return(0);
	}
	return(1);
}

