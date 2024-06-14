# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/04 13:01:33 by jasnguye          #+#    #+#              #
#    Updated: 2024/06/04 13:04:07 by jasnguye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   philo
CC      =   cc
CFLAGS  =   -Wall -Werror -Wextra -Imlx -g

SRCS	=	philo.c utils.c
OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME): $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			rm -rf $(OBJS)
			
fclean:		clean
			rm -rf $(NAME)
			
re:			fclean all

.PHONY: all clean fclean re


