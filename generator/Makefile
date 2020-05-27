
##
## EPITECH PROJECT, 2019
## mf
## File description:
## mf
##

SRC	=	src/begin_maze.c	\
		src/imperfect_map.c	\
		src/setting_maze.c	\
		src/checking_maze.c		\
		src/set_maze.c	\
		src/my_strcmp.c	\
		src/my_str_is_num.c 	\

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

DEBUG	=	-g3

CFLAGS	=	-W -Wextra

CPPFLAGS	=	-I include/

NAME	=	generator

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(DEBUG) $(SRC) $(CPPFLAGS)

clean:
	rm -f $(OBJ)
	rm -f vg*
	rm -f *~

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re