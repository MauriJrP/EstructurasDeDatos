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

  bool operator == (const Song &) const;
  bool operator != (const Song &) const;
  bool operator > (const Song &) const;
  bool operator >= (const Song &) const;
  bool operator < (const Song &) const;
  bool operator <= (const Song &) const;
};

#endif // __SONG_H__