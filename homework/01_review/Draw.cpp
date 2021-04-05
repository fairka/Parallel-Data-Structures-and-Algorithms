/*************************************************************************
 *
 * Project: Draw
 *
 * Course:    CPTR 242
 * Date:      March 29, 2021
 */

#include "Draw.h"
#include <functional>
using namespace std;

Draw::Draw() {
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      board[i][j] = ' ';
    }
  }
}

void Draw::drawPoint(int row, int col, char character) {
  board[row][col] = character;
}

void Draw::drawLine(int row, int col, int row2, int col2, char character) {
  if (row == row2 || col == col2) {
    int num = 0;
    if (row > row2) {
      num = row;
      row = row2;
      row2 = num;
    }
    if (col > col2) {
      num = col;
      col = col2;
      col2 = num;
    }

    for (int i = row; i <= row2; i++) {
      for (int j = col; j <= col2; j++) {
        drawPoint(i, j, character);
      }
    }
  } else {
    double vertex = (double)(col2 - col) / (row2 - row);
    int smallR = (row <= row2) ? row : row2;
    int smallC = (col <= col2) ? col : col2;
    int bigR = (row >= row2) ? row : row2;
    int bigC = (row >= row2) ? col : col2;

    for (int i = smallR; i <= bigR; i++) {
      for (int j = smallC; j <= bigC; j++) {
        double point = vertex * (i - row) - (j - col);
        if (point < 0.5 && point > -0.2) {
          drawPoint(i, j, character);
        }
      }
    }
  }
}

void Draw::drawRectangle(int row, int col, int row2, int col2, char character) {
  int smallR = (row <= row2) ? row : row2;
  int smallC = (col <= col2) ? col : col2;
  int bigR = (row >= row2) ? row : row2;
  int bigC = (row >= row2) ? col : col2;

  for (int i = smallR; i <= bigR; i++) {
    for (int j = smallC; j <= bigC; j++) {
      drawPoint(i, j, character);
    }
  }
}

void Draw::drawFun() {
  drawPoint(2, 4, '*');
  drawPoint(2, 6, '*');
  drawPoint(4, 5, '-');
  drawPoint(4, 6, '-');
  drawPoint(4, 4, '-');
  drawPoint(4, 3, '\\');
  drawPoint(4, 7, '/');
}

void Draw::resetVisualization() {
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      board[i][j] = ' ';
    }
  }
}
