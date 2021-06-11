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

void testslistsdl(arcade::IGraphApi *mytest)
{
    //Assert("SDL", "Example test", "If you see this your are bad", mytest->example() == 0);
    myWindow_t *windows = new myWindow_t;
    mySprite *Sprite = new mySprite;
    mySprite *Sprite2 = new mySprite;
    windows = mytest->initWindow(1500, 1500, "Haachama");

    Sprite->setPosMySprite((pos_t){500, 600});
    Sprite2->setPosMySprite((pos_t){900, 900});
    Sprite->setSprite(mytest->createSprite("tests/testsRessources/clean/player", windows));
    Sprite2->setSprite(mytest->createSprite("tests/testsRessources/clean/player", windows));

    // void *audio = mytest->createAudio("tests/testsRessources/clean/game.ogg");
    void *text = mytest->createText("TOTO");

    bindings event = UNKNOWN;
    //     mytest->playAudio(audio);
    while (event != DEL) {
        event = mytest->pollEvents(windows);

        // if (event == UP) {
        //     mytest->playAudio(audio);
        // }
        // else if (event == DOWN)
        //     mytest->stopAudio(audio);
        // else if (event == EXIT_ALL)
        //     exit(0);
        // else if (event == LEFT) {
        //     Sprite->setPosMySprite((pos_t){Sprite->getPosSprite().x + 20, Sprite->getPosSprite().y});
        if (event == O) {
            text = mytest->setText(text, "AZERTY");
        }
        mytest->displaySprite(Sprite, windows);
        mytest->displaySprite(Sprite2, windows);
        mytest->displayText(text, windows, (pos_t){100, 200});
        mytest->refreshWindow(windows);
    }
    mytest->destroyWindow(windows);
    mytest->destroySprite(Sprite);
    mytest->destroySprite(Sprite2);
    // mytest->destroyAudio(audio);
    mytest->destroyText(text);

    //Add all your custom tests
}

void testsdl(void)
{
    auto symbolsGraph = Wdlopen("./lib/arcade_sdl2.so");

    arcade::IGraphApi *(*funccreate)(void) = (arcade::IGraphApi *(*)(void))symbolsGraph.fetchFunc("GraphApiCreate");
    void (*funcdelete)(arcade::IGraphApi *) = (void (*)(arcade::IGraphApi *))symbolsGraph.fetchFunc("GraphApiDelete");

    arcade::IGraphApi *mytest = funccreate();
    testslistsdl(mytest);
    funcdelete(mytest);

    return;
}