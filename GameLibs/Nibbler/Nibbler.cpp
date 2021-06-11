/*
** EPITECH PROJECT, 2021
** B-OOP-400-RUN-4-1-arcade-paul.brancieq
** File description:
** Nibbler
*/

#include "Nibbler.hpp"

using namespace arcade;

void Nibbler::launchGame()
{
    myWindow_t *windows = new myWindow_t;
    int inverse;
    int direction;
    int velocity = 1;
    auto time = clock();
    void *musique;

    if (!_init) {
        inverse = 1;
        direction = 0;
        _player = new mySprite;
        _player->setPosMySprite((pos_t){490, 510});
        _init = true;
    }
    musique = _graphAPI->createAudio("GameLibs/Nibbler/game.ogg");
    _graphAPI->playAudio(musique);
    time = clock();
    windows = _graphAPI->initWindow(1000, 1000, "NIBBLER");
    _player->setSprite(_graphAPI->createSprite("GameLibs/Nibbler/player", windows));
    bindings event = UNKNOWN;
    while (event != DEL && event != O && event != P && event != L && event != M && event != EXIT_ALL && event != R)
    {
        if (event == UP)
        {
            direction = 1;
            inverse = -1;
        }
        else if (event == DOWN)
        {
            direction = 1;
            inverse = 1;
        }
        else if (event == RIGHT)
        {
            direction = 0;
            inverse = 1;
        }
        else if (event == LEFT)
        {
            direction = 0;
            inverse = -1;
        }
        if (clock() - time > 1000)
        {
            time = clock();
            if (direction == 0 && _player->getPosSprite().x + velocity * inverse >= 0 && _player->getPosSprite().x + velocity * inverse <= 980)
                _player->setPosMySprite((pos_t){_player->getPosSprite().x + velocity * inverse, _player->getPosSprite().y});
            else if (_player->getPosSprite().y + velocity * inverse >= 0 && _player->getPosSprite().y + velocity * inverse <= 980)
                _player->setPosMySprite((pos_t){_player->getPosSprite().x, _player->getPosSprite().y + velocity * inverse});
        }
        event = _graphAPI->pollEvents(windows);
        _graphAPI->displaySprite(_player, windows);
        _graphAPI->refreshWindow(windows);
    }
    _endStatus = event;
    _graphAPI->destroyWindow(windows);
    _graphAPI->destroySprite(_player);
    _graphAPI->destroyAudio(musique);
}
