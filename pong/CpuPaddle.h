#pragma once
#include "Paddle.h"
#include "Ball.h"

class CpuPaddle : public Paddle {
public:
    CpuPaddle(float x, float y, float speed_y);
    void Update(Ball *ball);
};