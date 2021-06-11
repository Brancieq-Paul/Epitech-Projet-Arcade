##
## EPITECH PROJECT, 2021
## B-OOP-400-RUN-4-1-arcade-paul.brancieq
## File description:
## Makefile
##

all:
	make compil_nibbler
	make compil_pacman

compil_nibbler:
	make -C ./Nibbler
	cp ./Nibbler/arcade_nibbler.so ../lib/arcade_nibbler.so

compil_pacman:
	make -C ./Pacman
	cp ./Pacman/arcade_pacman.so ../lib/arcade_pacman.so

clean:
	make clean -C ./Nibbler
	make clean -C ./Pacman

fclean:
	make fclean -C ./Nibbler
	make fclean -C ./Pacman