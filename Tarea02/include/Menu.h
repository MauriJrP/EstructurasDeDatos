#ifndef __MENU_H__
#define __MENU_H__

#include <iostream>
#include <cstring>
#include "../include/Inventory.h"

class Menu
{
private:
  int option = 0;
  Inventory inventary = Inventory();
  std::string stringBuffer;
public:
  Menu();

  void chooseOption();
  void callMethod( const int&);
};

#endif // __MENU_H__