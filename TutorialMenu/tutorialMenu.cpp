#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include "menu.h"

int main(int argc, char **argv)
{

  initscr();
  noecho();
  curs_set(0);

  int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);

  WINDOW *win = newwin(yMax / 2, xMax / 2, yMax / 4, xMax / 4);
  box(win, 0, 0);

  Menu menus[3] = {
      Menu("File", 'f'),
      Menu("Edit", 'e'),
      Menu("Options", 'o'),
  };

  MenuBar menubar = MenuBar(win, menus, 3);
  menubar.draw();

  char ch;
  while (ch = wgetch(win))
  {
    menubar.handleTrigger(ch);
    menubar.draw();
  }

  endwin();
  return 0;
}

// VERSION 1
// int main(int argc, char **argv)
// {

//   initscr();
//   noecho();
//   curs_set(0);

//   int yMax, xMax;
//   getmaxyx(stdscr, yMax, xMax);

//   WINDOW *win = newwin(yMax / 2, xMax / 2, yMax / 4, xMax / 4);
//   box(win, 0, 0);

//   mvwprintw(win, 0, 2, "File");
//   mvwprintw(win, 0, 7, "Edit");
//   mvwprintw(win, 0, 12, "Options");

//   char ch;
//   while (ch = wgetch(win))
//   {
//     switch (ch)
//     {
//     case 'f':
//       wattron(win, A_STANDOUT);
//       mvwprintw(win, 0, 2, "File");
//       wattroff(win, A_STANDOUT);
//       mvwprintw(win, 0, 7, "Edit");
//       mvwprintw(win, 0, 12, "Options");
//       break;
//     case 'e':
//       wattron(win, A_STANDOUT);
//       mvwprintw(win, 0, 7, "Edit");
//       wattroff(win, A_STANDOUT);
//       mvwprintw(win, 0, 2, "File");
//       mvwprintw(win, 0, 12, "Options");
//       break;
//     case 'o':
//       wattron(win, A_STANDOUT);
//       mvwprintw(win, 0, 12, "Options");
//       wattroff(win, A_STANDOUT);
//       mvwprintw(win, 0, 2, "File");
//       mvwprintw(win, 0, 7, "Edit");
//       break;
//     default:
//       mvwprintw(win, 0, 2, "File");
//       mvwprintw(win, 0, 7, "Edit");
//       mvwprintw(win, 0, 12, "Options");
//       break;
//     }
//   }

//   endwin();
//   return 0;
// }