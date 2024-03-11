# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 15:10:59 by jasnguye          #+#    #+#              #
#    Updated: 2024/03/11 14:40:09 by jasnguye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c \
libraries/libft_utils/ft_lstadd_back.c \
libraries/libft_utils/ft_lstlast.c	\
libraries/libft_utils/ft_lstnew.c	\
libraries/libft_utils/ft_lstsize.c	\
libraries/libft_utils/ft_split.c	\
libraries/libft_utils/ft_atol.c	\
libraries/libft_utils/ft_strlen.c	\
libraries/libft_utils/ft_isdigit.c	\
libraries/libft_utils/ft_calloc.c	\
src/check_input.c \
src/parsing.c \
src/sort_three.c \
src/turk_algorithm.c \
src/turk_utils1.c \
src/turk_utils2.c \
src/turk_utils3.c \
src/commands/rev_rotate.c \
src/commands/push.c \
src/commands/swap.c \
src/commands/rotate.c \
src/free.c \

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
AR = ar rcs

NAME = push_swap

all: $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C libraries/ft_printf
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libraries/ft_printf/*.o

clean:
	rm -f $(OBJS)
	 $(MAKE) -C libraries/ft_printf clean

fclean: clean
	$(RM) $(NAME)
	 $(MAKE) -C libraries/ft_printf fclean

re: fclean all

.PHONY: all clean fclean re

