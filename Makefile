# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achepurn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/21 21:48:41 by achepurn          #+#    #+#              #
#    Updated: 2018/03/21 21:48:44 by achepurn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAG = -Wall -Wextra -Werror
NAME = achepurn.filler
INCL = filler.h
SRC_DIR = src/
FILES = main.c \
		parse.c \
		memory.c \
		analyze.c \
		algorythm1.c \
		algorythm2.c
SRC = $(addprefix $(SRC_DIR), $(FILES))
OBJ = $(SRC:.c=.o)
LIB = libft/libft.a

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CC) $(OBJ) libft/libft.a -o $(NAME)

%.o: %.c $(INCL)
	$(CC) -c $(CFLAG) $< -o $@

clean:
	make -C libft/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

$(LIB):
	make -C libft re

re: fclean all
