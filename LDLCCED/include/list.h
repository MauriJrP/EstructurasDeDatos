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
  // Node<T> *header;
  Node<T> *header;

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
  Node<T> *aux{header->getNext()};

  while (aux != header) {
    if (aux == position) {
      return true;
    }

    aux = aux->getNext();
  };

  return false;
}

template <class T>
void List<T>::copyAll(const List<T> &newList)
{
  Node<T> *aux{newList.header->getNext()};
  Node<T> *newNode;

  while ( aux != newList.header ) {
    try {
      if ((newNode = new Node<T>(aux->getData())) == nullptr) {
        throw Exception("Memoria no disponible, copyAll");
      }
    } catch( typename Node<T>::Exception ex) {
      throw Exception(ex.what());
    }

    newNode->setPrev(header->getPrev());
    newNode->setNext(header);

    header->getPrev()->setNext(newNode);
    header->setPrev(newNode);

    aux = aux->getNext();
  }

}

template<class T>
int List<T>::compare(const T &a, const T &b)
{
  if (a > b) return 1;
  else if (a == b) return 0;
  else return -1;
}

template <class T>
List<T>::List() : header(new Node<T>)
{
  if (header == nullptr) {
    throw Exception("Memoria no disponible, inicializando lista");
  }

  header->setPrev(header);
  header->setNext(header);
}

template <class T>
List<T>::List(const List<T> &newList) : List()
{
  copyAll(newList);
}

template <class T>
List<T>::~List()
{
  deleteAll();

  delete header;
}

template <class T>
bool List<T>::isEmpty() const
{
  return header->getNext() == header;
}

template <class T>
void List<T>::insert(const T &value, Node<T> *position)
{
  if (position != nullptr and !isValidPosition(position)) {
    throw Exception("Posicion invalida, insert");
  }

  Node<T> *aux;
  try {
    aux = new Node<T>(value);
  } catch (typename Node<T>::Exception ex) {
    throw Exception(ex.what());
  }

  if (aux == nullptr) {
    throw Exception("Memoria no disponible, insert");
  }

  if (position == nullptr) {
    position = header;
  }

  aux->setPrev(position);
  aux->setNext(position->getNext());

  position->getNext()->setPrev(aux);
  position->setNext(aux);

}

template <class T>
void List<T>::remove(Node<T> *position)
{
  if (!isValidPosition(position)) {
    throw Exception("Posicion invalida, remove");
  }

  position->getPrev()->setNext(position->getNext());

  position->getNext()->setPrev(position->getPrev());

  delete position;
}

template <class T>
Node<T> *List<T>::getFirst() const
{
  if (isEmpty()) return nullptr;

  return header->getNext();
}

template <class T>
Node<T> *List<T>::getLast() const
{
  if (isEmpty()) return nullptr;

  return header->getPrev();
}

template <class T>
Node<T> *List<T>::getPreviousPos(Node<T> *position)
{
  if (!isValidPosition(position) or position == header->getNext()) return nullptr;

  return position->getPrev();
}

template <class T>
Node<T> *List<T>::getNextPos(Node<T> *position)
{
  if (!isValidPosition(position) or position == header->getPrev()) return nullptr;

  return position->getNext();
}

template <class T>
Node<T> *List<T>::linearSearch(const T &value, int (*comp)(const T &, const T &))
{
  Node<T> *aux{header->getNext()};

  while ( aux != header ){
    if ( comp(aux->getData(), value) == 0 ) {
      return aux;
    }
    aux = aux->getNext();
  }
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
  Node<T> *aux{header->getNext()};

  string stringList{""};

  while (aux != header) {
    stringList += '\n' + aux->getData().toString();
    aux = aux->getNext();
  };

  return stringList + '\n';
}

template <class T>
void List<T>::deleteAll()
{

  Node<T> *aux;

  while (header->getNext() != header) {
    aux = header->getNext();
    header->setNext(aux->getNext());
    delete aux;
  };

  header->setPrev(header);
}

template <class T>
List<T> &List<T>::operator=(const List<T> &newList)
{
  deleteAll();
  copyAll(newList);
  return *this;
}

#endif // __LIST_H__