#include "include/raylib.h"
#include "Ball.h"
#include "Paddle.h"
#include "CpuPaddle.h"
float SCREEN_WIDTH = 1280;
float SCREEN_HEIGHT = 800;
float RADIUS = 15;
float HEIGHT = 120;
float WIDTH = 25;
float PADDING = 20;
int player_score = 0;
int computer_score = 0;

Color Green = Color{38, 185, 154, 255};
Color Dark_Green = Color{20, 160, 133, 255};
Color Light_Green = Color{129, 204, 184, 255};
Color Yellow = Color{243, 213, 91, 255};

#define BALL_SPEED 7
#define PADDLE_SPEED 8

int main () {

    

    Ball ball(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, BALL_SPEED, BALL_SPEED, RADIUS);
    Paddle player(PADDING, (SCREEN_HEIGHT - HEIGHT) / 2, PADDLE_SPEED);
    CpuPaddle computer(SCREEN_WIDTH - PADDING - WIDTH, (SCREEN_HEIGHT - HEIGHT)/2, 6);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "PONG");
    SetTargetFPS(60);
    
    while (WindowShouldClose() == false) {
        BeginDrawing();
        ball.Update();
        player.Update();
        computer.Update(&ball);
        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{player.x, player.y, player.width, player.height})) {
            ball.speed_x *= -1;
        }
        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{computer.x, computer.y, computer.width, computer.height})) {
            ball.speed_x *= -1;
        }
        ClearBackground(Dark_Green);
        DrawRectangle(SCREEN_WIDTH/2, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT, Green);
        DrawCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 100, Light_Green);
        ball.Draw();
        player.Draw();
        computer.Draw();
        DrawLine(SCREEN_WIDTH/2, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT, WHITE);
        DrawText(TextFormat("%d",player_score), SCREEN_WIDTH / 2 - 80, 30, 80, WHITE);
        DrawText(TextFormat("%d",computer_score), SCREEN_WIDTH / 2 + 40, 30, 80, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

