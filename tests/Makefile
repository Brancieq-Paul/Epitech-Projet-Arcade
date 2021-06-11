##
## EPITECH PROJECT, 2021
## B-OOP-400-RUN-4-1-arcade-paul.brancieq
## File description:
## Makefile
##

INC = -I../wdlopen/include/ -I../include/ -I./myAssert/ -I../GraphicLibs/NcurseLib/include -I../GraphicLibs/SDL2Lib/include -I../GraphicLibs/SFMLLib/include
USE = ./myAssert/*.cpp ../wdlopen/*.cpp Ncurse/*.cpp SDL/*.cpp SFML/*.cpp GraphMainTest/*.cpp ./*.cpp ../sprites/*.cpp

all:
	#make compilncurse
	#make compilSDL
	# make compilSFML
	#make compilNibbler
	#make compilPacman
	make compiltests

compilNibbler:
	g++ -I../GameLibs/NibblerLib/include $(INC) Nibbler/*.cpp $(USE) -ldl -g -g3 -ggdb -o testNibbler

compilPacman:
	g++ -I../GameLibs/PacmanLib/include $(INC) Pacman/*.cpp $(USE) -ldl -g -g3 -ggdb -o testPacman

compiltests:
	g++ $(INC) $(USE) -ldl -g -g3 -ggdb -o tests -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lm -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf

clean:
	rm -f *.o

fclean:
	make clean
	rm  -f testncurse
	rm -f testSDL
	rm -f testSFML
	rm -f testNibbler
	rm -f testPacman
	rm -f ./tests