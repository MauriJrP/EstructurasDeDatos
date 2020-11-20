#ifndef __NODE_H__
#define __NODE_H__

template <class T>
class Node
{
private:
  T data;
  Node<T> *next;
  Node<T> *prev;

public:
  Node();
  Node(const T &);

  T getData() const;
  Node<T> * getNext() const;
  Node<T> * getPrev() const;

  void setData(const T &);
  void setNext(Node *);
  void setPrev(Node *);
};

template <class T>
Node<T>::Node()
{
  next = nullptr;
  prev = nullptr;
}

template <class T>
Node<T>::Node(const T &e) : data(e), next(nullptr), prev(nullptr) {}

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

template<class T>
Node<T> * Node<T>::getPrev() const
{
  return prev;
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

template <class T>
void Node<T>::setPrev(Node *p)
{
  prev = p;
}

#endif // __NODE_H__
