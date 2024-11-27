#include <vector>
#include <iostream>
#include <ctime>
#include "include/raylib.h"


int SCREEN_WIDTH = 800;
int SCREEN_HEIGHT = 600;
int SIZE = 10;


#define SPEED 1
#define INIT_LEN 6 // size in squares (10px x 10px)

enum direction {
    UP, 
    DOWN, 
    LEFT, 
    RIGHT,    
};

class Snake {
    public:
    int length;
    direction dir;
    std::vector<int> X; 
    std::vector<int> Y; // X[0], Y[0] is the head
    Snake() {
        length = INIT_LEN;
        dir = direction::RIGHT;
        X.push_back(10*SIZE);
        Y.push_back(10*SIZE);
        for (int i = 1; i < length; i++) {
            X.push_back(X[i-1] - SIZE);
            Y.push_back(Y[i-1]);
        }
    }
    void Draw() {
        for(int i = 0; i < length; i++) {
            DrawRectangle(X[i], Y[i], SIZE, SIZE, WHITE);
        }
    }
    void Update() {
        if (IsKeyPressed(KEY_DOWN)) {
            if (dir !=direction::UP) {
                dir = direction::DOWN;
            }
        }
        if (IsKeyPressed(KEY_UP)) {
            if (dir !=direction::DOWN) {
                dir = direction::UP;
            }
        }
        if (IsKeyPressed(KEY_LEFT)) {
            if (dir !=direction::RIGHT) {
                dir = direction::LEFT;
            }
        }
        if (IsKeyPressed(KEY_RIGHT)) {
            if (dir !=direction::LEFT) {
                dir = direction::RIGHT;
            }
        }
        int i;
        for(i = 1; i < length; i++) {
                X[i] = X[i-1];
                Y[i] = Y[i-1];
            } 
        switch (dir)
        {
        case direction::RIGHT:
            X[0] += SPEED*SIZE;
            break;
        case direction::LEFT:
            X[0] -=SPEED*SIZE;
            break;
        case direction::UP:
            Y[0] -= SPEED*SIZE;
            break;
        case direction::DOWN:
            Y[0] += SPEED*SIZE;
            break;
        default:
            break;
        }
    }
    void Grow() {
        switch (dir)
        {
        case direction::RIGHT:
            X.push_back(X[length - 1] - SIZE);
            Y.push_back(Y[length - 1]);
            break;
        case direction::LEFT:
            X.push_back(X[length - 1] + SIZE);
            Y.push_back(Y[length - 1]);
            break;
        case direction::UP:
            X.push_back(X[length - 1]);
            Y.push_back(Y[length - 1] + SIZE);
            break;
        case direction::DOWN:
            X.push_back(X[length - 1]);
            Y.push_back(Y[length - 1] - SIZE);
            break;
        default:
            break;
        }
        ++length;
    }
};

class Food {
    public:
    int x, y;
    Food() {
        x = rand() % (780 + 1 - 2) + 2;
        y = rand() % (580 + 1 - 2) + 2;
    }
    void Draw() {
        DrawRectangle(x, y, SIZE, SIZE, RED);
    }
    void Update() {
        x = rand() % (780 + 1 - 20) + 20;
        y = rand() % (580 + 1 - 20) + 20;
    }
};

int main () {
    srand(time(NULL));
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "SNAKE");
    SetTargetFPS(60);
    
   Snake snake;
   Food food;
   
    while (WindowShouldClose() == false) {
        snake.Update();
        if (CheckCollisionRecs(Rectangle{(float)snake.X[0], (float)snake.Y[0], (float)SIZE, (float)SIZE}, Rectangle{(float)food.x, (float)food.y, (float)SIZE, (float)SIZE})) {
            food.Update();
            snake.Grow();
            snake.Draw();
        }
        BeginDrawing();
        ClearBackground(BLACK);
        snake.Draw();
        food.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

