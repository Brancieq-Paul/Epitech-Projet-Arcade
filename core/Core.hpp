/*
** EPITECH PROJECT, 2021
** B-OOP-400-RUN-4-1-arcade-paul.brancieq
** File description:
** core
*/

#pragma once

#include <vector>

#include "IGameApi.hpp"
#include "IGraphApi.hpp"
#include "Wdlopen.hpp"

typedef arcade::IGraphApi *funcreategraph();
typedef void funcdeletegraph(arcade::IGraphApi *);

typedef arcade::IGameApi *funcreategame();
typedef void funcdeletegame(arcade::IGameApi *);

class Core
{
private:

    arcade::IGraphApi *_current_graph;
    arcade::IGameApi *_current_game;

    Wdlopen *graphsymbols;
    Wdlopen *gamesymbols;

    funcreategraph *_graph_creator;
    funcdeletegraph *_graph_destroy;

    funcreategame *_game_creator;
    funcdeletegame *_game_destroy;

    std::vector<std::string> _graph_list;
    std::vector<std::string> _game_list;

    std::vector<std::string>::iterator _graph_it;
    std::vector<std::string>::iterator _game_it;

    void loadGraph(std::string);

    void destroyGraph();
    void destroyGame();

    void initGraphApiList(std::string);
    void initGameApiList(std::string);


    inline arcade::bindings verifyEnd() { return _current_game->endGame(); };

    inline void loopGame() { _current_game->launchGame(); };

    void swapGraphLibForward();
    void swapGraphLibBackward();
    void swapGameLibForward();
    void swapGameLibBackward();

    void menu();
    void loadMenu();

    arcade::myWindow_t *_menuWin;
    void *_actualMenuText;

public:
    Core();
    ~Core();
    void loadGame(std::string);

    void initGraphApi(std::string);
    void loop();

    bool _isEnd;
};
