#pragma once

#include <curses.h>
#include <time.h>
#include <stdlib.h>
#include "Board.hpp"
#include "Drawable.hpp"
#include "Apple.hpp"
#include "Empty.hpp"
#include "Snake.hpp"

class SnakeGame
{
private:
  Board board;
  bool game_over;
  Apple *apple;
  Snake snake;

public:
  SnakeGame(int height, int width)
  {
    board = Board(height, width);
    initialize();
  }

  ~SnakeGame()
  {
    delete apple;
  }

  void initialize()
  {
    apple = NULL;
    board.initialize();
    game_over = false;
    srand(time(NULL));

    snake.setDirection(down);

    SnakePiece next = SnakePiece(1, 1);
    board.add(next);
    snake.addPiece(next);

    next = snake.nextHead();
    board.add(next);
    snake.addPiece(next);

    next = snake.nextHead();
    board.add(next);
    snake.addPiece(next);

    snake.setDirection(right);

    next = snake.nextHead();
    board.add(next);
    snake.addPiece(next);
  }

  void processInput()
  {
    chtype input = board.getInput();
  }

  void updateState()
  {
    if (apple == NULL)
    {
      int y, x;
      board.getEmptyCoordinates(y, x);
      apple = new Apple(y, x);
      board.add(*apple);
    }

    SnakePiece next = snake.nextHead();
    if (next.getX() != apple->getX() && next.getY() != apple->getY())
    {
      int emptyRow = snake.tail().getY();
      int emptyCol = snake.tail().getX();

      board.add(Empty(emptyRow, emptyCol));
      snake.removePiece();
    }

    board.add(next);
    snake.addPiece(next);
  }

  void redraw()
  {
    board.refresh();
  }

  bool isOver()
  {
    return game_over;
  }
};