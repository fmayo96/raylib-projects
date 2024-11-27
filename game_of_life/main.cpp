#include <iostream>
#include <ctime>
#include "include/raylib.h"
#include "Grid.h"

float SCREEN_WIDTH = 1000;
float SCREEN_HEIGHT = 1000;

int main() {
  srand(time(NULL));
  
  Grid grid(1000,1000, 0.025);

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Game Of Life");
  //SetTargetFPS(60);
  
  while (WindowShouldClose() == false) {
      BeginDrawing();
      ClearBackground(BLACK);
      grid.Draw();
      grid.Update();
      EndDrawing();
  }

  CloseWindow();
}