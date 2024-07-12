# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achivela <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/09 15:16:35 by achivela          #+#    #+#              #
#    Updated: 2024/07/09 15:16:38 by achivela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

IS		= ./is/
MEM		= ./mem/
PRINT	= ./print/
PRINTF	= ./printf/
STRING	= ./string/
CONVERT	= ./convert/
		
FLAGS		= -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(IS)*.c $(MEM)*.c $(PRINT)*.c $(PRINTF)*.c $(STRING)*.c $(CONVERT)*.c -I ./
	ar rc $(NAME) *.o

run: 
	gcc $(FLAGS) -c $(IS)*.c $(MEM)*.c $(PRINT)*.c $(PRINTF)*.c $(STRING)*.c $(CONVERT)*.c main.c -I ./
	gcc *.o -o app
	rm -f *.o

run-f: 
	gcc -c $(IS)*.c $(MEM)*.c $(PRINT)*.c $(PRINTF)*.c $(STRING)*.c $(CONVERT)*.c main.c -I ./
	gcc *.o -o app
	rm -f *.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
