#ifndef _OBSTACLE__H
#define _OBSTACLE__H
struct Obstacle{
    int x, y;
    int speed;
    int width = 65, height = 55;
    bool passed = false;
    int score = 0;
    SDL_Texture* texture;
    Obstacle(int x, int y, SDL_Texture* tex, int speed );
    void update(int& score);
    void render(Graphics &graphics);
    void scroll(int distance);
    SDL_Rect getRect();
};
#endif
