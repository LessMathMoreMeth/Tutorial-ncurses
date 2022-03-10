// WORKING WITH USER INPUT

#include <curses.h>
#include <string>
#include <iostream>
using namespace std;

int main()
{
  // inizializza lo schermo e la memoria
  initscr();
  noecho();
  cbreak();

  // ottengo le dimensioni massime della schermata
  int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);

  // creo una finestra per l'input
  WINDOW *inputwin = newwin(3, xMax - 12, yMax - 5, 5);
  box(inputwin, 0, 0);
  refresh();
  wrefresh(inputwin);

  // funzione che abilita KEY_*
  keypad(inputwin, true);

  // ciclo che stampa ad ogni iterazione la freccietta corrispondente
  while (true)
  {
    int c = wgetch(inputwin);
    // per cancellare i vecchi output
    wclear(inputwin);

    if (c == KEY_UP)
    {
      mvwprintw(inputwin, 1, 1, "you pressed up!");
      wrefresh(inputwin);
    }
    else if (c == KEY_DOWN)
    {
      mvwprintw(inputwin, 1, 1, "you pressed down!");
      wrefresh(inputwin);
    }
    else if (c == KEY_LEFT)
    {
      mvwprintw(inputwin, 1, 1, "you pressed left!");
      wrefresh(inputwin);
    }
    else if (c == KEY_RIGHT)
    {
      mvwprintw(inputwin, 1, 1, "you pressed right!");
      wrefresh(inputwin);
    }
  }

  // dealloca la memoria e termina curses
  endwin();

  return 0;
}