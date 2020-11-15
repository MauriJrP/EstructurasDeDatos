#ifndef __NODE_H__
#define __NODE_H__

template <class T>
class Node
{
private:
  T data;
  Node<T> *next;

public:
  Node();
  Node(const T &);

  T getData() const;
  Node<T> * getNext() const;

  void setData(const T &);
  void setNext(Node *);
};

template <class T>
Node<T>::Node()
{
  next = nullptr;
}

template <class T>
Node<T>::Node(const T &e) : data(e), next(nullptr) {}

template <class T>
T Node<T>::getData() const
{
  return data;
}

template<class T>
Node<T> * Node<T>::getNext() const
{
  return next;
}

template <class T>
void Node<T>::setData(const T &e)
{
  data = e;
}

template <class T>
void Node<T>::setNext(Node *p)
{
  next = p;
}

#endif // __NODE_H__