# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/04 13:01:33 by jasnguye          #+#    #+#              #
#    Updated: 2024/06/25 15:25:17 by jasnguye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   philo
CC      =   cc
CFLAGS  =   -Wall -Werror -Wextra -Imlx -g

SRCS	=	philo.c utils.c \
			init.c utils2.c \
			monitor_routine.c philo_routine.c
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


