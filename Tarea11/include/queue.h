#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>
#include <exception>
#include <string>
#include "dummyNode.h"

using namespace std;

// -------- ------- ------ ----- Definition ----- ------ ------- --------

template <class T>
class Queue
{
private:
  dummyNode<T> *header;

  void copyAll(const Queue<T> &);

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

  Queue();
  Queue(const Queue<T> &);

  ~Queue();

  bool isEmpty();
  void enqueue(const T &);
  T dequeue();
  T getFront();

  Queue<T> &operator=(const Queue<T> &);
};

//* -------- ------- ------ ----- Implementation ----- ------ ------- --------

template <class T>
void Queue<T>::copyAll(const Queue<T> &newQueue)
{
  dummyNode<T> *aux(newQueue.header->getNext());
  dummyNode<T> newNode;

  while ( aux != newQueue.header ) {
    try {
      if ( (newNode = new dummyNode<T>(aux->getData())) == nullptr ) {
        throw Exception("Memoria no disponible, copyAll");
      }
    } catch (dummyNode<char>::Exception ex) { // -----------------------------------------------------------
    throw Exception(ex.what());
    }

    newNode->setPrev(header->getPrev());
    newNode->setNext(header);

    header->getPrev()->setNext(newNode);
    header->setPrev(newNode);

    aux = aux->getNext();
  }
}

template <class T>
void Queue<T>::deleteAll()
{
  dummyNode<T> *aux;

  while (header->getNext() != header) {
    aux = header->getNext();

    header->setNext(aux->getNext());

    delete aux;
  }

  header->setPrev(header);
}

template <class T>
Queue<T>::Queue() : header(new dummyNode<T>) {
  if (header == nullptr) {
    throw Exception("Memoria no disponible, constructor de queue");
  }

  header->setPrev(header);
  header->setNext(header);
}

template <class T>
Queue<T>::Queue(const Queue<T> &newQueue) : Queue() {
  copyAll(newQueue);
}

template <class T>
Queue<T>::~Queue()
{
  deleteAll();
  delete header;
}

template <class T>
bool Queue<T>::isEmpty()
{
  return header->getNext() == header;
}

template <class T>
void Queue<T>::enqueue(const T &value)
{
  dummyNode<T> *aux;

  try {
    if ((aux = new dummyNode<T>(value)) == nullptr) {
      throw Exception("Memoria no disponible, enqueue");
    }
  } catch (dummyNode<char>::Exception ex) { // -----------------------------------------------------------
    throw Exception(ex.what());
  }

  aux->setPrev(header->getPrev());
  aux->setNext(header);

  header->getPrev()->setNext(aux);
  header->setPrev(aux);
}

template <class T>
T Queue<T>::dequeue()
{
  if(isEmpty()) {
    throw Exception("Insuficiencia de datos, dequeue");
  }

  T result(header->getNext()->getData());

  dummyNode<T> *aux(header->getNext());

  aux->getPrev()->setNext(aux->getNext());
  aux->getNext()->setPrev(aux->getPrev());

  delete aux;
  return result;
}

template <class T>
T Queue<T>::getFront()
{
  if (isEmpty()) {
    throw Exception("Insuficiencia de datos, getFront");
  }

  return header->getNext()->getData();
}

template <class T>
Queue<T> & Queue<T>::operator=(const Queue<T> &newQueue)
{
  deleteAll();

  copyAll(newQueue);

  return *this;
}

#endif // __QUEUE_H__