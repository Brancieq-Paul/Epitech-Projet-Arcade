/*
** EPITECH PROJECT, 2021
** B-OOP-400-RUN-4-1-arcade-paul.brancieq
** File description:
** Testncurse
*/

#include <stdio.h>
#include "NcurseAPI.hpp"

extern "C"
{
    arcade::IGraphApi *arcade::GraphApiCreate()
    {
        return (new NcurseAPI());
    }

    void arcade::GraphApiDelete(arcade::IGraphApi *API)
    {
        delete (NcurseAPI *)API;
    }
}