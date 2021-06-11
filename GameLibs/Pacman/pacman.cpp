/*
** EPITECH PROJECT, 2021
** B-OOP-400-RUN-4-1-arcade-paul.brancieq
** File description:
** pacman
*/

#include "IGraphApi.hpp"
#include "Pacman.hpp"
#include "unistd.h"

using namespace arcade;

void Pacman::launchGame()
{
    myWindow_t *mywin = new myWindow_t;

    mywin =  this->_graphAPI->initWindow(1000, 1000, "PACMAN");
    if (!_init) {
        _pacman = new mySprite;
        _gost = new mySprite;
        _pacman->setPosMySprite(pos_t{500, 500});
        _gost->setPosMySprite(pos_t{0,100});
        _init = true;
    }
    _pacman->setSprite(_graphAPI->createSprite("GameLibs/Pacman/pacman", mywin));
    _gost->setSprite(_graphAPI->createSprite("GameLibs/Pacman/ennemi", mywin));
    _ghost_velo = 20;
    for (; (_endStatus = _graphAPI->pollEvents(mywin)) != EXIT_ALL;) {
        _graphAPI->refreshWindow(mywin);
        if (_endStatus == P || _endStatus == DEL ||_endStatus == R ||_endStatus == L ||_endStatus == M || _endStatus == O)
            break;
        _graphAPI->displaySprite(_gost, mywin);
        _graphAPI->displaySprite(_pacman, mywin);
        this->move(_endStatus, _pacman);
        this->gostMove(_gost);
    }
    _graphAPI->destroySprite(_pacman);
    _graphAPI->destroySprite(_gost);
    _graphAPI->destroyWindow(mywin);
}

void Pacman::move(bindings endStatus, mySprite *pacman)
{
    pos_t pos = pacman->getPosSprite();

    if (endStatus == UP) {
        pos.y -= 20;
        pacman->setPosMySprite(pos);
    }
    if (endStatus == DOWN) {
        pos.y += 20;
        pacman->setPosMySprite(pos);
    }
    if (endStatus == LEFT) {
        pos.x -= 20;
        pacman->setPosMySprite(pos);
    }
    if (endStatus == RIGHT) {
        pos.x += 20;
        pacman->setPosMySprite(pos);
    }
}

void Pacman::gostMove(arcade::mySprite *gost)
{
    pos_t pos = gost->getPosSprite();

    if (pos.x < 0) {
        _ghost_velo = 20;
    } else if (pos.x  > 1000) {
        _ghost_velo = -20;
    }
    pos.x += _ghost_velo;
    gost->setPosMySprite(pos);
    usleep(50000);
}