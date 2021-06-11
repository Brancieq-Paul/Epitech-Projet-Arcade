/*
** EPITECH PROJECT, 2021
** B-OOP-400-RUN-4-1-arcade-paul.brancieq
** File description:
** MyNcurses
*/

#ifndef MYNCURSES_HPP_
#define MYNCURSES_HPP_

#include "ncurses.h"
#include <vector>
#include <memory>
#include "IArcadeError.hpp"

class Window {
    public:
        Window() {};
        ~Window();
        int getHeight() const;
        int getWidth() const;
        inline void setHeight(int &Height) {_height = Height;};
        inline void setWidth(int &Width) {_width = Width;};
    protected:
    private:
        int _height;
        int _width;
};

#endif /* !MYNCURSES_HPP_ */
