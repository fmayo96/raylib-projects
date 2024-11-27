#include "CpuPaddle.h"

CpuPaddle::CpuPaddle(float x, float y, float speed_y) : Paddle (x, y, speed_y) {}
void CpuPaddle::Update(Ball *ball) {
        if (y > ball->y && ball->speed_x > 0) {
            y -= speed_y;
        } else if ((y + height) < ball->y && ball->speed_x > 0) {
            y += speed_y;
        }
    }