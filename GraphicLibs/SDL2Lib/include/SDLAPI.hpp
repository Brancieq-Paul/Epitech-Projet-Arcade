/*
** EPITECH PROJECT, 2021
** B-OOP-400-RUN-4-1-arcade-paul.brancieq
** File description:
** Testncurse
*/

#include <iostream>
#include "AGraphApi.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#pragma once

using namespace arcade;

class SDL2API : public arcade::AGraphApi
{
public:
    SDL2API() {};
    ~SDL2API() {};

    myWindow_t *initWindow(int height, int width, std::string name) override;
    void refreshCalledWindow(SDL_Window *window, SDL_Renderer *renderer);
    void refreshWindow(myWindow_t *window) override;
    void destroyCalledWindow(SDL_Window *window, SDL_Renderer *renderer);
    void destroyWindow(myWindow_t *window) override;

    void *createCalledSprite(std::string file, SDL_Renderer *renderer);
    void *createSprite(std::string file, myWindow_t *window) override;
    void displayCalledSprite(SDL_Texture *texture, SDL_Renderer *renderer, pos_t pos);
    void displaySprite(mySprite *entity, myWindow_t *window) override;
    void destroyCalledSprite(SDL_Texture *texture);
    void destroySprite(mySprite *entity) override;


    bindings pollCalledEvents(SDL_Window *window);
    bindings pollEvents(myWindow_t *win) override;

    void *createAudio(std::string file) override;
    void playAudio(void *audio) override;
    void stopAudio(void *audio) override;
    void destroyAudio(void *audio) override;

    void *createText(std::string file) override;
    void *setCalledText(SDL_Surface *text, std::string value);
    void *setText(void *text, std::string value) override;
    void displayCalledText(SDL_Surface *surface, SDL_Renderer *renderer, pos_t pos);
    void displayText(void *text, myWindow_t *window, pos_t offset) override;
    void destroyCalledText(SDL_Surface *text);
    void destroyText(void *text) override;

};
