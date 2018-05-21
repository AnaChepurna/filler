CC = gcc
CFLAG = -Wall -Wextra -Werror
NAME = ../visual
INCL = visualizer.h
SRC = main.c \
		parse.c \
		terminal.c
OBJ = $(SRC:.c=.o)
LIB = ../libft/libft.a

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CC) $(OBJ) ../libft/libft.a -o $(NAME) -ltermcap

%.o: %.c $(INCL)
	$(CC) -c $(CFLAG) $< -o $@

clean:
	make -C ../libft/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C ../libft/ fclean
	rm -rf $(NAME)

$(LIB):
	make -C ../libft re

re: fclean all
