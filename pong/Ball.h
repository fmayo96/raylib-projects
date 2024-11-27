#pragma once

class Ball {
public:
    float x, y, speed_x, speed_y;
    int radius;
    Ball (float x, float y, float speed_x, float speed_y, int radius);
    void Draw();
    void Update();
};