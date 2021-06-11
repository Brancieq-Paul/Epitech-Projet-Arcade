/*
** EPITECH PROJECT, 2021
** B-OOP-400-RUN-4-1-arcade-paul.brancieq
** File description:
** Windows
*/

#include "include/NcurseAPI.hpp"

myWindow_t *NcurseAPI::initWindow(int height, int width, std::string name)
{
    (void)name;
    (void)height;
    (void)width;
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    return (NULL);
}

void NcurseAPI::destroyWindow(myWindow_t *w)
{
    (void)w;
    endwin();
}

void NcurseAPI::refreshWindow(myWindow_t *w)
{
    (void)w;
    refresh();
    erase();
}