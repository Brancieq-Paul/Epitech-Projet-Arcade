/*
** EPITECH PROJECT, 2021
** B-OOP-400-RUN-4-1-arcade-paul.brancieq
** File description:
** tests
*/

#include <iostream>
#include "myAssert.hpp"

void testsgraph(std::string lib);
void testncurse(void);
void testsdl(void);
void testsfml(void);

int main(void)
{
    std::cout << std::endl << "TEST ALL" << std::endl;
    std::cout << std::endl << "sdl" << std::endl;
    testsgraph("./lib/arcade_sdl2.so");
    std::cout << std::endl << "ncurse" << std::endl;
    testsgraph("./lib/arcade_ncurses.so");
    std::cout << std::endl << "sfml" << std::endl;
    testsgraph("./lib/arcade_sfml.so");
    std::cout << std::endl << "TEST CUSTOM" << std::endl;
    testncurse();
    testsdl();
    testsfml();
    myTests::Assert().finalExit();
}