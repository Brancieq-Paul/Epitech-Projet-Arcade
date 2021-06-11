/*
** EPITECH PROJECT, 2021
** B-OOP-400-RUN-4-1-arcade-paul.brancieq
** File description:
** AGameApi
*/

#include "IGameApi.hpp"
#include "IGraphApi.hpp"

#pragma once

namespace arcade
{
    class AGameApi : public arcade::IGameApi
    {
    public:
        inline AGameApi() : _initStatus(false) {};
        virtual ~AGameApi() {};

        inline void initGraphApi(arcade::IGraphApi *api) override { _graphAPI = api; _initStatus = true;};
        virtual inline void launchGame() override {};
        inline arcade::bindings endGame() override { return _endStatus; };

    protected:
        arcade::IGraphApi *_graphAPI;
        bool _initStatus;

        arcade::bindings _endStatus;
    };
}
