/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:50:27 by jasnguye          #+#    #+#             */
/*   Updated: 2024/02/05 18:47:10 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int is_rectangular(t_game *game)
{
	int column = 0;
	int column_first_row = 0;
	int i = 0;

	
	while (game->map[0][column_first_row] != '\0')
	{
		column_first_row++;
	}
	//printf("colums first row:%d\n", column_first_row);
	
	while( i < game->map_height)
	{
		column = 0;
		while(game->map[i][column] != '\0')
		{
			column++;
			
		}
		if(column != column_first_row)
		{
			return(0); //invalid
		}
		i++;
		//printf("colums in %i row: %d\n", i, column);
	}
	return(1);//valid
}


int map_check(t_game *game)
{
	
	if(!(is_rectangular(game)))
	{
		ft_printf("Invalid map!");
		return(0);
	}
	return(1);
}

