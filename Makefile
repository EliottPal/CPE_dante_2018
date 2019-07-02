##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## My Makefile
##

GENERATOR_DIR	=	$(realpath ./generator/)

SOLVER_DIR =	$(realpath ./solver/)

OBJ	=	$(SRC:.c=.o)

all:		build

build:		$(OBJ)
		$(MAKE) -C $(GENERATOR_DIR)
		$(MAKE) -C $(SOLVER_DIR)

clean:
		$(MAKE) -C $(GENERATOR_DIR) fclean
		$(MAKE) -C $(SOLVER_DIR) fclean
		rm -f $(OBJ)
		rm -f *~
		rm -f vgcore*

fclean:		clean
		$(MAKE) -C $(GENERATOR_DIR) fclean
		$(MAKE) -C $(SOLVER_DIR) fclean
		rm -f *~
		rm -f vgcore*

re:		fclean all

.PHONY:		make clean fclean re
