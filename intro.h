#ifndef INTRO_H
#define INTRO_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

struct Intro {
    SDL_Texture* backgroundTexture;
    SDL_Texture* logoTexture;
    SDL_Texture* playButtonTexture;
    SDL_Rect logoRect, playButtonRect;

    void init(SDL_Renderer* renderer);
    bool show(SDL_Renderer* renderer);
    void clean();
};

#endif
