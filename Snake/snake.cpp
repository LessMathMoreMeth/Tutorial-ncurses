#include <curses.h>
#include "src/SnakeGame.hpp"
#include "src/board.hpp"
#include "src/Drawable.hpp"

#define BOARD_DIM 20
#define BOARD_ROWS BOARD_DIM
#define BOARD_COLS BOARD_DIM * 2.5

int main(int argc, char **argv)
{

  initscr();
  refresh();
  noecho();

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

  return 0;
}