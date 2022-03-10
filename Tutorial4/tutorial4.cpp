// ATTRIBUTES AND COLORS

#include <curses.h>
using namespace std;

int main()
{
  // inizializza lo schermo e la memoria
  initscr();

  // funzione per controllare se il terminale supporta i colori
  if (!has_colors())
  {
    printw("Terminal does not support colors");
    getch();
    return -1;
  }

  // funzione per controllare se posso cambiare i colori
  if (!can_change_color())
  {
    printw("Cant change color \n");
  }

  // funzione per inizializzare l'utilizzo dei colori
  start_color();

  // funzione per definire una nuova coppia di colori che verrà utilizzata in seguito
  init_pair(1, COLOR_CYAN, COLOR_WHITE);

  /*
  A_NORMAL --> The string get printed like no attribute is set
  A_STANDOUT --> The string get printed like no attribute is set
  A_REVERSE --> The string get printed like no attribute is set
  A_BLINK --> Wrong char are printed
  A_BOLD --> The string get printed like no attribute is set
  A_PROTECT --> The string get printed like the A_REVERSE of the video
  A_INVIS --> The string get printed like no attribute is set
  A_ALTCHARSET --> The string get printed like the A_REVERSE of the video
  A_CHARTEXT --> The string get printed like no attribute is set
  */

  attron(A_BLINK);
  printw("This is some text");
  attroff(A_BLINK);

  /*
  COLOR_PAIR(n)
  COLOR_BLACK 0
  COLOR_RED 1
  COLOR_GREEN 2
  COLOR_YELLOW 3
  COLOR_BLUE 4
  COLOR_MAGENTA 5
  COLOR_CYAN 6
  COLOR_WHITE 7
  */

  getch();

  // dealloca la memoria e termina curses
  endwin();

  return 0;
}