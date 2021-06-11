/*
** EPITECH PROJECT, 2021
** B-OOP-400-RUN-4-1-arcade-paul.brancieq
** File description:
** Core
*/

#include "Core.hpp"
#include "Wdlopen.hpp"
#include "IArcadeError.hpp"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <string>
#include <algorithm>
#include <regex>

Core::Core()
{
    _isEnd = false;
}

Core::~Core()
{
}

void Core::loadGraph(std::string lib)
{
    graphsymbols = new Wdlopen(lib);

    _graph_creator = (funcreategraph *)(*graphsymbols).fetchFunc("GraphApiCreate");
    _graph_destroy = (funcdeletegraph *)(*graphsymbols).fetchFunc("GraphApiDelete");

    _current_graph = _graph_creator();
}

void Core::loadGame(std::string lib)
{
    gamesymbols = new Wdlopen(lib);

    _game_creator = (funcreategame *)(*gamesymbols).fetchFunc("IGameApiCreate");
    _game_destroy = (funcdeletegame *)(*gamesymbols).fetchFunc("IGameApiDelete");

    _current_game = _game_creator();
    _current_game->initGraphApi(_current_graph);
}

void Core::destroyGraph()
{
    _graph_destroy(_current_graph);
}

void Core::destroyGame()
{
    _game_destroy(_current_game);
}

void Core::initGraphApiList(std::string filepath)
{
    std::fstream file("./core/graphs.txt");
    bool continuer = true;
    _graph_it = _graph_list.end();
    std::string ch;

    if (!file) {
        throw arcade::ArcadeError("Invalid list graph libs", "Core::initGraphApiList");
    }
    while(continuer) {
        ch = "";
        file >> ch;
        if (ch != "" && std::ifstream(ch).good()) {
            _graph_list.push_back(ch);
        }
        else if (ch == "")
            continuer = false;
    }
    loadGraph(filepath);
    _graph_it = _graph_list.begin();
    if (_graph_list.end() == _graph_list.begin())
        throw arcade::ArcadeError("No graph libs available", "Core::initGraphApiList");
}

void Core::initGameApiList(std::string filepath)
{
    std::fstream file("./core/games.txt");
    bool continuer = true;
    _game_it = _game_list.end();
    std::string ch;

    if (!file) {
        throw arcade::ArcadeError("Invalid list game libs", "Core::initGameApiList");
    }
    while(continuer) {
        ch = "";
        file >> ch;
        if (ch != "" && std::ifstream(ch).good()) {
            _game_list.push_back(ch);
        }
        else if (ch == "")
            continuer = false;
    }
    loadGame(filepath);
    _game_it = _game_list.begin();
    if (_game_list.end() == _game_list.begin())
        throw arcade::ArcadeError("No game libs available", "Core::initGameApiList");
}

void Core::initGraphApi(std::string filepath)
{
    initGraphApiList(filepath);
}

void Core::swapGraphLibForward()
{
    _graph_it++;
    if (_graph_it == _graph_list.end())
        _graph_it = _graph_list.begin();
    destroyGraph();
    loadGraph(*_graph_it);
}

void Core::swapGameLibForward()
{
    _game_it++;
    if (_game_it == _game_list.end())
        _game_it = _game_list.begin();
    destroyGame();
    loadGame(*_game_it);
}

void Core::swapGraphLibBackward()
{
    if (_graph_it == _graph_list.begin()) {
        while (_graph_it + 1 != _graph_list.end())
            _graph_it++;
    } else {
        _graph_it--;
    }
    destroyGraph();
    loadGraph(*_graph_it);
}

void Core::swapGameLibBackward()
{
    if (_game_it == _game_list.begin()) {
        while (_game_it + 1 != _game_list.end())
            _game_it++;
    } else {
        _game_it--;
    }
    destroyGame();
    loadGame(*_game_it);
}

void Core::loadMenu()
{
    _menuWin = _current_graph->initWindow(1000, 1000, "ARCADE");
    _actualMenuText = _current_graph->createText(*_game_it);
}

void Core::menu()
{
    loadMenu();
    auto time = clock();
    auto event = _current_graph->pollEvents(_menuWin);

    while ((event = _current_graph->pollEvents(_menuWin)) != arcade::EXIT_ALL && event != arcade::SPACE)
    {
        _current_graph->displayText(_actualMenuText, _menuWin, (arcade::pos_t){500, 500});
        if (event == arcade::O) {
            _current_graph->destroyWindow(_menuWin);
            _current_graph->destroyText(_actualMenuText);
            swapGraphLibBackward();
            loadMenu();
        }
        if (event == arcade::P) {
            _current_graph->destroyWindow(_menuWin);
            _current_graph->destroyText(_actualMenuText);
            swapGraphLibForward();
            loadMenu();
        }
        if (event == arcade::UP) {
            swapGameLibForward();
            _actualMenuText = _current_graph->setText(_actualMenuText, *_game_it);
        }
        if (event == arcade::DOWN) {
            swapGameLibBackward();
            _actualMenuText = _current_graph->setText(_actualMenuText, *_game_it);
        }
        if (clock() - time > 1000) {
            time = clock();
            _current_graph->refreshWindow(_menuWin);
        }
    }
    _current_graph->destroyWindow(_menuWin);
    _current_graph->destroyText(_actualMenuText);
    if (event == arcade::EXIT_ALL)
        _isEnd = true;
}

void Core::loop()
{
    initGameApiList("./lib/arcade_nibbler.so");
    menu();
    while (verifyEnd() != arcade::EXIT_ALL && !_isEnd) {
        _current_game->initGraphApi(_current_graph);
        loopGame();
        if (verifyEnd() == arcade::O) {
            swapGraphLibBackward();
        }
        if (verifyEnd() == arcade::P) {
            swapGraphLibForward();
        }
        if (verifyEnd() == arcade::L) {
            swapGameLibBackward();
        }
        if (verifyEnd() == arcade::M) {
            swapGameLibForward();
        }
        if (verifyEnd() == arcade::R) {
            destroyGame();
            loadGame(*_game_it);
        }
        if (verifyEnd() == arcade::DEL) {
            menu();
        }
    }
}
