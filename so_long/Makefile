# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 15:37:37 by jasnguye          #+#    #+#              #
#    Updated: 2024/02/06 14:48:03 by jasnguye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   so_long
CC      =   cc
CFLAGS  =   -Wall -Werror -Wextra -Imlx -g
MLXFLAGS=   -L ./libraries/mlx -lmlx -lXext -lX11
LIBS    =    ./libraries/Libft/libft.a

SRCS	=	src/window.c src/images.c src/free.c so_long.c src/read_map.c src/movement.c src/map_check.c
OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME): $(OBJS)
			make -C ./libraries/mlx
			make -C ./libraries/Libft
			$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MLXFLAGS) -o $(NAME)

clean:
			make clean -C ./libraries/mlx
			make clean -C ./libraries/Libft
			rm -rf $(OBJS)
			
fclean:		clean
			rm -rf $(NAME) $(LIBS)
			
re:			fclean all

.PHONY: all clean fclean re


