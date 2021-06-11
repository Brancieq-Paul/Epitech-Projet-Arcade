/*
** EPITECH PROJECT, 2021
** B-OOP-400-RUN-4-1-arcade-paul.brancieq
** File description:
** test
*/

#include <iostream>
#include <functional>

#pragma once

namespace arcade
{
    enum bindings {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        EXIT_ALL,
        A,
        B,
        C,
        D,
        E,
        F,
        G,
        H,
        I,
        J,
        K,
        L,
        M,
        N,
        O,
        P,
        Q,
        R,
        S,
        T,
        U,
        V,
        W,
        X,
        Y,
        Z,
        DEL,
        SPACE,
        UNKNOWN
    };

    typedef struct pos_s {
        float x;
        float y;
    } pos_t;

    class mySprite {
    public:
        mySprite();
        ~mySprite();
        void *getSprite() const;
        void setPosMySprite(pos_t pos);
        pos_t getPosSprite() const;
        void setSprite(void *sprite);
        std::string getSrc() const;
        void setSrc(std::string);
    private:
        pos_t _position;
        void *_sprite;
        std::string _src;
    };

    typedef struct myWindow_s {
        void *window;
        void *renderer;
    } myWindow_t;

    class IGraphApi
    {

    public:
        //window
        virtual myWindow_t *initWindow(int height, int width, std::string name) = 0;
        virtual void refreshWindow(myWindow_t *window) = 0;
        virtual void destroyWindow(myWindow_t *window) = 0;

        //sprite
        virtual void *createSprite(std::string file, myWindow_t *window) = 0;
        virtual void displaySprite(mySprite *entity, myWindow_t *window) = 0;
        virtual void destroySprite(mySprite *entity) = 0;

        //audio

        virtual void *createAudio(std::string file) = 0;
        virtual void playAudio(void *audio) = 0;
        virtual void stopAudio(void *audio) = 0;
        virtual void destroyAudio(void *audio) = 0;

        //events
        virtual bindings pollEvents(myWindow_t *win) = 0;

        //text
        virtual void *createText(std::string file) = 0;
        virtual void *setText(void *text, std::string value) = 0;
        virtual void displayText(void *text, myWindow_t *window, pos_t offset) = 0;
        virtual void destroyText(void *text) = 0;

    };

    extern "C" inline bool isGraphical(void) {return true;};
    extern "C" arcade::IGraphApi *GraphApiCreate();
    extern "C" void GraphApiDelete(arcade::IGraphApi *lib);
}