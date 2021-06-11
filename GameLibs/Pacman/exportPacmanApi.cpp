/*
** EPITECH PROJECT, 2021
** B-OOP-400-RUN-4-1-arcade-paul.brancieq
** File description:
** exportPacmanApi
*/

#include "Pacman.hpp"

extern "C"
{
    arcade::IGameApi *arcade::IGameApiCreate()
    {
        return (new Pacman());
    }

    void arcade::IGameApiDelete(arcade::IGameApi *API)
    {
        delete (Pacman *)API;
    }
}