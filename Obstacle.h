#ifndef _OBSTACLE__H
#define _OBSTACLE__H
struct Obstacle{
    int x, y;
    int speed;
    int width = 65, height = 55;
    SDL_Texture* texture;
    Obstacle(int x, int y, SDL_Texture* tex, int speed );
    void update();
    void render(Graphics &graphics);
    void scroll(int distance);
    SDL_Rect getRect();
};
#endif
