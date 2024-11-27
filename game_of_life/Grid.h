#pragma once

#include <vector>
#include "include/raylib.h"

class Grid {
  std::vector< std::vector<int> > data;
  int rows, cols;
  float prob;
  public:
  Grid(int rows, int cols, float prob);
  void Draw();
  int CountNeighbour(int i, int j);
  void Update();
};
