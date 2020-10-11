#ifndef __SONG_H__
#define __SONG_H__

#include <iostream>
#include <cstring>

class Song{
private:
  std::string author;
  std::string interpreter;
  std::string name;
  int position;

public:
  Song();
  Song(const Song&);

  std::string getAuthor();
  std::string getInterpreter();
  std::string getName();
  int getPosition();

  void setAuthor(const std::string&);
  void setInterpreter(const std::string&);
  void setName(const std::string&);
  void setPosition(const int&);

  std::string toString();
};

#endif // __SONG_H__