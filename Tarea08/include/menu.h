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
  List<Song> myList2;


  void userInterface(List<Song> &);
  std::string getInputNameSong();
  std::string getInputInterpreter();
  void chooseSearchMethod(List<Song> &, const int &, Song &);
  void chooseSortMethod(List<Song> &, const int &);
  void callMethod( const int&, List<Song> &);
public:
  Menu(List<Song> &);

};

#endif // __MENU_H__