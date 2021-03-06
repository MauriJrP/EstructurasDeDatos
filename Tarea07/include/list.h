#ifndef __LIST_H__
#define __LIST_H__

#include <iostream>
#include <cstring>

// -------- ------- ------ ----- List Exception ----- ------ ------- --------

class ListException : public std::exception
{
private:
  std::string msg;

public:
  explicit ListException(const char *message) : msg(message) {}

  explicit ListException(const std::string &message) : msg(message) {}

  virtual ~ListException() throw() {}

  virtual const char *what() const throw()
  {
    return msg.c_str();
  }
};

// -------- ------- ------ ----- Definition ----- ------ ------- --------

template <class T, int ARRAYSIZE = 50>
class List
{
private:
  T data[ARRAYSIZE];
  static int lastValue;

  bool isValid(const int &);
  void copyAll(const List<T, ARRAYSIZE> &);
  void swapData(T &, T &);
  static bool greaterThan(const T &, const T &);
  static bool lessThanOrEqualTo(const T &, const T &);

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

  void bubbleSort(bool (*comp)(const T &a, const T &b) = List::greaterThan);
  void insertSort(bool (*comp)(const T &a, const T &b) = List::greaterThan);
  void selectSort(bool (*comp)(const T &a, const T &b) = List::greaterThan);
  void shellSort(bool (*comp)(const T &a, const T &b) = List::greaterThan);
  void mergeSort(const int &left = 0, const int &right = lastValue, bool (*comp)(const T &a, const T &b) = List::lessThanOrEqualTo);
  void quickSort(const int &left = 0, const int &right = lastValue, bool (*comp)(const T &a, const T &b) = List::lessThanOrEqualTo);

  void print();
  void reset();

  void operator=(const List<T, ARRAYSIZE> &);
};

// -------- ------- ------ ----- Implementation ----- ------ ------- --------
using namespace std;

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::lastValue = -1;

template <class T, int ARRAYSIZE>
List<T, ARRAYSIZE>::List()
{
  lastValue = -1;
}

template <class T, int ARRAYSIZE>
List<T, ARRAYSIZE>::List(const List<T, ARRAYSIZE> &newList)
{
  copyAll(newList);
}

