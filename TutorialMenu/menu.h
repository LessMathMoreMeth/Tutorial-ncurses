#include <curses.h>
#include <string>

using namespace std;

#ifndef _MENU_H_
#define _MENU_H_

class Menu
{
public:
  int start_x;
  string text;
  char trigger;

  Menu(string text, char trigger)
  {
    this->text = text;
    this->trigger = trigger;
  }
};

class MenuBar
{
public:
  WINDOW *win;
  Menu *menus;
  int num_menus;
  int current_position;
  int selected_menu;

  MenuBar(WINDOW *win, Menu *menus, int num_menus)
  {
    this->win = win;
    this->menus = menus;
    this->num_menus = num_menus;
    this->current_position = 2;
    this->selected_menu = -1;

    for (int i = 0; i < num_menus; i++)
    {
      this->menus[i].start_x = current_position;
      current_position += this->menus[i].text.length() + 1;
    }
  }

  void draw()
  {
    for (int i = 0; i < num_menus; i++)
    {
      if (selected_menu == i)
      {
        wattron(win, A_STANDOUT);
      }
      mvwprintw(win, 0, this->menus[i].start_x, this->menus[i].text.c_str());
      wattroff(win, A_STANDOUT);
    }
  }

  void handleTrigger(char trigger)
  {
    for (int i = 0; i < num_menus; i++)
    {
      if (trigger == this->menus[i].trigger)
      {
        selected_menu = i;
      }
      else
      {
        selected_menu = -1;
      }
    }
  }
};

#endif