/*
** EPITECH PROJECT, 2021
** B-OOP-400-RUN-4-1-arcade-paul.brancieq
** File description:
** Testncurse
*/

#include <stdio.h>
#include "SDLAPI.hpp"

extern "C"
{
    arcade::IGraphApi *arcade::GraphApiCreate()
    {
        return (new SDL2API());
    }

    void arcade::GraphApiDelete(arcade::IGraphApi *API)
    {
        delete (SDL2API *)API;
    }
}