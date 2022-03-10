// GETTING INFO ABOUT THE TERM

#include <curses.h>
using namespace std;

int main()
{
  // inizializza lo schermo e la memoria
  initscr();
  noecho();
  cbreak();

  int y, x, yBeg, xBeg, yMax, xMax;

  WINDOW *win = newwin(10, 20, 10, 10);

  move(29, 99); // con queste coordinate la stampa avviene nell'ultima riga senza lsciare spazi in fondo

  // questa funzione ritorna la posizione del cursore modificando i parametri x, y passati in input
  getyx(stdscr, y, x);
  // questa funzione ritorna la posizione dell'angolo in alto a sinistra della finestra, posso vederlo come l'inizio della finestra
  getbegyx(stdscr, yBeg, xBeg);
  // questa funzione ritorna la posizione dell'angolo in basso a destra della finestra, posso vederlo come la fine della finestra
  getmaxyx(stdscr, yMax, xMax);

  // stampo tutte le informazioni appena calcolate
  printw("%d, %d, %d, %d, %d, %d", y, x, yBeg, xBeg, yMax, xMax);

  // posso utilizzare le variabili per piazzare al centro le informazioni ad esempio
  // in questo caso calcoliamo la metà per ogni dimensione e stampiamo il valore di inizio della finestra
  // mvprintw(yMax / 2, xMax / 2, "%d %d", yBeg, xBeg);

  getch();

  // dealloca la memoria e termina curses
  endwin();

  return 0;
}