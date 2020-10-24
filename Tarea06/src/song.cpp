#include "../include/song.h"

using namespace std;

Song::Song(){};

Song::Song(const Song &song) : author(song.author), interpreter(song.interpreter), name(song.name), position(song.position), fileName(song.fileName) {}

void Song::setFileName()
{
  fileName = name + ".mp3";
}

std::string Song::toLower(const string &value)
{
  string stringBuffer{""};
  for ( int i{0}; i < value.length(); i++ ) {
    stringBuffer += tolower(value[i]);
  }
  return stringBuffer;
}

string Song::getAuthor() const
{
  return author;
}

string Song::getInterpreter() const
{
  return interpreter;
}

string Song::getName() const
{
  return name;
}

int Song::getPosition() const
{
  return position;
}

void Song::setAuthor(const string &parameter)
{
  author = parameter;
}

void Song::setInterpreter(const string &parameter)
{
  interpreter = parameter;
}

void Song::setName(const string &parameter)
{
  name = parameter;
  setFileName();
}

void Song::setPosition(const int &parameter)
{
  position = parameter;
}

string Song::toString()
{
  string song;
  song += " | Nombre: " + name;
  song += " | Autor: " + author;
  song += " | Interprete: " + interpreter;
  song += " | Archivo: " + fileName;
  return song;
}

bool Song::compareByAuthor(const Song &a, const Song &b)
{
  string stringA{toLower(a.author)};
  string stringB{toLower(b.author)};
  return stringA > stringB;
}

bool Song::compareByName(const Song &a, const Song &b)
{
  string stringA{toLower(a.name)};
  string stringB{toLower(b.name)};
  return stringA > stringB;
}

bool Song::operator==(const Song &value) const
{
  return value.fileName == fileName;
}

bool Song::operator!=(const Song &value) const
{
  return value.fileName != fileName;
}

bool Song::operator>(const Song &value) const
{
  return value.fileName > fileName;
}

bool Song::operator>=(const Song &value) const
{
  return value.fileName >= fileName;
}

bool Song::operator<(const Song &value) const
{
  return value.fileName < fileName;
}

bool Song::operator<=(const Song &value) const
{
  return value.fileName <= fileName;
}
