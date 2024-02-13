/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:58:48 by jasnguye          #+#    #+#             */
/*   Updated: 2024/02/13 18:41:32 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	element_check(t_game *game)
{
	int	collectible;
	int	exit;
	int	player;

	collectible = 0;
	exit = 0;
	player = 0;
	count_elements(game, &collectible, &exit, &player);
	if (exit == 1 && collectible >= 1 && player == 1)
		return (1);
	return (0);
}

void	count_elements(t_game *game, int *collectible, int *exit, int *player)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	*collectible = 0;
	*player = 0;
	*exit = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'C' )
				(*collectible)++;
			else if (game->map[i][j] == 'E' )
				(*exit)++;
			else if (game->map[i][j] == 'P')
				(*player)++;
			j++;
		}
		i++;
	}
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
