/*
** EPITECH PROJECT, 2021
** B-OOP-400-RUN-4-1-arcade-paul.brancieq
** File description:
** main
*/

#include <dlfcn.h>
#include <stdio.h>
#include <cstdlib>
#include <assert.h>
#include "IGraphApi.hpp"
#include "Wdlopen.hpp"

// int mainqslkhdqsjk(int argc, char **argv)
// {
//     auto symbolsGraph = Wdlopen("./lib/arcade_sfml.so");
//     void *windows;

//     arcade::GraphApiCreate *myfunc = (arcade::GraphApiCreate *)symbolsGraph.fetchFunc("APIMake");
//     arcade::GraphApiDelete *myfuncdelete = (arcade::GraphApiDelete *)symbolsGraph.fetchFunc("APIDestroy");

//     // Exécution de la fonction "func"

//     arcade::IGraphApi *mytest = myfunc();

//     windows = mytest->initWindow(1500, 1500, "Haachama");
//     std::cout << "TEST" << std::endl;
//     // mytest->createSprite("CARRE", "tests/testsRessources/clean/carré.png");
//     // mytest->createAudio("AUDIO", "tests/testsRessources/clean/game.ogg");
//     // mytest->posSprite("CARRE", 50, 50);
//     while (1) {
//         // mytest->playAudio("CARRE", "LOL");
//         // mytest->displaySprite("CARRE");
//         mytest->refreshWindow(windows);
//     }

//     myfuncdelete(mytest);

//     return EXIT_SUCCESS;
// }