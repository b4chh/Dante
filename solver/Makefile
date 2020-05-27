##
## EPITECH PROJECT, 2019
## mf
## File description:
## mf
##

SRC 	=	main.c	\
			solver.c	\
			my_strlen.c	\
			my_putchar.c	\
			my_str_to_word_array.c	\
			depth_first_search.c	\
			limit_move.c	\
			find_path.c	\

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

CFLAGS	=	-W -Wextra

CPPFLAGS	=	-I include/

NAME	=	solver

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) -g3 $(SRC)

clean:
	rm -f $(OBJ)
	rm -f vg*
	rm -f *~

fclean:	clean
	rm -f  $(NAME)

re:	fclean all

.PHONY: all clean fclean re
