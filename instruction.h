#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <SDL.h>
#include <SDL_ttf.h>
#include "graphics.h"

class Instruction {
public:
    void show(Graphics& graphics, TTF_Font* font);
};

#endif
