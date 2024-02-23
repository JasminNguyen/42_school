# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 15:10:59 by jasnguye          #+#    #+#              #
#    Updated: 2024/02/23 16:57:17 by jasnguye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c \
libraries/libft_utils/ft_lstadd_back.c \
libraries/libft_utils/ft_lstlast.c	\
libraries/libft_utils/ft_lstnew.c	\
libraries/libft_utils/ft_split.c	\
libraries/libft_utils/ft_atoi.c	\
libraries/libft_utils/ft_strlen.c	\
src/check_input.c \
src/parsing.c \
#src/free.c \



OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror 
AR = ar rcs

NAME = push_swap

all: $(NAME)
$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS) 

clean:
	rm -f $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

