#ifndef _SPRITE__H
#define _SPRITE__H

#include <vector>

struct Sprite {
    SDL_Texture* texture;
    std::vector<SDL_Rect> clips;
    int currentFrame = 0;
    int width = 62, height = 130;

    void init(SDL_Texture* _texture, int frames, const int _clips [][4]);

    void tick();

    const SDL_Rect* getCurrentClip() const;

};

struct ScrollingBackground {
    SDL_Texture* texture;
    int scrollingOffset = 0;
    int width, height;

    void setTexture(SDL_Texture* _texture);

    void scroll(int distance);
};

#endif
