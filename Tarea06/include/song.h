#ifndef __SONG_H__
#define __SONG_H__

#include <iostream>
#include <cstring>

class Song{
private:
  std::string author;
  std::string interpreter;
  std::string name;
  std::string fileName; //automatically linked to the song name
  int position;

  void setFileName();
  static std::string toLower(const std::string &);
public:
  Song();
  Song(const Song&);

  std::string getAuthor() const;
  std::string getInterpreter() const;
  std::string getName() const;
  int getPosition() const;

  void setAuthor(const std::string&);
  void setInterpreter(const std::string&);
  void setName(const std::string&);
  void setPosition(const int&);

  std::string toString();
  static bool compareByAuthor(const Song &, const Song &);
  static bool compareByName(const Song &, const Song &);

  bool operator == (const Song &) const;
  bool operator != (const Song &) const;
  bool operator > (const Song &) const;
  bool operator >= (const Song &) const;
  bool operator < (const Song &) const;
  bool operator <= (const Song &) const;
};

#endif // __SONG_H__


// static int compByName(const Song&, const Song&);

// // Obvio hay que implementar:
// int Song::compByCode(const Song& a, const Song& b) { ...

// // En la implementación del sort de la lista:
// void sortDataBubble(int (const T&,const T&)); /// para comparacion externa

// void sortDataBubble(int (const T&,const T&)); /// para comparacion lazy


// // Y obvio: implementar...
// template <class T, int ARRAYSIZE>
// void List<T, ARRAYSIZE>::sortDataBubble(int comp(const T&,const T&)) { ...
//   if (comp(data[j], data[j + 1]) > 0) { ...


// void List<T, ARRAYSIZE>::sortDataBubble(int comp(const T&,const T&)) { ... /// para lazy


// // En la interfaz de usuario:
// myList.sortDataBubble(Song::compByName);
