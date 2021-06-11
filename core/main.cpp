/*
** EPITECH PROJECT, 2021
** B-OOP-400-RUN-4-1-arcade-paul.brancieq
** File description:
** main
*/

#include "Core.hpp"
#include "IArcadeError.hpp"

int main(int ac, char **av)
{
    try {
        if (ac != 2) {
            perror("Too many/Not enought arguments");
            return 84;
        }
        auto core = Core();
        core.initGraphApi(av[1]);
        core.loop();
    } catch (arcade::ArcadeError &e) {
        std::cerr << std::string("Error: ")  << e.where() << ": " << e.what() << std::endl;
    }
    return 0;
}