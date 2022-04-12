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
    if (apple != NULL)
    {
      switch (board.getCharAt(next.getY(), next.getX()))
      {
      case 'A':
        destroyApple();
        break;
      case ' ':
      {
        int emptyRow = snake.tail().getY();
        int emptyCol = snake.tail().getX();

        board.add(Empty(emptyRow, emptyCol));
        snake.removePiece();
        break;
      }
      default:
        game_over = true;
        break;
      }
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

    snake.setDirection(direction_down);

    handleNextPiece(SnakePiece(1, 1));
    handleNextPiece(snake.nextHead());
    handleNextPiece(snake.nextHead());

    snake.setDirection(direction_right);

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
      snake.setDirection(direction_up);
      break;
    case KEY_DOWN:
    case 's':
      snake.setDirection(direction_down);
      break;
    case KEY_RIGHT:
    case 'd':
      snake.setDirection(direction_right);
      break;
    case KEY_LEFT:
    case 'a':
      snake.setDirection(direction_left);
      break;
    case 'p':
      board.setTimeout(-1);
      while (board.getInput() != 'p')
        ;
      board.setTimeout(1000);
      break;
    case 'x':
      game_over = true;
      board.clear();
      board.refresh();
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