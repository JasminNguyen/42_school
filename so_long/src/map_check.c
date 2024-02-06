/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:50:27 by jasnguye          #+#    #+#             */
/*   Updated: 2024/02/06 16:37:15 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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


int map_check(t_game *game)
{
	
	if(!(is_rectangular(game)) || !(is_valid_char(game)) || !(is_surrounded_by_walls(game))  || !(element_check(game)) )
	{
		ft_printf("Error\nInvalid map!");
		return(0);
	}
	return(1);
}

