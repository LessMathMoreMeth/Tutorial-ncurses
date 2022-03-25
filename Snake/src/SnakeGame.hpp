#pragma once

#include <curses.h>
#include "Board.hpp"
#include "Drawable.hpp"

class SnakeGame
{
public:
  SnakeGame(int height, int width)
  {
    board = Board(height, width);
    board.initialize();
    game_over = false;
  }

  void processInput()
  {
    chtype input = board.getInput();
    if (input == 'x')
      game_over = true;
    board.clear();
    board.refresh();
  }

  void updateState()
  {
    board.add(Drawable(3, 3, '#'));
    board.add(Drawable(3, 5, '@'));
  }

  void redraw()
  {
    board.refresh();
  }

  bool isOver()
  {
    return game_over;
  }

private:
  Board board;
  bool game_over;
};