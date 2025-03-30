#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "graphics.h"
#include "defs.h"
#include "sprite.h"
#include "player.h"
#include "obstacle.h"
#include "intro.h"
#include "endScreen.h"
#include "instruction.h"
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
            checkCollision(player.getRect(), obstacle3.getRect())) {
                    SDL_Delay(500);
                    cout << "Game Over!" << endl;
                    endScreen.show(graphics, background, font);
                    running = false;
        }

        /*// Lấy hitbox của player và obstacle để debug
        SDL_Rect playerRect = player.getRect();
        SDL_Rect obstacleRect = obstacle.getRect();
        SDL_Rect obstacleRect2 = obstacle2.getRect();
        SDL_Rect obstacleRect3 = obstacle3.getRect();

        // In tọa độ để kiểm tra
        cout << "Player: x=" << playerRect.x << ", y=" << playerRect.y
             << ", w=" << playerRect.w << ", h=" << playerRect.h << endl;
        cout << "Obstacle 1: x=" << obstacleRect.x << ", y=" << obstacleRect.y
             << ", w=" << obstacleRect.w << ", h=" << obstacleRect.h << endl;
        cout << "Obstacle 2: x=" << obstacleRect2.x << ", y=" << obstacleRect2.y
             << ", w=" << obstacleRect2.w << ", h=" << obstacleRect2.h << endl;
        cout << "Obstacle 3: x=" << obstacleRect3.x << ", y=" << obstacleRect3.y
             << ", w=" << obstacleRect3.w << ", h=" << obstacleRect3.h << endl;*/

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


        /*// Vẽ hitbox để kiểm tra va chạm
        SDL_SetRenderDrawColor(graphics.renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(graphics.renderer, &playerRect);
        SDL_SetRenderDrawColor(graphics.renderer, 0, 255, 0, 255);
        SDL_RenderDrawRect(graphics.renderer, &obstacleRect);
        SDL_RenderDrawRect(graphics.renderer, &obstacleRect2);
        SDL_RenderDrawRect(graphics.renderer, &obstacleRect3);*/

        graphics.presentScene();
        SDL_Delay(40);  // Để game mượt (40 FPS)
    }
    //
    SDL_DestroyTexture( background.texture );
	SDL_DestroyTexture( manTexture ); manTexture = nullptr;
	TTF_CloseFont(font);
	graphics.quit();
    return 0;
}
