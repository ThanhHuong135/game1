#ifndef INTRO_H
#define INTRO_H
#include <SDL.h>
#include "graphics.h"

class Intro {
public:
    void init(Graphics& graphics); // Truyền tham chiếu
    bool show(Graphics& graphics); // Truyền tham chiếu
    void clean();

private:
    SDL_Texture* backgroundTexture = nullptr;
    SDL_Texture* playButtonTexture = nullptr;
    SDL_Texture* textTexture = nullptr;
    TTF_Font* font = nullptr;
    SDL_Rect playButtonRect;
    SDL_Rect textRect;
    SDL_Renderer* renderer;
};
#endif
