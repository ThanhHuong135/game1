
#ifndef _DEFS__H
#define _DEFS__H
#define BACKGROUND_IMG "forest.jpg"
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 500;
#define WINDOW_TITLE "Running Man!"

#define MAN_SPRITE_FILE "sprite.png"
#define OBSTACLE "obstacle.png"
const int MAN_CLIPS[][4] = {
    {  0, 0, 214, 146 },
    { 214, 0, 214, 146 },
    { 428, 0, 214, 146 },
    { 642, 0, 214, 146 },
    { 856, 0, 214, 146 }
};
const int MAN_FRAMES = sizeof(MAN_CLIPS)/sizeof(int)/6;

const int GROUND_Y = 500;
const int GRAVITY = 1;
const int JUMP_FORCE = -15;
#endif
