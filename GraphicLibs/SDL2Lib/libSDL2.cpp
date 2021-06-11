/*
** EPITECH PROJECT, 2021
** B-OOP-400-RUN-4-1-arcade-paul.brancieq
** File description:
** libSDL2
*/

#include "SDLAPI.hpp"

myWindow_t *SDL2API::initWindow(int height, int width, std::string name)
{
    myWindow_t *allwindow = new myWindow_t;
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if (SDL_Init(SDL_INIT_EVERYTHING))
    {
        std::cerr << SDL_GetError() << "\n";
        return NULL;
    }
    window = SDL_CreateWindow(name.c_str(), 100, 100, width, height, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    allwindow->window = window;
    allwindow->renderer = renderer;
    return allwindow;
}

void SDL2API::refreshCalledWindow(SDL_Window *window, SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
}

void SDL2API::refreshWindow(myWindow_t *window)
{
    refreshCalledWindow((SDL_Window *)window->window,
                        (SDL_Renderer *)window->renderer);
}

void SDL2API::destroyCalledWindow(SDL_Window *window, SDL_Renderer *renderer)
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}

void SDL2API::destroyWindow(myWindow_t *window)
{
    destroyCalledWindow((SDL_Window *)window->window, (SDL_Renderer *)window->renderer);
}

bindings SDL2API::pollCalledEvents(SDL_Window *window)
{
    (void)window;
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_WINDOWEVENT:
            if (event.window.event == SDL_WINDOWEVENT_CLOSE)
                return DEL;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_LEFT: return LEFT;
            case SDLK_RIGHT: return RIGHT;
            case SDLK_UP: return UP;
            case SDLK_DOWN: return DOWN;
            case SDLK_DELETE: return DEL;
            case SDLK_SPACE: return SPACE;
            case SDLK_ESCAPE: return EXIT_ALL;
            case SDLK_a: return A;
            case SDLK_b: return B;
            case SDLK_c: return C;
            case SDLK_d: return D;
            case SDLK_e: return E;
            case SDLK_f: return F;
            case SDLK_g: return G;
            case SDLK_h: return H;
            case SDLK_i: return I;
            case SDLK_j: return J;
            case SDLK_k: return K;
            case SDLK_l: return L;
            case SDLK_m: return M;
            case SDLK_n: return N;
            case SDLK_o: return O;
            case SDLK_p: return P;
            case SDLK_q: return Q;
            case SDLK_r: return R;
            case SDLK_s: return S;
            case SDLK_t: return T;
            case SDLK_u: return U;
            case SDLK_v: return V;
            case SDLK_w: return W;
            case SDLK_x: return X;
            case SDLK_y: return Y;
            case SDLK_z: return Z;
            default: break;
            }
        default:
            break;
        }
    }
    return UNKNOWN;
}

bindings SDL2API::pollEvents(myWindow_t *win)
{
    return pollCalledEvents((SDL_Window *)win->window);
}

void *SDL2API::createCalledSprite(std::string file, SDL_Renderer *renderer)
{
    SDL_Texture *texture = NULL;

    file = file + ".png";
    texture = IMG_LoadTexture(renderer, file.c_str());
    if (!texture) {
        std::cerr << SDL_GetError() << std::endl;
        return NULL;
    }
    return (void *)texture;
}

void *SDL2API::createSprite(std::string file, myWindow_t *window)
{
    return createCalledSprite(file, (SDL_Renderer *)window->renderer);
}

void SDL2API::displayCalledSprite(SDL_Texture *texture, SDL_Renderer *renderer, pos_t pos)
{
    int w = 0;
    int h = 0;
    SDL_Rect source {(int)pos.x, (int)pos.y, 0, 0};

    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    source.w = w;
    source.h = h;
    SDL_RenderCopy(renderer, texture, nullptr, &source);
}

void SDL2API::displaySprite(mySprite *entity, myWindow_t *window)
{
    displayCalledSprite((SDL_Texture *)entity->getSprite(),
    (SDL_Renderer *)window->renderer, entity->getPosSprite());
}

void SDL2API::destroyCalledSprite(SDL_Texture *texture)
{
    SDL_DestroyTexture(texture);
}

void SDL2API::destroySprite(mySprite *entity)
{
    destroyCalledSprite((SDL_Texture *)entity->getSprite());
}

void *SDL2API::createAudio(std::string file)
{
    return NULL;
}

void SDL2API::playAudio(void *audio)
{
    return;
}

void SDL2API::stopAudio(void *audio)
{
    return;
}

void SDL2API::destroyAudio(void *audio)
{
    return;
}

void *SDL2API::createText(std::string file)
{
    if (TTF_Init() != 0) {
        std::cout << TTF_GetError() << std::endl;
        throw ArcadeError("create text", "error ttf");
    }
    TTF_Font *font = TTF_OpenFont("Minecraft.ttf", 20);
    if (!font) {
        std::cout << "ERROR" << std::endl;
        throw ArcadeError("create text", "error font");
    }
    SDL_Color white = {255, 255, 255, 255};
    SDL_Surface *surfaceText = new SDL_Surface;
    surfaceText = TTF_RenderText_Solid(font, file.c_str(), white);
    return (void *)surfaceText;
}

void *SDL2API::setCalledText(SDL_Surface *text, std::string value)
{
    TTF_Font *font = TTF_OpenFont("Minecraft.ttf", 20);
    SDL_Color white = {255, 255, 255, 255};

    text = TTF_RenderText_Solid(font, value.c_str(), white);
    return (void *)text;
}

void *SDL2API::setText(void *text, std::string value)
{
    return (setCalledText((SDL_Surface *)text, value));
}

void SDL2API::displayCalledText(SDL_Surface *text, SDL_Renderer *renderer, pos_t pos)
{
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, text);
    SDL_Rect rect = {(int)pos.x, (int)pos.y, 100, 50};
    SDL_RenderCopy(renderer, texture, nullptr, &rect);
}

void SDL2API::displayText(void *text, myWindow_t *window, pos_t offset)
{
    displayCalledText((SDL_Surface *)text,(SDL_Renderer *)window->renderer, offset);
    return;
}

void SDL2API::destroyCalledText(SDL_Surface *text)
{
    delete text;
}

void SDL2API::destroyText(void *text)
{
    destroyCalledText((SDL_Surface *)text);
}