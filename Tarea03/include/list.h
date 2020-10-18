#ifndef __LIST_H__
#define __LIST_H__

#include <iostream>
#include <cstring>
#include "../include/song.h"


// -------- ------- ------ ----- List Exception ----- ------ ------- --------

class ListException : public std::exception {
private:
  std::string msg;

public:
  explicit ListException(const char* message) : msg(message) { }

  explicit ListException(const std::string& message) : msg(message) {}

  virtual ~ListException() throw () {}

  virtual const char* what() const throw () {
    return msg.c_str();
  }
};

// -------- ------- ------ ----- Definition ----- ------ ------- --------

template <class T, int ARRAYSIZE = 50>
class List
{
private:
  T data[ARRAYSIZE];
  int lastValue;

  bool isValid(const int &);
  void copyAll(const List<T, ARRAYSIZE> &);

public:
  List();
  List(const List<T, ARRAYSIZE> &);

  bool isEmpty();
  bool isFull();
  void insert(const T &, const int &); //data, positon
  void remove(const int &);
  int first();
  int last();
  int previous(const int &);
  int next(const int &);
  int linearSearch(T &);
  int binarySearch(T &);
  T recover(const int &);
  void sort();
  void print();
  void reset();
};

// -------- ------- ------ ----- Implementation ----- ------ ------- --------
using namespace std;
template <class T, int ARRAYSIZE>
List<T, ARRAYSIZE>::List()
{
  lastValue = -1;
}

template <class T, int ARRAYSIZE>
bool List<T, ARRAYSIZE>::isValid(const int &position)
{
  return (position > -1 && position <= lastValue);
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::copyAll(const List<T, ARRAYSIZE> &)
{
}

template <class T, int ARRAYSIZE>
bool List<T, ARRAYSIZE>::isEmpty()
{
  return lastValue == -1;
}

template <class T, int ARRAYSIZE>
bool List<T, ARRAYSIZE>::isFull()
{
  return lastValue == ARRAYSIZE - 1;
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::insert(const T &value, const int &position)
{
  if ( isFull() ) {
    throw ListException("Desbordamiento de datos, Insertar");
  }
  if ( position != -1 && !isValid(position) )
  {
    throw ListException("Posicion invalida, Insertar");
  }
  for (int i = lastValue; i > position; i--)
  {
    data[i + 1] = data[i];
  }
  data[position + 1] = value;
  lastValue++;
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::remove(const int &position)
{
  if ( isEmpty() ) {
    throw ListException("Insuficiencia de datos, Eliminar");
  }
  if ( !isValid(position) )
  {
    throw ListException("Posicion Invalida, Eliminar");
  }
  else
  {
    for (int i{position}; i < lastValue; i++)
    {
      data[i] = data[i + 1];
    }
    lastValue--;
  }
}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::first()
{
  return isEmpty() ? -1 : 0;
}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::last()
{
  return isEmpty() ? -1 : lastValue;
}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::previous(const int &position)
{
  if (isEmpty() || !isValid(position) || position == 0)
  {
    return -1;
  }
  else
  {
    return position - 1;
  }
}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::next(const int &position)
{
  if (isEmpty() || !isValid(position) || position == ARRAYSIZE - 1)
    return -1;
  else
    return position + 1;
}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::linearSearch(T &value)
{
  for (int i = 0; i <= lastValue; i++)
  {
    if (data[i] == value)
      return i;
  }
  return -1;
}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::binarySearch(T &value)
{
  int i{0};
  int j{lastValue};
  int half{0};
  while( i < j ) {
    half = (i + j) / 2;

    if ( data[half] == value ) return half;

    if ( value < data[half] ) j = half - 1;

    if ( value > data[half] ) i = half + 1;
  }
  return -1;
}

template <class T, int ARRAYSIZE>
T List<T, ARRAYSIZE>::recover(const int &position)
{
  if ( isEmpty() ) {
    throw ListException("Insuficiencia de datos, Recuperar");
  }
  if ( !isValid(position) ) {
    throw ListException("Posicion Invalida, Recuperar");
  }

  return data[position];
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::sort()
{
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::print()
{
  for (int i = 0; i <= lastValue; i++)
  {
    std::cout << "Posicion: " + to_string(i) << data[i].toString() << endl;
  }
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::reset()
{
  lastValue = -1;
}

#endif // __LIST_H__