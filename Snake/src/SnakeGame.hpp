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

  void createApple()
  {
    int y, x;
    board.getEmptyCoordinates(y, x);
    apple = new Apple(y, x);
    board.add(*apple);
  }

  void handleNextPiece(SnakePiece next)
  {
    if (apple != NULL && (next.getX() != apple->getX() || next.getY() != apple->getY()))
    {
      int emptyRow = snake.tail().getY();
      int emptyCol = snake.tail().getX();

      board.add(Empty(emptyRow, emptyCol));
      snake.removePiece();
    }
    else
    {
      destroyApple();
    }

    board.add(next);
    snake.addPiece(next);
  }

  void destroyApple()
  {
    delete apple;
    apple = NULL;
  }

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

    handleNextPiece(SnakePiece(1, 1));
    handleNextPiece(snake.nextHead());
    handleNextPiece(snake.nextHead());

    snake.setDirection(right);

    handleNextPiece(snake.nextHead());

    if (apple == NULL)
    {
      createApple();
    }
  }

  void processInput()
  {
    chtype input = board.getInput();

    switch (input)
    {
    case KEY_UP:
    case 'w':
      snake.setDirection(up);
      break;
    case KEY_DOWN:
    case 's':
      snake.setDirection(down);
      break;
    case KEY_RIGHT:
    case 'd':
      snake.setDirection(right);
      break;
    case KEY_LEFT:
    case 'a':
      snake.setDirection(left);
      break;
    case 'p':
      board.setTimeout(-1);
      while (board.getInput() != 'p')
        ;
      board.setTimeout(1000);
      break;
    default:
      break;
    }
  }

  void updateState()
  {
    handleNextPiece(snake.nextHead());

    if (apple == NULL)
    {
      createApple();
    }
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