##
## EPITECH PROJECT, 2021
## B-OOP-400-RUN-4-1-arcade-paul.brancieq
## File description:
## Makefile
##

NAME		=	arcade_ncurses.so

SRC		=	$(wildcard *.cpp)	\
			../../sprites/sprite.cpp

OBJ		=	$(SRC:.cpp=.o)

INC		=	-I./include/ -I../../include -I../

CFLAGS		+=	-W -Wall -Wextra -std=gnu99 -Ofast $(INC)

LDFLAGS		+=	-fPIC -shared

RM		=	rm -f

all:			$(NAME)

%.o: %.cpp
	g++ -c $< -o $@ -fPIC $(INC) -lncurses

$(NAME):		$(OBJ)
			$(CC) $(LDFLAGS) $(OBJ) -o $(NAME) $(INC) -lncurses

clean:
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			clean fclean all re
