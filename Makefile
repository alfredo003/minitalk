# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achivela <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 16:09:11 by achivela          #+#    #+#              #
#    Updated: 2024/07/10 16:09:16 by achivela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minitalk

IS		= ./libs/is/
MEM		= ./libs/mem/
PRINT	= ./libs/print/
PRINTF	= ./libs/printf/
STRING	= ./libs/string/
CONVERT	= ./libs/convert/

USER = client
SERV = server
USER_BONUS = client_bonus
SERV_BONUS = server_bonus
FLAGS	= -Wall -Werror -Wextra


all:$(NAME)

bonus:
	cc $(FLAGS) -o $(SERV_BONUS) $(SERV_BONUS).c $(IS)*.c $(MEM)*.c $(PRINT)*.c $(PRINTF)*.c $(STRING)*.c $(CONVERT)*.c utils.c -I ./libs/
	clear
	cc $(FLAGS) -o $(USER_BONUS) $(USER_BONUS).c $(IS)*.c $(MEM)*.c $(PRINT)*.c $(PRINTF)*.c $(STRING)*.c $(CONVERT)*.c utils.c -I ./libs/
	clear
	
$(NAME):
	cc $(FLAGS) -o $(SERV) $(SERV).c $(IS)*.c $(MEM)*.c $(PRINT)*.c $(PRINTF)*.c $(STRING)*.c $(CONVERT)*.c utils.c -I ./libs/
	clear
	cc $(FLAGS) -o $(USER) $(USER).c $(IS)*.c $(MEM)*.c $(PRINT)*.c $(PRINTF)*.c $(STRING)*.c $(CONVERT)*.c utils.c -I ./libs/
	clear
clean:
	rm -rf $(SERV) $(USER)
	clear

re: fclean all
