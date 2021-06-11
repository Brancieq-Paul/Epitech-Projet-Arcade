/*
** EPITECH PROJECT, 2021
** B-OOP-400-RUN-4-1-arcade-paul.brancieq
** File description:
** libSFML
*/

#include <stdio.h>
#include "SFMLAPI.hpp"

using namespace arcade;

myWindow_t *SFMLAPI::initWindow(int height, int width, std::string name)
{
    myWindow_t *allwindow = new myWindow_t;

    sf::Window *window = (new sf::RenderWindow(sf::VideoMode(height, width), name));
    allwindow->window = window;

    return (allwindow);
}

void SFMLAPI::refreshCalledWindow(sf::RenderWindow *windows)
{
    windows->display();
    windows->clear(sf::Color::Black);
}

void SFMLAPI::refreshWindow(myWindow_t *windows)
{
    refreshCalledWindow((sf::RenderWindow *)windows->window);
}

void SFMLAPI::destroyCalledWindow(sf::RenderWindow *windows)
{
    windows->close();
}

void SFMLAPI::destroyWindow(myWindow_t *windows)
{
    destroyCalledWindow((sf::RenderWindow *)windows->window);
}

void *SFMLAPI::createSprite(std::string file, myWindow_t *window)
{
    sf::Texture *texture = new sf::Texture;
    sf::Sprite *sprite = new sf::Sprite;

    file = file + ".png";
    if (!texture->loadFromFile(file))
        std::cout << "ERROR LOAD TEXTURE" << std::endl;
    sprite->setTexture(*texture);
    return (sprite);
}

void SFMLAPI::destroyCalledSprite(sf::Sprite *sprite)
{
    delete sprite;
}

void SFMLAPI::destroySprite(mySprite *entity)
{
    destroyCalledSprite((sf::Sprite *)entity->getSprite());
}

void SFMLAPI::displayCalledSprite(sf::Sprite *sprite, sf::RenderWindow *windows)
{
    windows->draw(*sprite);
}

void SFMLAPI::setPosSprite(mySprite *entity, sf::Sprite *sprite)
{
    pos_t pos = entity->getPosSprite();
    sprite->setPosition((sf::Vector2f){pos.x, pos.y});
}

void SFMLAPI::displaySprite(mySprite *entity, myWindow_t *windows)
{
    setPosSprite(entity, (sf::Sprite *)entity->getSprite());
    displayCalledSprite((sf::Sprite *)entity->getSprite(), (sf::RenderWindow *)windows->window);
}

bindings SFMLAPI::pollCalledEvents(sf::RenderWindow *window)
{
    sf::Event event;

    while (window->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed: window->close(); return DEL;
        case ::sf::Event::KeyPressed:
            switch (event.key.code)
            {
            case sf::Keyboard::Up:return UP;
            case sf::Keyboard::Down:return DOWN;
            case sf::Keyboard::Left:return LEFT;
            case sf::Keyboard::Right:return RIGHT;
            case sf::Keyboard::A:return A;
            case sf::Keyboard::B:return B;
            case sf::Keyboard::C:return C;
            case sf::Keyboard::D:return D;
            case sf::Keyboard::E:return E;
            case sf::Keyboard::F:return F;
            case sf::Keyboard::G:return G;
            case sf::Keyboard::H:return H;
            case sf::Keyboard::I:return I;
            case sf::Keyboard::K:return K;
            case sf::Keyboard::L:return L;
            case sf::Keyboard::M:return M;
            case sf::Keyboard::N:return N;
            case sf::Keyboard::O:return O;
            case sf::Keyboard::P:return P;
            case sf::Keyboard::Q:return Q;
            case sf::Keyboard::R:return R;
            case sf::Keyboard::S:return S;
            case sf::Keyboard::T:return T;
            case sf::Keyboard::U:return U;
            case sf::Keyboard::V:return V;
            case sf::Keyboard::W:return W;
            case sf::Keyboard::X:return X;
            case sf::Keyboard::Y:return Y;
            case sf::Keyboard::Z:return Z;
            case sf::Keyboard::Escape:return EXIT_ALL;
            case sf::Keyboard::Delete:return DEL;
            case sf::Keyboard::Space:return SPACE;
            default:
                break;
            }
        default:
            break;
        }
    }
    return UNKNOWN;
}

bindings SFMLAPI::pollEvents(myWindow_t *window)
{
    return (pollCalledEvents((sf::RenderWindow *)window->window));
}

void SFMLAPI::destroyCalledText(sf::Text *text)
{
    delete text;
    return;
}

void SFMLAPI::destroyText(void *text)
{
    destroyCalledText((sf::Text *)text);
}

void *SFMLAPI::createText(std::string file)
{
    sf::Text *text = new sf::Text;
    sf::Font *font = new sf::Font;

    if (!font->loadFromFile("Minecraft.ttf"))
        std::cout << "ERROR LOAD FONT" << std::endl;
    text->setFont(*font);
    text->setString(file);
    text->setCharacterSize(20);
    return (void *)text;
}

void SFMLAPI::displayCalledText(sf::Text *text, sf::RenderWindow *window)
{
    window->draw(*text);
}

void SFMLAPI::setPosText(sf::Text *text, pos_t offset)
{
    text->setPosition((sf::Vector2f){offset.x, offset.y});
}

void SFMLAPI::displayText(void *text, myWindow_t *window, pos_t offset)
{
    setPosText((sf::Text *)text, offset);
    displayCalledText((sf::Text *)text, (sf::RenderWindow *)window->window);
}

void *SFMLAPI::setCalledText(sf::Text *text, std::string value)
{
    text->setString(value);
    return (void *)text;
}

void *SFMLAPI::setText(void *text, std::string value)
{
    return (setCalledText((sf::Text *)text, value));
}


void *SFMLAPI::createAudio(std::string file)
{
    sf::Music *audio = new sf::Music;

    audio->openFromFile(file);
    audio->setVolume(15);
    return (void *)audio;
}

void SFMLAPI::playCalledAudio(sf::Music *audio)
{
    if (audio->getStatus() == sf::Music::Stopped)
    {
        audio->play();
    }
}

void SFMLAPI::playAudio(void *audio)
{
    playCalledAudio((sf::Music *)audio);
}

void SFMLAPI::stopCalledAudio(sf::Music *audio)
{
    if (audio->getStatus() == sf::Music::Playing)
    {
        audio->stop();
    }
}

void SFMLAPI::stopAudio(void *audio)
{
    stopCalledAudio((sf::Music *)audio);
}

void SFMLAPI::destroyCalledAudio(sf::Music *audio)
{
    if (audio->getStatus() == sf::Music::Playing)
    {
        audio->stop();
    }
    delete audio;
}

void SFMLAPI::destroyAudio(void *audio)
{
    destroyCalledAudio((sf::Music *)audio);
}