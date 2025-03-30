#ifndef END_H
#define END_H

#include <SDL.h>
#include <SDL_ttf.h>
#include "graphics.h"

class EndScreen {
public:
    EndScreen();
    void show(Graphics& graphics, ScrollingBackground& background, TTF_Font* font);
private:
    SDL_Texture* endBackground;
};

#endif
