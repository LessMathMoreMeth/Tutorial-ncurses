// INPUT MODES

#include <curses.h>
#include <string>
#include <iostream>
using namespace std;

int main()
{
  initscr();
  noecho();

  // Input modes
  // cbreak();
  // halfdelay(500);
  // nodelay(stdscr, true);
  // timeout(500);

  int c;
  while ((c = getch()) != 'x')
  {
    printw("%d \n", c);
  }

  // dealloca la memoria e termina curses
  endwin();
}