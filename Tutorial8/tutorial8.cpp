// BASIC TOP-DOWN PLAYER MOVEMENT

#include <curses.h>
#include <string>
#include <iostream>
#include "player.h"
using namespace std;

int main()
{
  initscr();
  noecho();
  cbreak();

  // ottengo le dimensioni massime della schermata
  int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);

  // creo una finestra per l'input
  WINDOW *playwin = newwin(20, 50, (yMax / 2) - 10, 10);
  box(playwin, 0, 0);
  refresh();
  wrefresh(playwin);

  Player *p = new Player(playwin, 1, 1, '@');

  do
  {
    p->display();
    wrefresh(playwin);
  } while (p->getmv() != 'x');

  // dealloca la memoria e termina curses
  endwin();
}