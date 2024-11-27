#include "Grid.h"

float PIXEL_SIZE = 1;

Grid::Grid(int rows, int cols, float prob) {
    int i,j;
    this->rows = rows;
    this->cols = cols;
    data.resize(rows, std::vector<int>(cols, 0));
    for (i = 0; i < rows; ++i) {
      for (j = 0; j < cols; ++j) {
        data[i][j] = (((float)rand() / RAND_MAX) < prob)? 1 : 0;
      }
    }
  }

void Grid::Draw() {
    int i, j;
    for (i = 0; i < rows; ++i) {
      for(j = 0; j < cols; ++j) {
        data[i][j]? DrawRectangle(i*PIXEL_SIZE, j*PIXEL_SIZE, PIXEL_SIZE, PIXEL_SIZE, WHITE) : DrawRectangle(i*10, j*10, 10, 10, BLACK);
      }
    }
  }

int Grid::CountNeighbour(int i, int j) {
    int count = 0;
    count = data[(i + rows + 1) % rows][j] + data[(i + rows - 1) % rows][j] + data[i][(j + rows + 1) % rows] + data[i][(j + rows - 1) % rows] + data[(i + rows + 1) % rows][(j + rows + 1) % rows] + data[(i + rows + 1) % rows][(j + rows - 1) % rows] + data[(i + rows - 1) % rows][(j + rows + 1) % rows] + data[(i + rows - 1) % rows][(j + rows - 1) % rows];
    return count;
  }

void Grid::Update() {
    int i, j, count;
    for (i = 0; i < rows; ++i) {
      for (j = 0; j < cols; ++j) {
        if (data[i][j]) {
          count = CountNeighbour(i,j);
          if (count < 2 || count > 3) {
            data[i][j] = 0;
          }
        } else {
          count = CountNeighbour(i,j);
          if (count == 3) {
            data[i][j] = 1;
          }
        } 
      }
    }
  }