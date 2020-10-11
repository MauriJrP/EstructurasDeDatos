#ifndef __STACK_H__
#define __STACK_H__

#include <exception>
#include <string>

class StackException : public std::exception {
private:
  std::string msg;

public:
  explicit StackException(const char* message) : msg(message) { }

  explicit StackException(const std::string& message) : msg(message) {}

  virtual ~StackException() throw () {}

  virtual const char* what() const throw () {
    return msg.c_str();
  }
};

// -------- ------- ------ ----- Definition ----- ------ ------- --------

template <class T, int ARRAYSIZE = 50>
class Stack
{
private:
  T data[ARRAYSIZE];
  int top;

  void copyAll(const Stack<T, ARRAYSIZE> &);
public:
  Stack();
  Stack(const Stack<T, ARRAYSIZE> &);

  bool isEmpty();
  bool isFull();
  void push(const T&);
  T pop();
  T getTop();

  Stack<T, ARRAYSIZE> &operator = (const Stack<T, ARRAYSIZE> &);
};


// -------- ------- ------ ----- Implementation ----- ------ ------- --------

template<class T, int ARRAYSIZE>
void Stack<T, ARRAYSIZE>::copyAll(const Stack<T, ARRAYSIZE> &newStack)
{
  for (int i(0); i <= newStack.top; i++)
  {
    this->data[i] = newStack.data[i];
  }

  this->top = newStack.top;
}

template <class T, int ARRAYSIZE>
Stack<T, ARRAYSIZE>::Stack()
{
  top = -1;
}

template <class T, int ARRAYSIZE>
Stack<T, ARRAYSIZE>::Stack(const Stack<T, ARRAYSIZE> &newStack)
{
  copyAll(newStack);
}

template <class T, int ARRAYSIZE>
bool Stack<T, ARRAYSIZE>::isEmpty()
{
  return top == -1;
}

template <class T, int ARRAYSIZE>
bool Stack<T, ARRAYSIZE>::isFull()
{
  return top == ARRAYSIZE - 1;
}

template <class T, int ARRAYSIZE>
void Stack<T, ARRAYSIZE>::push(const T&element)
{
  // -------- ------- ------ ----- Error Desbordamiento de datos ----- ------ ------- --------
  if ( isFull() ) {
    throw StackException("Desbordamiento de datos, push");
  }

  top++;
  data[top] = element;
}

template <class T, int ARRAYSIZE>
T Stack<T, ARRAYSIZE>::pop()
{
  //-------- ------- ------ ----- Error Insuficiencia de datos ----- ------ ------- --------
  if ( isEmpty() ) {
    throw StackException("Insuficiencia de datos, pop");
  }

  top--;
  return data[top + 1];
}

template <class T, int ARRAYSIZE>
T Stack<T, ARRAYSIZE>::getTop()
{
  //-------- ------- ------ ----- Excepcion Insuficiencia de datos ----- ------ ------- --------
  if ( isEmpty() ) {
    throw StackException("Insuficiencia de datos, getTop");
  }

  return data[top];
}

template<class T, int ARRAYSIZE>
Stack<T, ARRAYSIZE>& Stack<T, ARRAYSIZE>::operator = (const Stack<T, ARRAYSIZE> &newStack)
{
  copyAll(newStack);
  return *this;
}

#endif // __STACK_H__