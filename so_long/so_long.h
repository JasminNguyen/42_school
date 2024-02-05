/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:14:21 by jasnguye          #+#    #+#             */
/*   Updated: 2024/02/05 18:38:03 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#define TILE_SIZE_X 48
#define TILE_SIZE_Y 48

#define PATH_TEXTURE_GRASS "img/TX-Tileset-Grass.xpm"
#define PATH_TEXTURE_WALL "img/TX-Tileset-Wall.xpm"

# include "./libraries/Libft/libft.h"
# include "libraries/mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_image{
	void *background;
	void *wall;
	void *player;
	void *exit;
	void *collectible;
}				t_image;

typedef struct	s_game {
	t_image image;
	void *mlx;
	void *mlx_win;
	void *img_ptr;
	int map_width;
	int map_height;
	char **map;
	int player_x;
	int player_y;
	//int new_player_position_x;
	//int new_player_position_y; 
	int fd;

}				t_game;

void open_window(t_game *game);
void load_img(t_game *game);
int handle_key_press(int keycode, t_game *game);
int close_window(t_game *game);
void free_exit(t_game *game);
void free_sprites(t_game *game);

void calculate_map_dimensions(const char *filename, t_game *game);
void read_map(const char *filename, t_game *game);
//void dispay_img(t_game *game);
void	load_img(t_game *game);
void	iterate_through_map(t_game *game);
void    put_tile(t_game *game, int width, int height);
int		map_check(t_game *game);
int is_rectangular(t_game *game);

void move_player(int keycode, t_game *game);
#endif
