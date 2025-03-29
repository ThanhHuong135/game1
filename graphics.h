#ifndef _GRAPHICS__H
#define _GRAPHICS__H
#include "sprite.h"
struct Graphics {
    SDL_Renderer *renderer;
	SDL_Window *window;
// báo lỗi
	void logErrorAndExit(const char* msg, const char* error);

// hàm khởi tạo video hình ảnh am thanh vv
	void init();

// background
	void prepareScene(SDL_Texture * background);

// hiển thị ảnh
    void presentScene();

// Tải hình ảnh từ file vào SDL
    SDL_Texture *loadTexture(const char *filename);

// Vẽ một texture lên cửa sổ tại vị trí (x, y)
    void renderTexture(SDL_Texture *texture, int x, int y);

// Vẽ một phần của texture lên cửa sổ tại vị trí (x, y)
    void blitRect(SDL_Texture *texture, SDL_Rect *src, int x, int y);

// kết thúc và thoát
    void quit();

    void render(int x, int y, const Sprite& sprite);

    void render_background(const ScrollingBackground& background);

};

#endif

