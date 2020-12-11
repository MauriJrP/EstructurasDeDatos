#ifndef __NODE_H__
#define __NODE_H__

template <class T>
class Node
{
private:
  T *dataPtr;
  Node<T> *prev;
  Node<T> *next;

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

  Node();
  Node(const T &);

  ~Node();

  T *getDataPtr() const;
  T getData() const;
  Node<T> *getPrev() const;
  Node<T> *getNext() const;

  void setDataPtr(T *);
  void setData(const T &);
  void setPrev(Node *);
  void setNext(Node *);
};

// -------- ------- ------ ----- Implementation ----- ------ ------- --------

template <class T>
Node<T>::Node() : dataPtr(nullptr), prev(nullptr), next(nullptr) {}

template <class T>
Node<T>::Node(const T &e) : dataPtr(new T(e)), prev(nullptr), next(nullptr)
{
  if (dataPtr == nullptr)
  {
    throw Exception("Memoria insuficiente, creando nodo");
  }
}

template <class T>
Node<T>::~Node()
{
  delete dataPtr;
}

template <class T>
T * Node<T>::getDataPtr() const
{
  return dataPtr;
}

template <class T>
T Node<T>::getData() const
{
  if (dataPtr == nullptr) {
    throw Exception("Dato inexistente, getData");
  }
  return *dataPtr;
}

template <class T>
Node<T> *Node<T>::getPrev() const
{
  return prev;
}

template <class T>
Node<T> *Node<T>::getNext() const
{
  return next;
}

template <class T>
void Node<T>::setDataPtr(T *p)
{
  dataPtr = p;
}

template <class T>
void Node<T>::setData(const T &e)
{
  if (dataPtr == nullptr) {
    if ( (dataPtr = new T(e)) == nullptr ) {
      throw Exception("Memoria no disponible, setData");
    }
  } else {
    *dataPtr = e;
  }
}

template <class T>
void Node<T>::setPrev(Node *p)
{
  prev = p;
}

template <class T>
void Node<T>::setNext(Node *p)
{
  next = p;
}

#endif // __NODE_H__