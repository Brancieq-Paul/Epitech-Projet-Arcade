/*
** EPITECH PROJECT, 2021
** B-OOP-400-RUN-4-1-arcade-paul.brancieq
** File description:
** main
*/

#include <dlfcn.h>
#include <stdio.h>
#include <cstdlib>
#include "IGraphApi.hpp"
#include "Wdlopen.hpp"
#include "myAssert.hpp"

using namespace myTests;

void testsncurselist(arcade::IGraphApi *mytest)
{
    //Assert("Ncurse", "Example test", "If you see this your are bad", mytest->example() == 0);

    //Add all your custom tests
}

void testncurse(void)
{
    auto symbolsGraph = Wdlopen("./lib/arcade_ncurses.so");

    arcade::IGraphApi *(*funccreate)(void) = (arcade::IGraphApi *(*)(void))symbolsGraph.fetchFunc("GraphApiCreate");
    void (*funcdelete)(arcade::IGraphApi *) = (void (*)(arcade::IGraphApi *))symbolsGraph.fetchFunc("GraphApiDelete");

    arcade::IGraphApi *mytest = funccreate();
    testsncurselist(mytest);
    funcdelete(mytest);

    return;
}