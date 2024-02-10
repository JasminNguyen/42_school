/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:50:27 by jasnguye          #+#    #+#             */
/*   Updated: 2024/02/10 17:53:38 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_ber_file(const char *filename)
{
	int file_len = ft_strlen(filename);
	if(file_len >= 4)
	{
		if(ft_strncmp(filename + file_len - 4, ".ber", 4) == 0)
		{
			return(1); //valid
		}
	}
	return(0);
}


int is_rectangular(t_game *game)
{
	int colums = 0;
	int colums_in_first_row = 0;
	int i = 0;


	
	while (game->map[0][colums_in_first_row] != '\n' && game->map[0][colums_in_first_row] != '\0')
	{
		colums_in_first_row++;
	}
	//printf("colums first row:%d\n", colums_in_first_row);
	
	while( i < game->map_height)
	{
		colums = 0;
		while(game->map[i][colums] != '\n' && game->map[i][colums] != '\0')
		{
			colums++;
			
		}
		if(colums != colums_in_first_row)
		{
			return(0); //invalid
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
		
		// printf("colums in %i row: %d\n", i, colums);
	return(1);

}

int is_valid_char(t_game *game)
{
	int i = 0;
	int j = 0;
	while(i < game->map_height)
	{
		j = 0;
		while(j < game->map_width)
		{
			
			if(!(game->map[i][j] == '0' || game->map[i][j] == '1' || game->map[i][j] == 'P' || game->map[i][j] == 'E' || game->map[i][j] == 'C'))
			{
				return (0); //not valid
			}
			j++;
		}
		i++;
	}
	return(1);
}

int is_surrounded_by_walls(t_game *game)
{
	
	int j = 0;
	int i = 0;
	while (j < game->map_width)
	{
		if((game->map[0][j] != '1') || (game->map[game->map_height - 1][j] != '1'))
		{
			return(0);
		}
		j++;
	}
	while (i < game->map_height)
	{
		if(game->map[i][game->map_width -1] != '1' || game->map[i][0] != '1')
		{
			return(0);
		}
		i++;
	}

	return(1);
}

int element_check(t_game *game)
{
	int i = 0;
	int j = 0;
	int collectible = 0;
	int exit = 0;
	int player = 0;
	
	while(i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if(game->map[i][j] == 'C' )
			{
				collectible++;
			}
			else if(game->map[i][j] == 'E' )
			{
				exit++;
			}
			else if(game->map[i][j] == 'P')
			{
				player++;
			}
			j++;
		}
		i++;
		
	}
	
	if(exit == 1 && collectible >= 1 && player == 1)
	{
		return (1);
	}
	return(0);
}


void flood_fill(t_game *game, int x, int y)
{
	game->map[y][x] = 'F';
	
	if(y > 0 && (game->map[y - 1][x] == '0' || game->map[y - 1][x] == 'C'))//up
	{
		if (game->map[y - 1][x] == 'C')
            game->flooded_collectibles++;
        if (game->map[y - 1][x] == 'E')
            game->flooded_exit++;
        flood_fill(game, x, y);
	}
	 if(y < game->map_height -1 && (game->map[y + 1][x] == '0' || game->map[y + 1][x] == 'C'))//down
	{
		if (game->map[y + 1][x] == 'C')
            game->flooded_collectibles++;
        if (game->map[y + 1][x] == 'E')
            game->flooded_exit++;
        flood_fill(game, x, y);
	}
	 if(x > 0 && (game->map[y][x - 1] == '0' || game->map[y][x -1] == 'C'))//left
	{
		if (game->map[y][x - 1] == 'C')
            game->flooded_collectibles++;
        if (game->map[y][x - 1] == 'E')
            game->flooded_exit++;
        flood_fill(game, x, y);
	}
	 if(x < game->map_height - 1 && (game->map[y][x + 1] == '0' || game->map[y][x + 1] == 'C'))//right
	{
		if (game->map[y][x + 1] == 'C')
            game->flooded_collectibles++;
        if (game->map[y][x + 1] == 'E')
            game->flooded_exit++;
        flood_fill(game, x, y);
	}

}


void find_player(t_game *game)
{
    int i;
    int j;

    j = 0;
    while (j < game->map_height)
    {
        i = 0;
        while(i < game->map_width)
        {
            if(game->map[j][i] == 'P')
			{
				game->player_pos_x = i;
				game->player_pos_y = j;
			}
            i++;
        }
        j++;
    }
}


int check_valid_path(t_game *game)
{
	find_player(game);
	int x = game->player_pos_x;
	int y = game->player_pos_y;
	printf("x is%d\n", x);
	printf("y is%d\n", y);
    // Base case: If player's position is out of bounds or on a wall, return 0
    if (x < 0 || x >= game->map_width ||
        y < 0 || y >= game->map_height ||
        game->map[y][x] == '1') {
        ft_printf("Player is out of bounds or on a wall\n");
        return 0;
    }

    // Flood fill to check for a valid path
    flood_fill(game, x, y);

    // Check if the flooded exit count is exactly 1 and all collectibles are flooded
    if (game->flooded_exit == 1 && game->flooded_collectibles == game->collectibles_nbr) {
        return 1;
    } else {
        ft_printf("Not a valid path\n");
        return 0;
    }

}

int map_check(t_game *game)
{
	
	if(!(is_rectangular(game)) || !(is_valid_char(game)) || !(is_surrounded_by_walls(game))  || !(element_check(game)) || !(check_valid_path(game)))
	{
		ft_printf("Error\nInvalid map!");
		return(0);
	}
	return(1);
}