template <class T, int ARRAYSIZE>
bool List<T, ARRAYSIZE>::isValid(const int &position)
{
  return (position > -1 && position <= lastValue);
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::copyAll(const List<T, ARRAYSIZE> &newList)
{
  for (int i(0); i <= newList.lastValue; i++)
  {
    this->data[i] = newList.data[i];
  }

  this->lastValue = newList.lastValue;
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::swapData(T &a, T &b)
{
  T aux{a};
  a = b;
  b = aux;
}

template <class T, int ARRAYSIZE>
bool List<T, ARRAYSIZE>::greaterThan(const T &a, const T &b)
{
  return a > b;
}

template<class T, int ARRAYSIZE>
bool List<T, ARRAYSIZE>::lessThanOrEqualTo(const T &a, const T &b)
{
  return a <= b;
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
  if (isFull())
  {
    throw ListException("Desbordamiento de datos, Insertar");
  }
  if (position != -1 && !isValid(position))
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
  if (isEmpty())
  {
    throw ListException("Insuficiencia de datos, Eliminar");
  }
  if (!isValid(position))
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
  while (i < j)
  {
    half = (i + j) / 2;

    if (data[half] == value)
      return half;

    if (value < data[half])
      j = half - 1;

    if (value > data[half])
      i = half + 1;
  }
  return -1;
}

template <class T, int ARRAYSIZE>
T List<T, ARRAYSIZE>::recover(const int &position)
{
  if (isEmpty())
  {
    throw ListException("Insuficiencia de datos, Recuperar");
  }
  if (!isValid(position))
  {
    throw ListException("Posicion Invalida, Recuperar");
  }

  return data[position];
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::bubbleSort(bool (*comp)(const T &a, const T &b)) //optimized
{
  int i{lastValue};
  int j{0};
  bool flag;
  do
  {
    flag = false;
    j = 0;
    while (j < i)
    {
      if (comp(data[j], data[j + 1]))
      {
        swapData(data[j], data[j + 1]);
        flag = true;
      }
      j++;
    }
    i--;
  } while (flag);
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::insertSort(bool (*comp)(const T &a, const T &b))
{
  int i{1};
  int j{0};
  T aux;
  while (i <= lastValue)
  {
    aux = data[i];
    j = i;
    while (j > 0 and comp(data[j - 1], aux))
    {
      data[j] = data[j - 1];
      j--;
    }
    if (i != j)
    {
      data[j] = aux;
    }
    i++;
  }
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::selectSort(bool (*comp)(const T &a, const T &b))
{
  int smaller{0};
  int j{0};
  for (int i{0}; i < lastValue; i++)
  {
    smaller = i;
    j = i + 1;
    while (j <= lastValue)
    {
      if (comp(data[smaller], data[j]))
      {
        smaller = j;
      }
      j++;
    }
    if (smaller != i)
    {
      swapData(data[smaller], data[i]);
    }
  }
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::shellSort(bool (*comp)(const T &a, const T &b))
{
  // 1 / 2
  // int decreasingSequence[] = {524288, 262144, 131072, 65536, 32768, 16384, 8192, 4096, 2048, 1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1, 0};
  // 1 / 3
  // int decreasingSequence[] = {531441, 177147, 59049, 19683, 6561, 2187, 729, 243, 81, 27, 9, 3, 1, 0};
  // Tokuda
  // int decreasingSequence[] = {776591, 345152, 153401, 68178, 30301, 13467, 5985, 2660, 1182, 525, 233, 103, 46, 20, 9, 4, 1, 0};
  // Ciura
  int decreasingSequence[] = {510774, 227011, 100894, 44842, 19930, 8858, 3937, 1750, 701, 301, 132, 57, 23, 10, 4, 1, 0};
  int sequencePosition{0};
  int diferential{decreasingSequence[sequencePosition]};
  int i{0};
  int j{0};
  while (diferential > 0)
  {
    i = diferential;
    while (i <= lastValue)
    {
      j = i;
      while (j >= diferential and comp(data[j - diferential], data[j]))
      {
        swapData(data[j - diferential], data[j]);
        j -= diferential;
      }
      i++;
    }
    sequencePosition++;
    diferential = decreasingSequence[sequencePosition];
  }
}

template <class T, int ARRAYSIZE>
// comp = lessThanOrEqualTo
void List<T, ARRAYSIZE>::mergeSort(const int &left, const int &right, bool (*comp)(const T &a, const T &b))
{
  if ( comp(right, left) ) return; //stop recursion

  // divide and conquer
  int half = (left + right) / 2;
  mergeSort(left, half);
  mergeSort(half + 1, right);

  // Copy to auxiliary
  static T auxiliaryArray[ARRAYSIZE];
  for( int n{left}; n <= right; n++ ) {
    auxiliaryArray[n] = data[n];
  }

  // Merge
  int i = left;
  int j{half + 1};
  int x{left};
  while( i <= half and j <= right ) {
    while( i <= half and comp(auxiliaryArray[i], auxiliaryArray[j]) ) {
      data[x] = auxiliaryArray[i];
      x++;
      i++;
    }
    if ( i <= half ) {
      while( j <= right and comp(auxiliaryArray[j], auxiliaryArray[i]) ) {
        data[x] = auxiliaryArray[j];
        x++;
        j++;
      }
    }
  }
  while( i <= half ) {
    data[x] = auxiliaryArray[i];
    x++;
    i++;
  }

  while( j <= right ) {
    data[x] = auxiliaryArray[j];
    x++;
    j++;
  }
}

// comp = lessThanOrEqualTo
template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::quickSort(const int &left, const int &right, bool (*comp)(const T &a, const T &b))
{
  if ( comp(right, left) ) return; //stop recursion

  int i{left};
  int j{right};

  while( i < j ) {
    while( i < j and comp(data[i], data[right]) ) {
      i++;
    }
    while( i < j and comp(data[right], data[j] ) ) {
      j--;
    }

    if ( i != j ) {
      swapData(data[i], data[j]);
    }
  }

  if ( i != right ) {
    swapData(data[i], data[right]);
  }

  quickSort(left, i - 1);
  quickSort(i + 1, right);
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::print()
{
  for (int i = 0; i <= lastValue; i++)
  {
    std::cout << "Posicion: " + to_string(i) << " = " << data[i] << endl;
  }
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::reset()
{
  lastValue = -1;
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::operator=(const List<T, ARRAYSIZE> &newList)
{
  copyAll(newList);
}

#endif // __LIST_H__