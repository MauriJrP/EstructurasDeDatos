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
  T *data[ARRAYSIZE];
  T *auxPointer;
  int lastValue;

  bool isValid(const int &);
  void copyAll(const List<T, ARRAYSIZE> &);
  void swapData(T *&, T *&);
  static int compare(const T &, const T &);
  static bool lessThanOrEqualTo(const T &, const T &);

public:
  List();
  List(const List<T, ARRAYSIZE> &);

  ~List();

  bool isEmpty();
  bool isFull();
  void insert(const T &, const int &); //data, positon
  void remove(const int &);
  int first();
  int last();
  int previous(const int &);
  int next(const int &);

  int linearSearch(T &, int (*comp)(const T &a, const T &b) = List::compare);
  int binarySearch(T &, int (*comp)(const T &a, const T &b) = List::compare);

  T recover(const int &);

  void bubbleSort(int (*comp)(const T &a, const T &b) = List::compare);
  void insertSort(int (*comp)(const T &a, const T &b) = List::compare);
  void selectSort(int (*comp)(const T &a, const T &b) = List::compare);
  void shellSort(int (*comp)(const T &a, const T &b) = List::compare);
  void mergeSort(int (*comp)(const T &a, const T &b) = List::compare);
  void mergeSort(int (*comp)(const T &a, const T &b), const int &left, const int &right);
  void quickSort(int (*comp)(const T &a, const T &b) = List::compare);
  void quickSort(int (*comp)(const T &a, const T &b), const int &left, const int &right);

  void print();
  void deleteAll();

  List<T, ARRAYSIZE> &operator=(const List<T, ARRAYSIZE> &);
};

// -------- ------- ------ ----- Implementation ----- ------ ------- --------
using namespace std;

template <class T, int ARRAYSIZE>
List<T, ARRAYSIZE>::List()
{
  lastValue = -1;
  auxPointer = nullptr;

  for (int i{0}; i < ARRAYSIZE; i++)
  {
    data[i] = nullptr;
  }
}

template <class T, int ARRAYSIZE>
List<T, ARRAYSIZE>::List(const List<T, ARRAYSIZE> &newList)
{
  auxPointer = nullptr;
  copyAll(newList);
}

template<class T, int ARRAYSIZE>
List<T, ARRAYSIZE>::~List()
{
  deleteAll();
}

