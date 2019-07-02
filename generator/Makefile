##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## My Makefile
##

SRC_DIR =	./src

INC_DIR =	./inc

CFLAGS = -Wall -Wextra -I $(INC_DIR) -g

SRC	=	src/generator.c	\
		src/main.c		\
		src/algo.c		\
		inc/my_putchar.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	generator

all:	build

build:	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
