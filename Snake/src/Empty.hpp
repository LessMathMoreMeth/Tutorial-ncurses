#pragma once

#include <curses.h>
#include "Drawable.hpp"

class Empty : public Drawable
{
public:
  Empty(int y, int x)
  {
    this->y = y;
    this->x = x;
    this->icon = ' ';
  }
};