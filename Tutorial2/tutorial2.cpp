// WINDOWS BASIC

#include <curses.h>
using namespace std;

int main()
{
  // inizializza lo schermo e la memoria
  initscr();

  // creo le variabili che mi servono per creare la window
  int height, width, start_y, start_x;
  height = 10;
  width = 20;
  start_y = start_x = 10;

  // creo un puntatore ad una window
  WINDOW *win = newwin(height, width, start_y, start_x);

  // serve per visualizzare a schermo la finestra che abbiamo appena creato
  refresh();

  // creo un box all'interno della window
  box(win, 0, 0);

  // questa funzione mi permette di stampare all'interno di una finestra
  // wprintw(win, "this is my box");

  mvwprintw(win, 4, 1, "__this is my box__");

  // analogo di refresh ma esegue il refresh solamente della finestra e non dell'intero schermo
  wrefresh(win);

  // funzione che aspetta per l'input dell'utente e ritorna l'int value del tasto premuto
  int c = getch();

  // dealloca la memoria e termina curses
  endwin();

  return 0;
}