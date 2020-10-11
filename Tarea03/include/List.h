#ifndef __LIST_H__
#define __LIST_H__

#include <iostream>
#include <cstring>
#include "../include/Song.h"
#define SIZE 50
// typedef Song Song;

// template <class Song>

class List
{
private:
  Song list[SIZE];
  int lastValue;

  bool isValid(const int&);
public:
  // List<Song>();
  List();
  // List(const List&);

  bool isEmpty();
  bool isFull();
  void insert(const Song&, const int&); //data, positon
  void remove(const int&);
  int first();
  int last();
  int previous(const int&);
  int next(const int&);
  int find(Song&);
  Song recover(const int&);
  void sort();
  void print();
  void reset();
};


#endif // __LIST_H__