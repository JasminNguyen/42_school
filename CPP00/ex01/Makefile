# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 12:09:03 by jasnguye          #+#    #+#              #
#    Updated: 2024/11/13 17:40:49 by jasnguye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g 


NAME = phonebook

SRCS	=	PhoneBook.cpp Contact.cpp \
			
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