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
#include "IGameApi.hpp"
#include "Wdlopen.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;
    auto graphSymbols = Wdlopen(argv[1]);
    auto gameSymbols = Wdlopen("./lib/arcade_pacman.so");

    arcade::GraphApiCreate *myfunc = (arcade::GraphApiCreate *)graphSymbols.fetchFunc("APIMake");
    arcade::GraphApiDelete *myfuncdelete = (arcade::GraphApiDelete *)graphSymbols.fetchFunc("APIDestroy");

    arcade::IGameApiCreate *myfuncgraph = (arcade::IGameApiCreate *)gameSymbols.fetchFunc("APIMake");
    arcade::IGameApiDelete *myfuncgraphdelete = (arcade::IGameApiDelete *)gameSymbols.fetchFunc("APIDestroy");

    arcade::IGraphApi *mytest = myfunc();
    arcade::IGameApi *mygraph = myfuncgraph();

    mygraph->initGraphApi(mytest);
    mygraph->example();

    myfuncdelete(mytest);
    myfuncgraphdelete(mygraph);
 
    return EXIT_SUCCESS;
}