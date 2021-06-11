##
## EPITECH PROJECT, 2021
## B-OOP-400-RUN-4-1-arcade-paul.brancieq
## File description:
## Makefile
##


##ALL COMPIL

all:
	make graphicals
	make games
	make core

re:
	make fclean
	make all


#COMPIL ALL GRAPHICAL

graphicals:
	make -C ./GraphicLibs

#COMPIL ALL GAMES

games:
	make -C ./GameLibs

#COMPIL CORE

core:
	make -C ./core

#COMPIL TESTS

tests_runs:
	make graphicals
	make games
	make -C ./tests/

#CLEAN RULES

clean:
	make clean -C ./GraphicLibs

fclean:
	make fclean -C ./GraphicLibs
	make fclean -C ./GameLibs
	make fclean -C ./tests
	make fclean -C ./core
	rm -f ./lib/*

.PHONY: tests tests_runs core games tests_runs graphicals re all