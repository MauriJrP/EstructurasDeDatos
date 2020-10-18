#include "../include/Song.h"

using namespace std;

Song::Song(){};

Song::Song(const Song &song) : author(song.author), interpreter(song.interpreter), name(song.name), position(song.position)  {}

string Song::getAuthor()
{
  return author;
}

string Song::getInterpreter()
{
  return interpreter;
}

string Song::getName()
{
  return name;
}

int Song::getPosition()
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
}

void Song::setPosition(const int &parameter)
{
  position = parameter;
}

string Song::toString()
{
  string song;
  // song += "Posicion: " + to_string(position);
  song += " | Nombre: " + name;
  song += " | Autor: " + author;
  song += " | Interprete: " + interpreter;
  return song;
}
