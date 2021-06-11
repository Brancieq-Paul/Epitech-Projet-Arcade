/*
** EPITECH PROJECT, 2021
** B-OOP-400-RUN-4-1-arcade-paul.brancieq
** File description:
** Nibbler
*/

#pragma once

#include "AGameApi.hpp"

class Nibbler : public arcade::AGameApi {
    public:
        inline Nibbler() : AGameApi(), _init(false) {};
        inline ~Nibbler() override {};

        void launchGame() override;
    protected:
    private:
        bool _init;

        arcade::mySprite *_player;
};
