##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## My Makefile
##

SRC_DIR =	./src

INC_DIR =	./inc

CFLAGS = -Wall -Wextra -I $(INC_DIR) -g

SRC	=	src/solver.c	\
		src/maze.c	\
		src/recursive.c	\
		src/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	solver

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
