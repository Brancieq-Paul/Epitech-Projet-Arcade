/*
** EPITECH PROJECT, 2021
** B-OOP-400-RUN-4-1-arcade-paul.brancieq
** File description:
** Sprite
*/

#include "NcurseAPI.hpp"
#include "IArcadeError.hpp"

using namespace arcade;

void *NcurseAPI::createSprite(std::string file, myWindow_t *Window)
{
    std::ifstream content(file + ".txt");
    std::ostringstream buff;
    auto str = new char[1];
    void *sprite = NULL;

    content.open(file);
    if (content.is_open() != false) {
        buff << content.rdbuf();
        str[0] = buff.str()[0];
    }
    content.close();
    sprite = str;
    if (str[0] == 0)
        throw(arcade::ArcadeError("File is empty\n", "in Fonction:createSprite"));
    return (sprite);
}

void NcurseAPI::displaySprite(mySprite *ent, myWindow_t *Window)
{
    (void)Window;
    if (ent == NULL)
        throw ArcadeError("Sprite are NULL", "displaySprite");
    mvaddch((int)(ent->getPosSprite().y/20), ((int)ent->getPosSprite().x/20), *(char *)ent->getSprite());
}

void NcurseAPI::destroySprite(mySprite *entity)
{
    if (entity != NULL) {
        delete (char *)entity->getSprite();
    } else
        throw ArcadeError("Sprite are NULL", "displaySprite");
}

bindings NcurseAPI::pollEvents(myWindow_t *win)
{
    char c = getch();

    if (c == 3)
        return (UP);
    if (c == 2)
        return (DOWN);
    if (c == 4)
        return (LEFT);
    if (c == 5)
        return (RIGHT);
    if (c == 74)
        return (DEL);
    if (c == 27)
        return (EXIT_ALL);
    if (c == 114)
        return (R);
    if (c == 108)
        return (L);
    if (c == 109)
        return (M);
    if (c == 111)
        return (O);
    if (c == 112)
        return (P);
    if (c == 32)
        return (SPACE);
    return UNKNOWN;
}

void *NcurseAPI::createText(std::string file)
{
    std::string *str = new std::string;

    *str = file;
    return (str);
}

void *NcurseAPI::setText(void *text, std::string value)
{
    std::string *str = (std::string *)text;
    *str = value;
    return text;
}

void NcurseAPI::displayText(void *text, myWindow_t *window, pos_t offset)
{
    std::string *mytext = (std::string *)text;
    char c;

    for (auto it = mytext->begin(); it != mytext->end(); it++) {
        c = *it;
        mvaddch((int)(offset.y/20), ((int)offset.x/20), c);
        offset.x += 20;
    }
}

void NcurseAPI::destroyText(void *text)
{
    if (text != NULL)
        delete (std::string *)text;
}