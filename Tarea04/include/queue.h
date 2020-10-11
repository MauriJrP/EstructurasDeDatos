#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>
#include <exception>
#include <string>

using namespace std;

class QueueException : public std::exception {
private:
  std::string msg;

public:
  explicit QueueException(const char* message) : msg(message) { }

  explicit QueueException(const std::string& message) : msg(message) {}

  virtual ~QueueException() throw () {}

  virtual const char* what() const throw () {
    return msg.c_str();
  }
};

// -------- ------- ------ ----- Definition ----- ------ ------- --------

template <class T, int ARRAYSIZE = 50>
class Queue
{
private:
  T data[ARRAYSIZE];
  int front;
  int end;

  bool fullFlag = false;
  void toggleFull();
  void copyAll(const Queue<T, ARRAYSIZE> &);

public:
  Queue();
  Queue(const Queue &);

  bool isEmpty();
  bool isFull();
  void enqueue(const T &);
  T dequeue();
  T getFront();

  Queue<T, ARRAYSIZE> &operator = (const Queue<T, ARRAYSIZE> &);
};

// -------- ------- ------ ----- Implementation ----- ------ ------- --------

template<class T, int ARRAYSIZE>
void Queue<T, ARRAYSIZE>::copyAll(const Queue<T, ARRAYSIZE> &newQueue)
{
  this->front = newQueue.front;
  this->end = newQueue.end;
  this->fullFlag = newQueue.fullFlag;
  int i = newQueue.front;
  if ( isEmpty() ) return;
  while ( (i != newQueue.end + 1) and fullFlag ) {
    this->data[i] = newQueue.data[i];
    i++;
    if ( ( end == ARRAYSIZE and front != 0 ) or end == ARRAYSIZE + 1 ) i = 0;
  }
}

template <class T, int ARRAYSIZE>
void Queue<T, ARRAYSIZE>::toggleFull()
{
  fullFlag = !fullFlag;

}

template <class T, int ARRAYSIZE>
Queue<T, ARRAYSIZE>::Queue()
{
  front = 0;
  end = ARRAYSIZE;
}

template <class T, int ARRAYSIZE>
Queue<T, ARRAYSIZE>::Queue(const Queue &newQueue)
{
  copyAll(newQueue);
}

template <class T, int ARRAYSIZE>
bool Queue<T, ARRAYSIZE>::isEmpty()
{
  if ( isFull() ) return false;
  return ( front == (end + 1) or ( front == 0 and end == ARRAYSIZE - 1 ) or ( front == 0 and end == ARRAYSIZE ) );
}

template <class T, int ARRAYSIZE>
bool Queue<T, ARRAYSIZE>::isFull()
{
  return fullFlag;
}

template <class T, int ARRAYSIZE>
void Queue<T, ARRAYSIZE>::enqueue(const T &element)
{
  //-------- ------- ------ ----- Error Desbordamiento de datos ----- ------ ------- --------
  if ( isFull() ) {
    throw QueueException("Desbordamiento de datos, enqueue");
  }

  end++;
  // when the queue is created, end == ARRAYSIZE + 1
  if ( ( end == ARRAYSIZE and front != 0 ) or end == ARRAYSIZE + 1 ) end = 0;
  data[end] = element;
  if ( front == end + 1 or ( front == 0 and end == ARRAYSIZE - 1 ) ) {
    toggleFull();
  }
}

template <class T, int ARRAYSIZE>
T Queue<T, ARRAYSIZE>::dequeue()
{
  //-------- ------- ------ ----- Error Insuficiencia de datos ----- ------ ------- --------
  if ( isEmpty() ) {
    throw QueueException("Insuficiencia de datos, dequeue");
  }

  front++;
  if ( front == ARRAYSIZE) {
    front = 0;
    return data[ARRAYSIZE - 1];
  }

  if (fullFlag) toggleFull();

  return data[front - 1];
}

template <class T, int ARRAYSIZE>
T Queue<T, ARRAYSIZE>::getFront()
{
  //-------- ------- ------ ----- Excepcion Insuficiencia de datos ----- ------ ------- --------
  if ( isEmpty() ) {
    throw QueueException("Insuficiencia de datos, getFront");
  }

  return data[front];
}

template<class T, int ARRAYSIZE>
Queue<T, ARRAYSIZE>& Queue<T, ARRAYSIZE>::operator = (const Queue<T, ARRAYSIZE> &newQueue)
{
  copyAll(newQueue);
  return *this;
}

#endif // __QUEUE_H__