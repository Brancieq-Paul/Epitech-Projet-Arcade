##
## EPITECH PROJECT, 2021
## B-OOP-400-RUN-4-1-arcade-paul.brancieq
## File description:
## Makefile
##

INC = -I./ -I./../include -I../wdlopen/include
SRC = *.cpp ../wdlopen/*.cpp ../sprites/*.cpp
EXEC = ../arcade

all:
	g++ $(SRC) $(INC) -ldl -o $(EXEC) -g -g3 -ggdb

clean:
	rm -f $(EXEC)

fclean:
	make clean