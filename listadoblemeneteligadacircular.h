#ifndef __LIST_H__
#define __LIST_H__

// LDLCCED
// Lista doblemente circular con encabezado dummy

#include <iostream>
#include <cstring>
#include "./node.h"

// -------- ------- ------ ----- Definition ----- ------ ------- --------

template <class T>
class List
{
private:
  Node<T> *anchor;

  bool isValidPosition(Node<T> *);
  void copyAll(const List<T> &);
  static int compare(const T &a, const T &b);

public:
  typedef Node<T> *Position;

  class Exception : public std::exception
  {
  private:
    std::string msg;

  public:
    explicit Exception(const char *message) : msg(message) {}

    explicit Exception(const std::string &message) : msg(message) {}

    virtual ~Exception() throw() {}

    virtual const char *what() const throw()
    {
      return msg.c_str();
    }
  };

  List();
  List(const List<T> &);

  ~List();

  bool isEmpty() const;

  void insert(const T &, Node<T> *); //data, positon
  void remove(Node<T> *);

  Node<T> *getFirst() const;
  Node<T> *getLast() const;
  Node<T> *getPreviousPos(Node<T> *);
  Node<T> *getNextPos(Node<T> *);

  Node<T> *linearSearch(const T &, int (*comp)(const T &, const T &) = List::compare);

  T recover(Node<T> *);

  std::string toString() const;

  void deleteAll();

  List<T> &operator=(const List<T> &);
};

// -------- ------- ------ ----- Implementation ----- ------ ------- --------
using namespace std;

template <class T>
bool List<T>::isValidPosition(Node<T> *position)
{
  Node<T> *aux{anchor};

  do {
    if (aux == position) {
      return true;
    }

    aux = aux->getNext();
  }while (aux != anchor);

  return false;
}

template <class T>
void List<T>::copyAll(const List<T> &newList)
{
  Node<T> *aux{newList.anchor};
  Node<T> *last{nullptr};
  Node<T> *newNode;

  do {
    newNode = new Node<T>(aux->getData());

    if (newNode == nullptr) {
      throw Exception("Memoria no disponible, copyAll");
    }

    if (last == nullptr) {
      anchor = newNode;
    } else {
      newNode->setPrev(last);
      last->setNext(newNode);
    }
    last = newNode;
    aux = aux->getNext();
  }while ( aux != newList.anchor );

  anchor->setPrev(last);
  last->setNext(anchor);
}

template<class T>
int List<T>::compare(const T &a, const T &b)
{
  if (a > b) return 1;
  else if (a == b) return 0;
  else return -1;
}

template <class T>
List<T>::List() : anchor(nullptr)
{
}

template <class T>
List<T>::List(const List<T> &newList) : anchor(nullptr)
{
  copyAll(newList);
}

template <class T>
List<T>::~List()
{
  deleteAll();
}

template <class T>
bool List<T>::isEmpty() const
{
  return anchor == nullptr;
}

template <class T>
void List<T>::insert(const T &value, Node<T> *position)
{
  if (position != nullptr and !isValidPosition(position)) {
    throw Exception("Posicion invalida, insert");
  }

  cerr << position;
  Node<T> *aux;
  aux = new Node<T>(value);

  if (aux == nullptr) {
    throw Exception("Memoria no disponible, insert");
  }

  if (position == nullptr) {    //insert at the beginning
    if (anchor == nullptr) {
      aux->setPrev(aux);
      aux->setNext(aux);
    } else {
      aux->setPrev(anchor->getPrev());
      aux->setNext(anchor);

      anchor->getPrev()->setNext(aux);
      anchor->setPrev(aux);
    }
    anchor = aux;
  } else {                      //insert in any other position
    aux->setPrev(position);
    aux->setNext(position->getNext());

    position->getNext()->setPrev(aux);
    position->setNext(aux);
  }
}

template <class T>
void List<T>::remove(Node<T> *position)
{
  if (!isValidPosition(position)) {
    throw Exception("Posicion invalida, remove");
  }

  position->getPrev()->setNext(position->getNext());

  position->getNext()->setPrev(position->getPrev());

  if (position == anchor) {         //delete first
    if (position->getNext() ==  position) {
      anchor = nullptr;
    } else {
      anchor = anchor->getNext();
    }
  }

  delete position;
}

template <class T>
Node<T> *List<T>::getFirst() const
{
  return anchor;
}

template <class T>
Node<T> *List<T>::getLast() const
{
  if (isEmpty()) return nullptr;

  return anchor->getPrev();
}

template <class T>
Node<T> *List<T>::getPreviousPos(Node<T> *position)
{
  if (!isValidPosition(position) or position == anchor) return nullptr;

  return position->getPrev();
}

template <class T>
Node<T> *List<T>::getNextPos(Node<T> *position)
{
  if (!isValidPosition(position) or position == anchor->getPrev()) return nullptr;

  return position->getNext();
}

template <class T>
Node<T> *List<T>::linearSearch(const T &value, int (*comp)(const T &, const T &))
{
  Node<T> *aux{anchor};

  do {
    if ( comp(aux->getData(), value) == 0 ) {
      return aux;
    }
    aux = aux->getNext();
  }while ( aux != anchor );
  return nullptr;
}

template <class T>
T List<T>::recover(Node<T> *position)
{
  if (!isValidPosition(position)) {
    throw Exception("Posicion invalida, recover");
  }

  return position->getData();
}

template <class T>
string List<T>::toString() const
{
  if (isEmpty()) return "";

  Node<T> *aux{anchor};

  string stringList{""};

  do {
    stringList += '\n' + aux->getData().toString();
    aux = aux->getNext();
  }while (aux->getNext() != anchor);

  return stringList + '\n';
}

template <class T>
void List<T>::deleteAll()
{
  if (isEmpty()) return;

  Node<T> *aux;
  Node<T> *mark{anchor};

  do {
    aux = anchor;
    anchor = anchor->getNext();
    delete aux;
  }while (anchor != mark);

  anchor = nullptr;
}

template <class T>
List<T> &List<T>::operator=(const List<T> &newList)
{
  deleteAll();
  copyAll(newList);
  return *this;
}

#endif // __LIST_H__