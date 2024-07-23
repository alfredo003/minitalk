# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achivela <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 16:09:11 by achivela          #+#    #+#              #
#    Updated: 2024/07/23 17:18:26 by achivela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
IS_DIR = ./libs/is/
MEM_DIR = ./libs/mem/
PRINT_DIR = ./libs/print/
PRINTF_DIR = ./libs/printf/
STRING_DIR = ./libs/string/
CONVERT_DIR = ./libs/convert/
INCLUDE_DIR = ./libs/
FLAGS = -Wall -Werror -Wextra
SERVER =server
CLIENT = client

SERVER_BONUS =server_bonus
CLIENT_BONUS = client_bonus

UTILS = utils.c
LIB_SRCS = $(wildcard $(IS_DIR)*.c $(MEM_DIR)*.c $(PRINT_DIR)*.c $(PRINTF_DIR)*.c $(STRING_DIR)*.c $(CONVERT_DIR)*.c)
INCLUDES = -I $(INCLUDE_DIR)

all: server client

server: server.c $(LIB_SRCS) $(UTILS)
	cc $(FLAGS) -o server server.c $(LIB_SRCS) $(UTILS) $(INCLUDES)

client: client.c $(LIB_SRCS) $(UTILS)
	cc $(FLAGS) -o client client.c $(LIB_SRCS) $(UTILS) $(INCLUDES)

bonus: server_bonus client_bonus

server_bonus: server_bonus.c $(LIB_SRCS) $(UTILS)
	cc $(FLAGS) -o server_bonus server_bonus.c $(LIB_SRCS) $(UTILS) $(INCLUDES)

client_bonus: client_bonus.c $(LIB_SRCS) $(UTILS)
	cc $(FLAGS) -o client_bonus client_bonus.c $(LIB_SRCS) $(UTILS) $(INCLUDES)

clean:
	rm -f *.o

fclean: clean 
	rm -rf $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS) 

re: clean all

.PHONY: all bonus clean re
