#include "Paddle.h"

extern float SCREEN_HEIGHT;

Paddle::Paddle (float x, float y, float speed_y) : x(x), y(y), speed_y(speed_y) {}
void Paddle::Draw() {
        DrawRectangleRounded(Rectangle{x, y, width, height}, 0.8, 0, WHITE);
    }
void Paddle::Update() {
        if(IsKeyDown(KEY_UP) && y > 0) {
            y -= speed_y;
        } else if (IsKeyDown(KEY_DOWN) && (y + height) < SCREEN_HEIGHT) {
            y += speed_y;
        } 
    }