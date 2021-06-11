##
## EPITECH PROJECT, 2021
## B-OOP-400-RUN-4-1-arcade-paul.brancieq
## File description:
## Makefile
##

all:
	make compil_ncurse
	make compil_SDL2
	make compil_SFML

compil_ncurse:
	make -C ./NcurseLib
	cp ./NcurseLib/arcade_ncurses.so ../lib/arcade_ncurses.so

compil_SDL2:
	make -C ./SDL2Lib
	cp ./SDL2Lib/arcade_sdl2.so ../lib/arcade_sdl2.so

compil_SFML:
	make -C ./SFMLLib
	cp ./SFMLLib/arcade_sfml.so ../lib/arcade_sfml.so

clean:
	make clean -C ./NcurseLib
	make clean -C ./SFMLLib
	make clean -C ./SDL2Lib

fclean:
	make fclean -C ./NcurseLib
	make fclean -C ./SDL2Lib
	make fclean -C ./SFMLLib