#ifndef __LIST_H__
#define __LIST_H__

// LDLCCED
// Lista doblemente circular con encabezado dummy

#include <iostream>
#include <cstring>
// #include "./node.h"
#include "./nodeTree.h"
#include "./binaryTree.h"

// -------- ------- ------ ----- Definition ----- ------ ------- --------

template <class T>
class List
{
protected:
  NodeTree<T> *header;

  bool isValidPosition(NodeTree<T> *);
  void copyAll(const List<T> &);
  static int compare(const T &a, const T &b);
  // template<T> friend class BinaryTree;
  // friend class Interface;

public:
  // typedef NodeTree<T> *Position;
  int estaprueba;

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

  void insert(const T &, NodeTree<T> *); //data, positon
  void remove(NodeTree<T> *);

  NodeTree<T> *getFirst() const;
  NodeTree<T> *&getLast() const;
  NodeTree<T> *getPreviousPos(NodeTree<T> *);
  NodeTree<T> *getNextPos(NodeTree<T> *);

  NodeTree<T> *linearSearch(const T &, int (*comp)(const T &, const T &) = List::compare);

  T recover(NodeTree<T> *);

  std::string toString() const;

  template<typename> friend class BinaryTree;

  // friend List<T> &toList(string, Position &);
  // friend class BinaryTree;
  // template<T>
  // friend class BinaryTree void toList(std::string);
  // template<T>
  // friend class BinaryTree void toList(std::string, NodeTree<T> *);

  void deleteAll();

  List<T> &operator=(const List<T> &);
};

// -------- ------- ------ ----- Implementation ----- ------ ------- --------
using namespace std;

template <class T>
bool List<T>::isValidPosition(NodeTree<T> *position)
{
  NodeTree<T> *aux{header->getRight()};

  while (aux != header) {
    if (aux == position) {
      return true;
    }

    aux = aux->getRight();
  };

  return false;
}

template <class T>
void List<T>::copyAll(const List<T> &newList)
{
  NodeTree<T> *aux{newList.header->getRight()};
  NodeTree<T> *newNode;

  while ( aux != newList.header ) {
    try {
      if ((newNode = new NodeTree<T>(aux->getData())) == nullptr) {
        throw Exception("Memoria no disponible, copyAll");
      }
    } catch( typename NodeTree<T>::Exception ex) {
      throw Exception(ex.what());
    }

    newNode->setLeft(header->getLeft());
    newNode->setRight(header);

    header->getLeft()->setRight(newNode);
    header->setLeft(newNode);

    aux = aux->getRight();
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
List<T>::List() : header(new NodeTree<T>)
{
  if (header == nullptr) {
    throw Exception("Memoria no disponible, inicializando lista");
  }

  header->setLeft(header);
  header->setRight(header);
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
  return header->getRight() == header;
}

template <class T>
void List<T>::insert(const T &value, NodeTree<T> *position)
{
  if (position != nullptr and !isValidPosition(position)) {
    throw Exception("Posicion invalida, insert");
  }

  NodeTree<T> *aux;
  try {
    aux = new NodeTree<T>(value);
  } catch (typename NodeTree<T>::Exception ex) {
    throw Exception(ex.what());
  }

  if (aux == nullptr) {
    throw Exception("Memoria no disponible, insert");
  }

  if (position == nullptr) {
    position = header;
  }

  aux->setLeft(position);
  aux->setRight(position->getRight());

  position->getRight()->setLeft(aux);
  position->setRight(aux);

}

template <class T>
void List<T>::remove(NodeTree<T> *position)
{
  if (!isValidPosition(position)) {
    throw Exception("Posicion invalida, remove");
  }

  position->getLeft()->setRight(position->getRight());

  position->getRight()->setLeft(position->getLeft());

  delete position;
}

template <class T>
NodeTree<T> *List<T>::getFirst() const
{
  if (isEmpty()) return nullptr;

  return header->getRight();
}

template <class T>
NodeTree<T> *&List<T>::getLast() const
{
  if (isEmpty()) return nullptr;

  return header->getLeft();
}

template <class T>
NodeTree<T> *List<T>::getPreviousPos(NodeTree<T> *position)
{
  if (!isValidPosition(position) or position == header->getRight()) return nullptr;

  return position->getLeft();
}

template <class T>
NodeTree<T> *List<T>::getNextPos(NodeTree<T> *position)
{
  if (!isValidPosition(position) or position == header->getLeft()) return nullptr;

  return position->getRight();
}

template <class T>
NodeTree<T> *List<T>::linearSearch(const T &value, int (*comp)(const T &, const T &))
{
  NodeTree<T> *aux{header->getRight()};

  while ( aux != header ){
    if ( comp(aux->getData(), value) == 0 ) {
      return aux;
    }
    aux = aux->getRight();
  }
  return nullptr;
}

template <class T>
T List<T>::recover(NodeTree<T> *position)
{
  if (!isValidPosition(position)) {
    throw Exception("Posicion invalida, recover");
  }

  return position->getData();
}

template <class T>
string List<T>::toString() const
{
  NodeTree<T> *aux{header->getRight()};

  string stringList{""};

  while (aux != header) {
    stringList += '\n' + to_string(aux->getData());
    aux = aux->getRight();
  };

  return stringList + '\n';
}

template <class T>
void List<T>::deleteAll()
{

  NodeTree<T> *aux;

  while (header->getRight() != header) {
    aux = header->getRight();
    header->setRight(aux->getRight());
    delete aux;
  };

  header->setLeft(header);
}

template <class T>
List<T> &List<T>::operator=(const List<T> &newList)
{
  deleteAll();
  copyAll(newList);
  return *this;
}

#endif // __LIST_H__