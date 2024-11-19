# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 16:08:35 by jasnguye          #+#    #+#              #
#    Updated: 2024/11/19 17:52:51 by jasnguye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g 


NAME = zombie

SRCS	=	main.cpp Zombie.cpp newZombie.cpp randomChump.cpp \
			
OBJS	=	$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME): $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
clean:
			rm -rf $(OBJS)
			
fclean:		clean
			rm -rf $(NAME)
			
re:			fclean all

.PHONY: all clean fclean re