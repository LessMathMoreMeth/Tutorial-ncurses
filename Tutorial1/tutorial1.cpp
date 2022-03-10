// MOVING CURSOR

#include <curses.h>
using namespace std;

int main()
{
  // inizializza lo shermo e la memoria
  initscr();
  int x, y;
  x = y = 10;

  // sposta il cursore ad una posizione specificata
  move(y, x);

  // stampa una stringa in una finestra
  printw("Hello World!");

  // funzione che aspetta per l'input dell'utente e ritorna l'int value del tasto premuto
  int c = getch();

  // funzione per pulire lo schermo nel nostro caso la utilizziamo per cancellare hello world quando l'utente preme un tasto
  clear();

  // risposto il cursore alla posizione 0,0
  move(0, 0);

  // utilizzo la varibile c in cui è stato salvato il tasto premuto dall utente per stampare il suo valore intero
  // mvprintw(0, 0, "%d", c); --> Comando unico per move + print
  printw("%d", c);

  // aspetto che l'utente prema un altro tasto prima di uscire dal programma in modo da vedere gli effetti del comando precedente
  getch();

  // dealloca la memoria e termina curses
  endwin();

  return 0;
}