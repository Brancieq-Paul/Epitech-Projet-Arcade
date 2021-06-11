/*
** EPITECH PROJECT, 2021
** ArcadeProjectCommonAPI
** File description:
** ArcadeError
*/

#pragma once

#include <exception>
#include <iostream>

namespace arcade
{
    class ArcadeError : virtual public std::exception
    {
    public:
        inline ArcadeError(std::string what, std::string where) : _what(what), _where(where){};
        inline ArcadeError(ArcadeError prevError, std::string where) : _what(prevError.what()), _where(std::string(prevError.where()) + " in " + where) {};
        virtual ~ArcadeError() throw() {};

        inline const char * where() { return _where.c_str(); };
        inline const char * what() { return _what.c_str(); };

    protected:
        std::string _what;
        std::string _where;
    };
}