template <class T, int ARRAYSIZE>
bool List<T, ARRAYSIZE>::isValid(const int &position)
{
  return (position > -1 && position <= lastValue);
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::copyAll(const List<T, ARRAYSIZE> &newList)
{
  int i{0};
  int j{newList.lastValue};
  while (i <= j)
  {
    auxPointer = new T;
    *auxPointer = *newList.data[i];
    data[i] = auxPointer;
    i++;
  }

  while (j < ARRAYSIZE)
  {
    auxPointer = new T;
    auxPointer = nullptr;
    j++;
  }

  this->lastValue = newList.lastValue;
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::swapData(T *&a, T *&b)
{
  T *aux{a};
  a = b;
  b = aux;
}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::compare(const T &a, const T &b)
{
  if (a > b) return 1;
  else if (a == b) return 0;
  else return -1;
  // return a > b;
}

template <class T, int ARRAYSIZE>
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
  if (position != -1 and !isValid(position))
  {
    throw ListException("Posicion invalida, Insertar");
  }
  for (int i = lastValue; i > position; i--)
  {
    data[i + 1] = data[i];
  }
  auxPointer = new T;
  *auxPointer = value;
  data[position + 1] = auxPointer;
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
    delete data[position];
    for (int i{position}; i < lastValue; i++)
    {
      data[i] = data[i + 1];
    }
    data[lastValue] = nullptr;
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
int List<T, ARRAYSIZE>::linearSearch(T &value, int (*comp)(const T &a, const T &b))
{
  for (int i = 0; i <= lastValue; i++)
  {
    if (comp(*data[i], value) == 0)
      return i;
  }
  return -1;
}

//* compare
template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::binarySearch(T &value, int (*comp)(const T &a, const T &b)) {
  int i{0};
  int j{lastValue};
  int half{0};
  while (i < j)
  {
    half = (i + j) / 2;

    if (comp(*data[half], value) == 0)
      return half;
    if (comp(value, *data[half]) < 0) {
      j = half;
    } else {
      i = half;
    }
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

  return *data[position];
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::bubbleSort(int (*comp)(const T &a, const T &b)) //optimized
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
      if (comp(*data[j], *data[j + 1]) > 0)
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
void List<T, ARRAYSIZE>::insertSort(int (*comp)(const T &a, const T &b))
{
  int i{1};
  int j{0};
  T *aux;
  while (i <= lastValue)
  {
    aux = data[i];
    j = i;
    while (j > 0 and comp(*data[j - 1], *aux) > 0)
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
void List<T, ARRAYSIZE>::selectSort(int (*comp)(const T &a, const T &b))
{
  int smaller{0};
  int j{0};
  for (int i{0}; i < lastValue; i++)
  {
    smaller = i;
    j = i + 1;
    while (j <= lastValue)
    {
      if (comp(*data[smaller], *data[j]) > 0)
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
void List<T, ARRAYSIZE>::shellSort(int (*comp)(const T &a, const T &b))
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
      while (j >= diferential and comp(*data[j - diferential], *data[j]) > 0)
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
void List<T, ARRAYSIZE>::mergeSort(int (*comp)(const T &a, const T &b))
{
  mergeSort(comp, 0, lastValue);
}

template <class T, int ARRAYSIZE>
//* comp = lessThanOrEqualTo
void List<T, ARRAYSIZE>::mergeSort(int (*comp)(const T &a, const T &b), const int &left, const int &right)
{
  if (right <= left)
    return; //stop recursion

  // divide and conquer
  int half = (left + right) / 2;
  mergeSort(comp, left, half);
  mergeSort(comp, half + 1, right);

  // Copy to auxiliary
  static T *auxiliaryArray[ARRAYSIZE];
  for (int n{left}; n <= right; n++)
  {
    auxiliaryArray[n] = data[n];
  }

  // Merge
  int i = left;
  int j{half + 1};
  int x{left};
  while (i <= half and j <= right)
  {
    while (i <= half and comp(*auxiliaryArray[i], *auxiliaryArray[j]) < 1)
    {
      data[x] = auxiliaryArray[i];
      x++;
      i++;
    }
    if (i <= half)
    {
      while (j <= right and comp(*auxiliaryArray[j], *auxiliaryArray[i]) < 1)
      {
        data[x] = auxiliaryArray[j];
        x++;
        j++;
      }
    }
  }
  while (i <= half)
  {
    data[x] = auxiliaryArray[i];
    x++;
    i++;
  }

  while (j <= right)
  {
    data[x] = auxiliaryArray[j];
    x++;
    j++;
  }
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::quickSort(int (*comp)(const T &a, const T &b))
{
  quickSort(comp, 0, lastValue);
}

// comp = lessThanOrEqualTo
template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::quickSort(int (*comp)(const T &a, const T &b), const int &left, const int &right)
{
  if (right <= left)
    return; //stop recursion

  int i{left};
  int j{right};

  while (i < j)
  {
    while (i < j and comp(*data[i], *data[right]) < 1)
    {
      i++;
    }
    while (i < j and comp(*data[right], *data[j]) < 1)
    {
      j--;
    }

    if (i != j)
    {
      swapData(data[i], data[j]);
    }
  }

  if (i != right)
  {
    swapData(data[i], data[right]);
  }

  quickSort(comp, left, i - 1);
  quickSort(comp, i + 1, right);
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::print()
{
  for (int i = 0; i <= lastValue; i++)
  {
    std::cout << "Posicion: " + to_string(i) << data[i]->toString() << endl;
  }
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::deleteAll()
{
  while (lastValue >= 0)
  {
    delete data[lastValue--];
    data[lastValue + 1] = nullptr;
  }
}

template <class T, int ARRAYSIZE>
List<T, ARRAYSIZE> &List<T, ARRAYSIZE>::operator=(const List<T, ARRAYSIZE> &newList)
{
  deleteAll();
  copyAll(newList);
  return *this;
}

#endif // __LIST_H__