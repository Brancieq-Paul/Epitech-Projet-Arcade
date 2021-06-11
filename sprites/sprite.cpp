/*
** EPITECH PROJECT, 2021
** B-OOP-400-RUN-4-1-arcade-paul.brancieq
** File description:
** Sprite
*/

#include <stdio.h>
#include "IGraphApi.hpp"

using namespace arcade;

arcade::mySprite::mySprite()
{
}

arcade::mySprite::~mySprite()
{
}

void *arcade::mySprite::getSprite() const
{
    return _sprite;
}

void arcade::mySprite::setSprite(void *sprite)
{
    _sprite = sprite;
}

pos_t arcade::mySprite::getPosSprite() const
{
    return _position;
}

void arcade::mySprite::setPosMySprite(pos_t pos)
{
    _position = pos;
}

std::string arcade::mySprite::getSrc() const
{
    return _src;
}

void arcade::mySprite::setSrc(std::string src)
{
    _src = src;
}