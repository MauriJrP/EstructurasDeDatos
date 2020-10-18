#include "../include/song.h"

using namespace std;

Song::Song(){};

Song::Song(const Song &song) : author(song.author), interpreter(song.interpreter), name(song.name), position(song.position), fileName(song.fileName) {}

void Song::setFileName()
{
  fileName = name + ".mp3";
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
