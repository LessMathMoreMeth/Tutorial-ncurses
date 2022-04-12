#pragma once

#include <curses.h>
#include <queue>
#include "Drawable.hpp"

using namespace std;

enum Direction
{
  up,
  down,
  left,
  right
};

class SnakePiece : public Drawable
{
public:
  SnakePiece()
  {
    this->x = 0;
    this->y = 0;
    this->icon = '#';
  }

  SnakePiece(int y, int x)
  {
    this->x = x;
    this->y = y;
    this->icon = '#';
  }
};

class Snake
{
protected:
  queue<SnakePiece> prev_pieces;
  Direction cur_direction;

public:
  Snake()
  {
    cur_direction = down;
  }

  void addPiece(SnakePiece piece)
  {
    prev_pieces.push(piece);
  }

  void removePiece()
  {
    prev_pieces.pop();
  }

  SnakePiece tail()
  {
    return prev_pieces.front();
  }

  SnakePiece head()
  {
    return prev_pieces.back();
  }

  Direction getDirection()
  {
    return cur_direction;
  }

  void setDirection(Direction d)
  {
    cur_direction = d;
  }

  SnakePiece nextHead()
  {
    int row = head().getY();
    int col = head().getX();

    switch (cur_direction)
    {
    case down:
      row++;
      break;
    case up:
      row--;
      break;
    case right:
      col++;
      break;
    case left:
      col--;
      break;
    }

    return SnakePiece(row, col);
  }
};