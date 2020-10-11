#ifndef __MENU_H__
#define __MENU_H__

#include <iostream>
#include <cstring>
#include "../include/List.h"
#include "../include/Song.h"

class Menu
{
private:
  int option = 0, intBuffer;
  List playlist;
  // int List playlist = List();
  std::string stringBuffer;
  Song songBuffer = Song();

public:
  Menu();

  void chooseOption();
  void callMethod( const int&);
};

#endif // __MENU_H__