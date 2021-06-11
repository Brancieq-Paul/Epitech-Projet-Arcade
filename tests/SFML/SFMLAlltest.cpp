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
using namespace arcade;


void testslistsfml(arcade::IGraphApi *mytest)
{
    //Assert("SFML", "Example test", "If you see this your are bad", mytest->example() == 0);
    myWindow_t *windows = new myWindow_t;
    mySprite *Sprite = new mySprite;

    Sprite->setPosMySprite((pos_t){500, 600});
    Sprite->setSprite(mytest->createSprite("tests/testsRessources/clean/carré", windows));

    void *audio = mytest->createAudio("tests/testsRessources/clean/game.ogg");
    void *text = mytest->createText("TOTO");

    windows = mytest->initWindow(1500, 1500, "Haachama");
    bindings event = UNKNOWN;
        mytest->playAudio(audio);
    while (event != DEL) {
        event = mytest->pollEvents(windows);

        if (event == UP) {
            mytest->playAudio(audio);
        }
        else if (event == DOWN)
            mytest->stopAudio(audio);
        else if (event == EXIT_ALL)
            exit(0);
        else if (event == LEFT) {
            Sprite->setPosMySprite((pos_t){Sprite->getPosSprite().x + 20, Sprite->getPosSprite().y});
        } else if (event == O) {
            text = mytest->setText(text, "AZERTY");
        }
        mytest->displaySprite(Sprite, windows);
        mytest->displayText(text, windows, (pos_t){100, 900});
        mytest->refreshWindow(windows);
    }
    mytest->destroyWindow(windows);
    mytest->destroySprite(Sprite);
    mytest->destroyAudio(audio);
    mytest->destroyText(text);
    //Add all your custom tests
}

void testsfml(void)
{
    auto symbolsGraph = Wdlopen("./lib/arcade_sfml.so");

    arcade::IGraphApi *(*funccreate)(void) = (arcade::IGraphApi *(*)(void))symbolsGraph.fetchFunc("GraphApiCreate");
    void (*funcdelete)(arcade::IGraphApi *) = (void (*)(arcade::IGraphApi *))symbolsGraph.fetchFunc("GraphApiDelete");

    arcade::IGraphApi *mytest = funccreate();
    testslistsfml(mytest);
    funcdelete(mytest);
    return;
}