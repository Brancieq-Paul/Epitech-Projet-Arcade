/*
** EPITECH PROJECT, 2021
** B-OOP-400-RUN-4-1-arcade-paul.brancieq
** File description:
** test
*/

#include <iostream>
#include "IArcadeError.hpp"
#include "IGraphApi.hpp"

#pragma once

namespace arcade
{
    class AGraphApi : public IGraphApi
    {
    public:

        //Window:

        virtual myWindow_t *initWindow(int height, int width, std::string name) override { throw ArcadeError("Function not init", "GraphAPI"); };
        virtual void destroyWindow(myWindow_t *window) override { throw ArcadeError("Function not init", "GraphAPI"); };
        virtual void refreshWindow(myWindow_t *window) override { throw ArcadeError("Function not init", "GraphAPI"); };

        //Sprite:

        virtual void *createSprite(std::string file, myWindow_t *window) override { throw ArcadeError("Function not init", "GraphAPI"); };
        virtual void displaySprite(mySprite *entity, myWindow_t *window) override { throw ArcadeError("Function not init", "GraphAPI"); };
        virtual void destroySprite(mySprite *entity) override { throw ArcadeError("Function not init", "GraphAPI"); };

        //Audio:

        virtual void *createAudio(std::string file) override { throw ArcadeError("Function not init", "GraphAPI"); };
        virtual void playAudio(void *audio) override { throw ArcadeError("Function not init", "GraphAPI"); };
        virtual void stopAudio(void *audio) override { throw ArcadeError("Function not init", "GraphAPI"); };
        virtual void destroyAudio(void *audio) override { throw ArcadeError("Function not init", "GraphAPI"); };

        //text
        virtual void *createText(std::string file) override { throw ArcadeError("Function not init", "GraphAPI"); };
        virtual void *setText(void *text, std::string value) override { throw ArcadeError("Function not init", "GraphAPI"); };
        virtual void displayText(void *text, myWindow_t *window, pos_t offset) override { throw ArcadeError("Function not init", "GraphAPI"); };
        virtual void destroyText(void *text) override { throw ArcadeError("Function not init", "GraphAPI"); };

        //Events:

        virtual bindings pollEvents(myWindow_t *win) override { throw ArcadeError("Function not init", "GraphAPI"); return DOWN; };
    };
}