/*
** EPITECH PROJECT, 2021
** B-OOP-400-RUN-4-1-arcade-paul.brancieq
** File description:
** exportNibblerApi
*/

#include "Nibbler.hpp"

extern "C"
{
    arcade::IGameApi *arcade::IGameApiCreate()
    {
        return (new Nibbler());
    }

    void arcade::IGameApiDelete(arcade::IGameApi *API)
    {
        delete (Nibbler *)API;
    }
}