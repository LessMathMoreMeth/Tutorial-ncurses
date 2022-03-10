// HELLO WORLD!

#include <curses.h>
using namespace std;

int main()
{
  // inizializza lo shermo e la memoria
  initscr();

  // stampa una stringa in una finestra
  printw("Hello World!");

  // aggiorna lo schermo per visualizzare quello che abbiamo in meoria
  refresh();

  // funzione che aspetta per l'input dell'utente e ritorna l'int value del tasto premuto
  int c = getch();

  // utilizzo la varibile c in cui è stato salvato il tasto premuto dall utente per stampare il suo valore intero
  printw("%d", c);

  // aspetto che l'utente prema un altro tasto prima di uscire dal programma in modo da vedere gli effetti del comando precedente
  getch();

  // dealloca la memoria e termina curses
  endwin();

  return 0;
}