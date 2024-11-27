#pragma once
#include "include/raylib.h"

extern float WIDTH;
extern float HEIGHT;

class Paddle {
public:
    float x, y, speed_y;
    float width=WIDTH, height=HEIGHT;
    
    Paddle (float x, float y, float speed_y);
    
    void Draw();
    
    void Update();
};
