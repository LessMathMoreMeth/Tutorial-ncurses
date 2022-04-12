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
    return prev_pieces.back();
  }

  SnakePiece head()
  {
    return prev_pieces.front();
  }
};