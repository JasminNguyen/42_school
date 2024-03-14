# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 16:27:44 by jasnguye          #+#    #+#              #
#    Updated: 2024/03/14 17:40:01 by jasnguye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = server.c	\
client.c	\

LIBS = libraries/Libft/libft.a \

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror 
AR = ar rcs

NAME = minitalk
all:		$(NAME)

$(NAME): $(OBJS)
			make -C ./libraries/Libft
			$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
			
clean:
	rm -f $(OBJS)
	make clean -C ./libraries/Libft

fclean: clean
	$(RM) $(NAME)
	rm -rf $(NAME) $(LIBS)

re: fclean all

.PHONY: all clean fclean re