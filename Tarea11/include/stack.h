#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
using namespace std;

#include <exception>
#include <string>
#include "dummyNode.h"

// -------- ------- ------ ----- Definition ----- ------ ------- --------

template <class T>
class Stack
{
private:
  T data;
  dummyNode<T> *anchor;

  void copyAll(const Stack<T> &);
  void deleteAll();

public:
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

  Stack();
  Stack(const Stack<T> &);

  ~Stack();

  bool isEmpty();

  void push( T &);
  T pop();
  T getTop();

  Stack<T> &operator=(const Stack<T> &);
};

// -------- ------- ------ ----- Implementation ----- ------ ------- --------

template <class T>
void Stack<T>::copyAll(const Stack<T> &newStack)
{
  dummyNode<T> *aux{newStack.anchor};
  dummyNode<T> *last{nullptr};
  dummyNode<T> *newNode;

  while ( aux != nullptr ){
    newNode = new dummyNode<T>(aux->getData());

    if (newNode == nullptr) {
      throw Exception("Memoria no disponible, copyAll");
    }

    if (last == nullptr) {
      anchor = newNode;
    } else {
      last->setNext(newNode);
    }
    last = newNode;
    aux = aux->getNext();
  }
}

template <class T>
void Stack<T>::deleteAll()
{
  dummyNode<T> *aux;

  while (anchor != nullptr) {
    aux = anchor;
    anchor = anchor->getNext();
    delete aux;
  }
}

template <class T>
Stack<T>::Stack() : anchor{nullptr} {}

template <class T>
Stack<T>::Stack(const Stack<T> &newStack) : anchor{nullptr} {
  copyAll(newStack);
}

template <class T>
Stack<T>::~Stack()
{
  deleteAll();
}

template <class T>
bool Stack<T>::isEmpty()
{
  return anchor == nullptr;
}

template <class T>
void Stack<T>::push(T &value)
{
  dummyNode<T> *aux;
  aux = new dummyNode<T>(value);

  if (aux == nullptr) {
    throw Exception("Memoria no disponible, push");
  }
  aux->setNext(anchor);
  anchor = aux;
}

template <class T>
T Stack<T>::pop()
{
  if (isEmpty()) {
    throw Exception("Insuficiencia de datos, pop");
  }

  T result{anchor->getData()};

  dummyNode<T> *aux{anchor};

  anchor = anchor->getNext();

  delete aux;

  return result;
}

template <class T>
T Stack<T>::getTop()
{
  if (isEmpty()) {
    throw Exception("Insuficiencia de datos, getTop");
  }

  return anchor->getData();
}

template <class T>
Stack<T> &Stack<T>::operator=(const Stack<T> &newStack)
{
  deleteAll();
  copyAll(newStack);

  return *this;
}

#endif // __STACK_H__