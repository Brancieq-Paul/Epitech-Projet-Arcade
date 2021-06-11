/*
** EPITECH PROJECT, 2021
** B-OOP-400-RUN-4-1-arcade-paul.brancieq
** File description:
** Testncurse
*/

#include <stdio.h>
#include "SFMLAPI.hpp"

using namespace arcade;

extern "C"
{
    arcade::IGraphApi *arcade::GraphApiCreate()
    {
        return (new SFMLAPI());
    }

    void arcade::GraphApiDelete(arcade::IGraphApi *API)
    {
        delete (SFMLAPI *)API;
    }
}