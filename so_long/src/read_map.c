/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:54:29 by jasnguye          #+#    #+#             */
/*   Updated: 2024/02/14 12:34:33 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	calculate_map_dimensions(const char *filename, t_game *game)
{
	int		fd;
	char	*line;
	int		map_width;
	int		map_height;

	map_width = 0;
	map_height = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1) 
	{
		perror("Error opening file!");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	while (line != NULL) 
	{
		map_width = ft_strlen(line);
		map_height++; 
		free(line);
		line = get_next_line(fd);
	}
	game->map_height = map_height;
	game->map_width = map_width;
	close(fd);
}

void	read_map(const char *filename, t_game *game)
{
	int	i;

	i = 0;
	game->fd = open(filename, O_RDONLY);
	game->map = (char **)malloc(sizeof(char *) * game->map_height);
	if (game->fd == -1) 
	{
		perror ("Error opening file!");
		exit (EXIT_FAILURE);
	}
	while (i < game->map_height)
	{
		game->map[i] = get_next_line(game->fd);
		printf("map: %s\n", game->map[i]);
		i++;
	}
	close(game->fd);
}
