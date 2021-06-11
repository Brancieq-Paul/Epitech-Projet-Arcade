/*
** EPITECH PROJECT, 2021
** B-OOP-400-RUN-4-1-arcade-paul.brancieq
** File description:
** Pacman
*/

#pragma once

#include "AGameApi.hpp"

class Pacman : public arcade::AGameApi {
    public:
        inline Pacman() : AGameApi(), _init(false) {};
        inline ~Pacman() override {};

        void launchGame();
        void move(arcade::bindings, arcade::mySprite *);
        void gostMove(arcade::mySprite *);
    protected:
    private:
        int _ghost_velo;
        bool _init;

        arcade::mySprite *_pacman;
        arcade::mySprite *_gost;
};
