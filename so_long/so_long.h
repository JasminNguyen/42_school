/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:14:21 by jasnguye          #+#    #+#             */
/*   Updated: 2024/02/15 15:05:39 by jasnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE_X 48
# define TILE_SIZE_Y 48

# include "./libraries/Libft/libft.h"
# include "libraries/mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_image{
	void	*background;
	void	*wall;
	void	*player;
	void	*exit_closed;
	void	*exit_open;
	void	*collectible;
}				t_image;

typedef struct s_game {
	t_image	image;
	void	*mlx;
	void	*mlx_win;
	void	*img_ptr;
	int		map_width;
	int		map_height;
	char	**map;
	char	**map_cpy;
	int		player_x;
	int		player_y;
	int		player_pos_x;
	int		player_pos_y;
	int		exit_pos_x;
	int		exit_pos_y;
	int		exit_x;
	int		exit_y;
	int		fd;
	int		moves;
	int		collectibles_collected;
	int		collectibles_nbr;
	int		exit_accessible;
	int		flooded_collectibles;
	int		flooded_exit;
	char	*input_file;
	int		is_rect_colums;
	int		is_rect_colums_first_row;
	int		is_rect_i;

}				t_game;

void	open_window(t_game *game);
void	load_img(t_game *game);
int		handle_key_press(int keycode, t_game *game);
int		close_window(t_game *game);
void	free_exit(t_game *game);
void	free_sprites(t_game *game);
void	calculate_map_dimensions(const char *filename, t_game *game);
void	read_map(const char *filename, t_game *game);
void	find_player(t_game *game);
void	count_collectibles(t_game *game);
void	load_img(t_game *game);
void	iterate_through_map(t_game *game);
void	put_tile(t_game *game, int width, int height);
void	put_player_and_exit(t_game *game, int width, int height);
int		map_check(t_game *game);
void	flood_fill(char **map, int p_x, int p_y, t_game *game);
void	count_collectibles(t_game *game);
void	find_player(t_game *game);
int		element_check(t_game *game);
void	check_path_right_and_left(char **map, int p_x, int p_y, t_game *game);
void	check_path_up_and_down(char **map, int p_x, int p_y, t_game *game);
void	count_elements(t_game *game, int *collectible, int *exit, int *player);
int		is_ber_file(const char *filename);

void	press_key(int keycode, t_game *game);
void	which_key(int keycode, int *x, int *y);
void	open_exit(t_game *game);
void	free_map(t_game *game, int flag);
int		check_valid_path(t_game *game);
void	print_error_message(t_game *game);
void	move_player(t_game *game, int new_player_x, int new_player_y);
void	count_moves(t_game *game, int x, int y);
int		check_path(char **map, int p_x, int p_y, t_game *game);
#endif
