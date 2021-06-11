/*
** EPITECH PROJECT, 2021
** B-OOP-400-RUN-4-1-arcade-paul.brancieq
** File description:
** Testncurse
*/

#include <iostream>
#include "AGraphApi.hpp"
#include "Window.hpp"
#include <memory>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>

#pragma once

using namespace arcade;

class NcurseAPI : public arcade::AGraphApi
{
public:
    NcurseAPI() {};
    ~NcurseAPI() {};

    //Window:

    myWindow_t *initWindow(int height, int width, std::string name) override;
    void destroyWindow(myWindow_t *w) override;
    void refreshWindow(myWindow_t *w) override;

    //Sprite:

    void *createSprite(std::string file, myWindow_t *Window) override;
    void displaySprite(mySprite *entity, myWindow_t *Window) override;
    void destroySprite(mySprite *entity) override;

    //Audio:

    void *createAudio(std::string file) override {return 0;};
    void playAudio(void *audio) override {return;};
    void stopAudio(void *audio) override {return;};
    void destroyAudio(void *audio) override {return;};

    //text
    void *createText(std::string file) override;
    void *setText(void *text, std::string value);
    void displayText(void *text, myWindow_t *window, pos_t offset) override;
    void destroyText(void *text) override;
    //Event:
    bindings pollEvents(myWindow_t *win) override;
};
