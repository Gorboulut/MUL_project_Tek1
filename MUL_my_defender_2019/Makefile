##
## EPITECH PROJECT, 2019
## CPool_Day12_2019
## File description:
## Makefile
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	my_defender

CFLAGS	=	-g

all:	$(NAME)

$(NAME):	$(SRC)
	$(CC) $(SRC) -o $(NAME) -g -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
