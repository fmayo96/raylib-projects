#include "Ball.h"
#include "include/raylib.h"

extern float SCREEN_HEIGHT;
extern float SCREEN_WIDTH;
extern int player_score;
extern int computer_score;
extern Color Yellow;
Ball::Ball (float x, float y, float speed_x, float speed_y, int radius) : x(x), y(y), speed_x(speed_x), speed_y(speed_y), radius(radius) {} 
void Ball::Draw() {
        DrawCircle(x, y, radius, Yellow);
    }
void Ball::Update() {
        x += speed_x;
        y += speed_y;
        
        if ((y-radius) < 0 || (y+radius) > SCREEN_HEIGHT) {
            speed_y *= -1;
        }
        if (x < 0) {
          ++computer_score;
          x = SCREEN_WIDTH / 2;
          y = SCREEN_HEIGHT / 2;
        }
        if (x > SCREEN_WIDTH) {
          ++player_score;
          x = SCREEN_WIDTH / 2;
          y = SCREEN_HEIGHT / 2;
        }
    }