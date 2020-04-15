##
## EPITECH PROJECT, 2019
## myhunter
## File description:
## makefile
##

SRC	=	main.c	\
		manage_font.c	\
		init_strc.c	\
		manage_click.c	\
		manage_life.c	\
		help.c	\

OBJ 	=	$(SRC:.c=.o)

CFLAGS	=	-lcsfml-audio -lcsfml-graphics -lcsfml-system -lcsfml-window

CFLAGS2 =	-W -Wall -Wextra -lmy -L./lib/my -I./include

NAME	=	my_hunter

all:	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(CFLAGS2)
	rm $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f *~ \#*\#

fclean:	clean
	rm -f $(NAME)

re:	fclean	all

