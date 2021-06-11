/*
** EPITECH PROJECT, 2021
** B-OOP-400-RUN-4-1-arcade-paul.brancieq
** File description:
** Testncurse
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include "IArcadeError.hpp"
#include "IGraphApi.hpp"
#include "AGraphApi.hpp"

#pragma once

using namespace arcade;

class SFMLAPI : public arcade::AGraphApi
{
public:
    SFMLAPI(){};
    ~SFMLAPI(){};

    myWindow_t *initWindow(int height, int width, std::string name) override;
    void refreshWindow(myWindow_t *window) override;
    void refreshCalledWindow(sf::RenderWindow *window);
    void destroyWindow(myWindow_t *window) override;
    void destroyCalledWindow(sf::RenderWindow *window);

    bindings pollCalledEvents(sf::RenderWindow *window);
    bindings pollEvents(myWindow_t *window) override;

    void *createSprite(std::string file, myWindow_t *window) override;
    void destroyCalledSprite(sf::Sprite *sprite);
    void destroySprite(mySprite *entity) override;
    void displaySprite(mySprite *entity, myWindow_t *windows) override;
    void displayCalledSprite(sf::Sprite *sprite, sf::RenderWindow *windows);
    void setPosSprite(mySprite *entity, sf::Sprite *sprite);

    void *createText(std::string file) override;
    void setPosText(sf::Text *, pos_t offset);
    void displayCalledText(sf::Text *text, sf::RenderWindow *window);
    void displayText(void *text, myWindow_t *window, pos_t offset) override;
    void destroyCalledText(sf::Text *text);
    void destroyText(void *text) override;
    void *setText(void *text, std::string value) override;
    void *setCalledText(sf::Text *text, std::string value);


    void *createAudio(std::string file) override;
    void playCalledAudio(sf::Music *audio);
    void playAudio(void *audio) override;
    void stopCalledAudio(sf::Music *audio);
    void stopAudio(void *audio) override;
    void destroyCalledAudio(sf::Music *audio);
    void destroyAudio(void *audio) override;
};
