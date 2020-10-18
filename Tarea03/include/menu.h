#ifndef __MENU_H__
#define __MENU_H__

#include <iostream>
#include <cstring>
#include "../include/list.h"
#include "../include/song.h"

class Menu
{
private:
  int option = 0, intBuffer;
  std::string stringBuffer;
  Song songBuffer = Song();

  void callMethod( const int&, List<Song> &);
  void userInterface(List<Song> &);
  std::string getInputNameSong();
public:
  Menu(List<Song> &);

};

#endif // __MENU_H__