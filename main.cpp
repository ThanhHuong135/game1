#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "graphics.h"
#include "defs.h"
#include "sprite.h"
#include "player.h"
#include "obstacle.h"
#include "intro.h"
#include "endScreen.h"
#include "instruction.h"
#include "music.h"
using namespace std;
// xử lý va chạm
bool checkCollision(SDL_Rect a, SDL_Rect b) {
    return (a.x < b.x + b.w &&
            a.x + a.w > b.x &&
            a.y < b.y + b.h &&
            a.y + a.h > b.y);
}
int main(int argc, char *argv[])
{
    Graphics graphics;
    graphics.init();
    // music
    MusicPlayer music;
    music.loadMusic();
    music.playBackgroundMusic(); // phats nhajc neenf
// Khởi tạo Intro
    Intro intro;
    intro.init(graphics);  // Truyền graphics vào hàm init()
    intro.show(graphics);
    intro.clean();
// Load background
    ScrollingBackground background;
    background.setTexture(graphics.loadTexture(BACKGROUND));
// Load sprite nhân vật
    Sprite man;
    SDL_Texture* manTexture = graphics.loadTexture(MAN_SPRITE_FILE);
    man.init(manTexture, MAN_FRAMES, MAN_CLIPS);
// load chuowngs ngaji vaajt
    SDL_Texture* obstacleTexture = graphics.loadTexture(OBSTACLE);
    Obstacle obstacle(350, 420, obstacleTexture, 8);
    Obstacle obstacle2(650, 420, obstacleTexture, 8);
    Obstacle obstacle3(900, 420, obstacleTexture, 8);
// Biến điểm số
    int score = 0;

    // Load font để hiển thị điểm số
    TTF_Font* font = graphics.loadFont("Purisa-BoldOblique.ttf", 50);
    SDL_Color textColor = {255, 255, 255}; // Màu trắng
    // Khởi tạo màn hình kết thúc
    EndScreen endScreen;
//
    bool quit = false;
    SDL_Event e;
    bool running = true ;
// Tạo nhân vật với vị trí ban đầu
    Player player(0, 351);
    player.sprite = man; // gán player cho sprite
//màn hình hướng dẫn
    Instruction instruction;
    instruction.show(graphics, font);
    // xử lý sprite sheet
    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
            } else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE) {
                player.jump(); // Gọi jump() đúng nhân vật
                music.playJumpSound();
            }
        }
        // Cập nhật nhân vật
        player.update();
        // cập nhật chướng ngại vạat
        obstacle.update(score);
        obstacle2.update(score);
        obstacle3.update(score);
        // xử lý va chạm
        if (checkCollision(player.getRect(), obstacle.getRect()) ||
            checkCollision(player.getRect(), obstacle2.getRect()) ||
            checkCollision(player.getRect(), obstacle3.getRect())) {\
                    music.playDieSound();
                    SDL_Delay(500);
                    cout << "Game Over!" << endl;
                    endScreen.show(graphics, background, font);
                    running = false;
        }
        // Vẽ nền và nhân vật
        background.scroll(8);
        graphics.render_background(background);
        graphics.render(player.x, player.y, player.sprite);
        obstacle.render(graphics);
        obstacle2.render(graphics);
        obstacle3.render(graphics);
        // Hiển thị điểm số lên màn hình
        string scoreText = "Score: " + to_string(score);
        SDL_Texture* scoreTexture = graphics.renderText(scoreText.c_str(), font, textColor);
        graphics.renderTexture(scoreTexture, 10, 10); // Hiển thị ở góc trái trên
        SDL_DestroyTexture(scoreTexture); // Giải phóng bộ nhớ sau mỗi lần vẽ
        graphics.presentScene();
        SDL_Delay(35);
    }
    //
    music.cleanUp();
    SDL_DestroyTexture( background.texture );
	SDL_DestroyTexture( manTexture ); manTexture = nullptr;
	TTF_CloseFont(font);
	graphics.quit();
    return 0;
}
