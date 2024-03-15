# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jasnguye <jasnguye@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 16:27:44 by jasnguye          #+#    #+#              #
#    Updated: 2024/03/15 14:34:13 by jasnguye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_CLIENT = client.c
SRCS_SERVER = server.c

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra -Imlx -g
LIBS = Libft/libft.a

SERVER = server
CLIENT = client

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJS_SERVER)
		$(MAKE) -C Libft
		$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBS) -o $(SERVER)
		
$(CLIENT): $(OBJS_CLIENT)
		$(MAKE) -C Libft
		$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBS) -o $(CLIENT)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C Libft
	rm -rf $(OBJS_CLIENT) $(OBJS_SERVER)

fclean: clean
	rm -rf $(SERVER) $(CLIENT)
	rm -rf $(LIBS)
	
re: fclean all

.PHONY: all clean fclean re
