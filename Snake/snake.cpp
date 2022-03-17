#include <curses.h>
#include "src/board.hpp"

#define BOARD_DIM 20
#define BOARD_ROWS BOARD_DIM
#define BOARD_COLS BOARD_DIM * 2.5

int main(int argc, char **argv)
{

  initscr();
  refresh();

  Board board(BOARD_ROWS, BOARD_COLS);
  board.initialize();

  board.addAt(5, 5, '#');
  board.refresh();

  getch();
  endwin();

  return 0;
}