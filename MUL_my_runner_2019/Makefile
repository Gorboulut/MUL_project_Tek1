##
## EPITECH PROJECT, 2019
## myhunter
## File description:
## makefile
##

SRC	=	main.c	\
			helper.c	\
			init_struct.c		\
			manage_backg.c	\
			map_sprite.c	\
			map_manage.c	\
			check_hit.c	\
			menu_management.c	\

OBJ 	=	$(SRC:.c=.o)

CFLAGS	=	-lcsfml-audio -lcsfml-graphics -lcsfml-system -lcsfml-window

CFLAGS2 =	-W -Wall -Wextra -lmy -L./lib/my -I./include

NAME	=	my_runner

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
