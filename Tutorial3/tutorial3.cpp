// BORDERS AND OTHER USEFUL FUNCTION

#include <curses.h>
using namespace std;

int main()
{
  // inizializza lo schermo e la memoria
  initscr();

  // attivdando questa fuznione possiamo chiudere il programma premendo cntr + c
  // cbreak();

  // attivando questa funzione non consideriamo i caratteri speciali, ad esempio cntr + c non funzionerà
  // raw();

  // attivando questa funzione qualsiasi input l'utente inserirà non verrà stampato a schermo
  // noecho();

  // creo le variabili che mi servono per creare la window
  int height, width, start_y, start_x;
  height = 10;
  width = 20;
  start_y = start_x = 10;

  // creo un puntatore ad una window
  WINDOW *win = newwin(height, width, start_y, start_x);

  // serve per visualizzare a schermo la finestra che abbiamo appena creato
  refresh();

  // creo un box all'interno della window con i bordi specificati
  // il primo parametro specifica i bordi destri e sinistri il secondo parametro specifica i bordi in alto e in basso
  box(win, 103, 104);

  // abbiamo il controllo su tutti bordi della box con la seguente funzione che permette di specificare quale carattere usare per ogni bordo e angolo
  int left, right, top, bottom, tlc, trc, blc, brc;
  left = right = 103;
  top = bottom = 104;
  tlc = trc = blc = brc = '+';
  wborder(win, left, right, top, bottom, tlc, trc, blc, brc);

  // questa funzione mi permette di stampare all'interno di una finestra
  // wprintw(win, "this is my box");

  mvwprintw(win, 4, 1, "__this is my box__");

  // analogo di refresh ma esegue il refresh solamente della finestra e non dell'intero schermo
  wrefresh(win);

  getch();
  getch();

  // dealloca la memoria e termina curses
  endwin();

  return 0;
}