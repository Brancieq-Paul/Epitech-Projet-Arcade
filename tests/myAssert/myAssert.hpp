/*
** EPITECH PROJECT, 2021
** B-OOP-400-RUN-4-1-arcade-paul.brancieq
** File description:
** myAssert
*/

#pragma once

#include <iostream>

namespace myTests
{
    class Assert
    {
    private:
        static bool _error;

    public:
        Assert(std::string testCateg, std::string testName, std::string testDesc, bool toTest);
        inline Assert() {};
        ~Assert() {};

        void display(std::string testCateg, std::string testName, std::string testDesc, bool toTest);
        inline bool getErrorStatus() { return Assert::_error; };
        inline void finalExit() { if (_error) { exit(EXIT_FAILURE); } else { exit(EXIT_SUCCESS); }};
    };
}
