/*
** EPITECH PROJECT, 2021
** B-OOP-400-RUN-4-1-arcade-paul.brancieq
** File description:
** test
*/

#include <iostream>
#include "IGraphApi.hpp"

#pragma once

namespace arcade
{
    class IGameApi
    {
    public:
        //Interface

        virtual void initGraphApi(IGraphApi *api) = 0;
        virtual void launchGame() = 0;
        virtual bindings endGame() = 0;
    };

    extern "C" inline bool isGame(void) {return true;};
    extern "C" IGameApi *IGameApiCreate();
    extern "C" void IGameApiDelete(IGameApi *interface);
}