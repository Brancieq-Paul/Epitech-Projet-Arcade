/*
** EPITECH PROJECT, 2021
** B-OOP-400-RUN-4-1-arcade-paul.brancieq
** File description:
** Wdlopen
*/

#pragma once

#include <iostream>
#include <map>

class Wdlopen
{
public:
    Wdlopen(std::string libPath);
    inline Wdlopen() {};
    ~Wdlopen();

    void *fetchFunc(std::string name);
private:
    void *hndl;
};
