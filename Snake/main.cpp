#include <curses.h>
#include <iostream>
#include "src/SnakeGame.hpp"
#include "src/board.hpp"
#include "src/Drawable.hpp"

using namespace std;

#define BOARD_DIM 20
#define BOARD_ROWS BOARD_DIM
#define BOARD_COLS BOARD_DIM * 2.5

int main(int argc, char **argv)
{

  initscr();
  refresh();
  noecho();
  cbreak();
  curs_set(0);

  SnakeGame game(BOARD_ROWS, BOARD_COLS);

  while (!game.isOver())
  {
    // 1: get input from user
    game.processInput();

    // 2: update game state
    game.updateState();

    // 3: redraw display
    game.redraw();
  }

  getch();
  endwin();

  cout << "Gameover" << endl;

  return 0;
}