##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

CFLAGS =	-W -Wall -Wextra

SRC =		src/main.c		\
		src/get_file.c		\
		src/my_put.c		\
		src/my_putw.c		\
		src/check_error.c	\
		src/my_sokoban.c	\
		src/coord_o.c		\
		src/coord_x.c		\
		src/move.c		\
		src/move_re.c		\
		src/win_lose.c		\
		src/fct.c

OBJ =		$(SRC:.c=.o)

NAME =		my_sokoban

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS) -lncurses

clean:
		$(RM) $(OBJ)
		make -C tests/ clean

fclean:		clean
		$(RM) $(NAME)
		make -C tests/ fclean

re:		fclean all

tests_run:	clean fclean
		make -C tests/ re

.PHONY:		re fclean clean all
