/*
** EPITECH PROJECT, 2021
** B-OOP-400-RUN-4-1-arcade-paul.brancieq
** File description:
** MyNcurses
*/

#include "include/Window.hpp"

Window::~Window()
{
    endwin();
}

int Window::getHeight() const
{
    return (_height);
}

int Window::getWidth() const
{
    return (_width);
}