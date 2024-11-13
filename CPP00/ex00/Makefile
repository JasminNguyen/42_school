# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 15:48:39 by jasnguye          #+#    #+#              #
#    Updated: 2024/11/12 12:08:34 by jasnguye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g 


NAME = megaphone

SRCS	=	megaphone.cpp \
			
OBJS	=	$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME): $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			rm -rf $(OBJS)
			
fclean:		clean
			rm -rf $(NAME)
			
re:			fclean all

.PHONY: all clean fclean re