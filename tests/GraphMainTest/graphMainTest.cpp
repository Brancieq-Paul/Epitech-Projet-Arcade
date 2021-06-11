/*
** EPITECH PROJECT, 2021
** B-OOP-400-RUN-4-1-arcade-paul.brancieq
** File description:
** graphMainTest
*/

#include <dlfcn.h>
#include <stdio.h>
#include <cstdlib>

#include "IGraphApi.hpp"
#include "Wdlopen.hpp"
#include "myAssert.hpp"
#include "IArcadeError.hpp"

using namespace myTests;

void testslistgraph(arcade::IGraphApi *mytest)
{
    bool var = true;
    arcade::myWindow_t *window;

    try {
        window = mytest->initWindow(600, 600, "Test");
    } catch (arcade::ArcadeError &e) {
        var = false;
        std::cout << e.where() << ": " << e.what() << std::endl;
    } catch (...) {
        var = false;
        std::cout << "Uknown throw" << std::endl;
    }
    Assert("Windows", "create", "Echec window create", var);
    var = true;

    try {
        mytest->refreshWindow(window);
    } catch (arcade::ArcadeError &e) {
        var = false;
        std::cout << e.where() << ": " << e.what();
    } catch (...) {
        var = false;
        std::cout << "Uknown throw" << std::endl;
    }
    Assert("Windows", "refresh", "Echec window refresh", var);
    var = true;

    try {
        mytest->destroyWindow(window);
    } catch (arcade::ArcadeError &e) {
        var = false;
        std::cout << e.where() << ": " << e.what();
    } catch (...) {
        var = false;
        std::cout << "Uknown throw" << std::endl;
    }
    Assert("Windows", "destroy", "Echec window destroy", var);
    var = true;
}

void testsgraph(std::string lib)
{
    auto graphSymbols = Wdlopen(lib);

    arcade::IGraphApi *(*myfunc)(void) = (arcade::IGraphApi *(*)(void))graphSymbols.fetchFunc("GraphApiCreate");
    void (*myfuncdelete)(arcade::IGraphApi *) = (void (*)(arcade::IGraphApi *))graphSymbols.fetchFunc("GraphApiDelete");

    arcade::IGraphApi *mytest = myfunc();
    testslistgraph(mytest);
    myfuncdelete(mytest);
    return;
}