##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =		my_put.c		\
		coord_o.c		\
		coord_x.c		\
		move.c			\
		move_re.c		\
		win_lose.c		\
		fct.c

SRC_TEST =      soko_tests.c

GCOVR_FLAG =    --exclude

TEST_FLAGS =    --coverage -lcriterion

NAME =          unit_tests

all:            $(NAME)

$(NAME):
		mv ../src/*.c ./
		gcc     -o      $(NAME) $(SRC) $(SRC_TEST) $(TEST_FLAGS)
		./$(NAME)
		gcovr $(GCOVR_FLAG) $(SRC_TEST)
		gcovr $(GCOVR_FLAG) $(SRC_TEST) -b
		mv *.c ../src/
		mv ../src/$(SRC_TEST) ./

clean:
		rm -f *.gcno
		rm -f *.gcda

fclean:         clean
		rm -f $(NAME)

re:             fclean all

.PHONY:         re fclean clean all
