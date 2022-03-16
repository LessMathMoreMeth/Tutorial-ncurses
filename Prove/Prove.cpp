#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

int main(int argc, char **argv)
{

  initscr();
  noecho();
  curs_set(0);

  int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);

  WINDOW *win = newwin(yMax / 2, xMax / 2, yMax / 4, xMax / 4);
  box(win, 0, 0);

  mvwprintw(win, 0, 2, "File");
  mvwprintw(win, 0, 7, "Edit");
  mvwprintw(win, 0, 12, "Options");

  char ch;
  while (ch = wgetch(win))
  {
    switch (ch)
    {
    case 'f':
      wattron(win, A_STANDOUT);
      mvwprintw(win, 0, 2, "File");
      wattroff(win, A_STANDOUT);
      break;
    case 'e':
      break;
    case 'o':
      break;
    default:
      break;
    }
  }

  endwin();
  return 0;
}