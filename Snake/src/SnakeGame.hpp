#pragma once

#include <curses.h>
#include <time.h>
#include <stdlib.h>
#include "Board.hpp"
#include "Drawable.hpp"
#include "Apple.hpp"
#include "Empty.hpp"

class SnakeGame
{
public:
  SnakeGame(int height, int width)
  {
    board = Board(height, width);
    board.initialize();
    game_over = false;
    srand(time(NULL));
  }

  ~SnakeGame()
  {
    delete apple;
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
    int y, x;
    board.getEmptyCoordinates(y, x);
    if (apple != NULL)
      board.add(Empty(apple->getY(), apple->getX()));
    apple = new Apple(y, x);
    board.add(*apple);
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
  Apple *apple;
};