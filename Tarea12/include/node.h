#ifndef __NODE_H__
#define __NODE_H__

template <class T>
class Node
{
private:
  T *dataPtr;
  Node<T> *left;
  Node<T> *right;

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

  T *&getDataPtr();
  T &getData();
  Node<T> *&getLeft();
  Node<T> *&getRight();

  void setDataPtr(T *);
  void setData(const T &);
  void setLeft(Node *);
  void setRight(Node *);
};

// -------- ------- ------ ----- Implementation ----- ------ ------- --------

template <class T>
Node<T>::Node() : dataPtr(nullptr), left(nullptr), right(nullptr) {}

template <class T>
Node<T>::Node(const T &e) : dataPtr(new T(e)), left(nullptr), right(nullptr)
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
  left = nullptr;
  right = nullptr;
}

template <class T>
T *& Node<T>::getDataPtr()
{
  return dataPtr;
}

template <class T>
T & Node<T>::getData()
{
  if (dataPtr == nullptr) {
    throw Exception("Dato inexistente, getData");
  }
  return *dataPtr;
}

template <class T>
Node<T> *& Node<T>::getLeft()
{
  return left;
}

template <class T>
Node<T> *& Node<T>::getRight()
{
  return right;
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
void Node<T>::setLeft(Node *p)
{
  left = p;
}

template <class T>
void Node<T>::setRight(Node *p)
{
  right = p;
}

#endif // __NODE_H__