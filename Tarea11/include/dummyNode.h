#ifndef __NODE_H__
#define __NODE_H__

template <class T>
class dummyNode
{
private:
  T *dataPtr;
  dummyNode<T> *prev;
  dummyNode<T> *next;

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

  dummyNode();
  dummyNode(const T &);

  ~dummyNode();

  T *getDataPtr() const;
  T getData() const;
  dummyNode<T> *getPrev() const;
  dummyNode<T> *getNext() const;

  void setDataPtr(T *);
  void setData(const T &);
  void setPrev(dummyNode *);
  void setNext(dummyNode *);
};

// -------- ------- ------ ----- Implementation ----- ------ ------- --------

template <class T>
dummyNode<T>::dummyNode() : dataPtr(nullptr), prev(nullptr), next(nullptr) {}

template <class T>
dummyNode<T>::dummyNode(const T &e) : dataPtr(new T(e)), prev(nullptr), next(nullptr)
{
  if (dataPtr == nullptr)
  {
    throw Exception("Memoria insuficiente, creando nodo");
  }
}

template <class T>
dummyNode<T>::~dummyNode()
{
  delete dataPtr;
}

template <class T>
T * dummyNode<T>::getDataPtr() const
{
  return dataPtr;
}

template <class T>
T dummyNode<T>::getData() const
{
  if (dataPtr == nullptr) {
    throw Exception("Dato inexistente, getData");
  }
  return *dataPtr;
}

template <class T>
dummyNode<T> *dummyNode<T>::getPrev() const
{
  return prev;
}

template <class T>
dummyNode<T> *dummyNode<T>::getNext() const
{
  return next;
}

template <class T>
void dummyNode<T>::setDataPtr(T *p)
{
  dataPtr = p;
}

template <class T>
void dummyNode<T>::setData(const T &e)
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
void dummyNode<T>::setPrev(dummyNode *p)
{
  prev = p;
}

template <class T>
void dummyNode<T>::setNext(dummyNode *p)
{
  next = p;
}

#endif // __NODE_H__