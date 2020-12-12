#ifndef __NODETREE_H__
#define __NODETREE_H__

template <class T>
class NodeTree
{
private:
  T *dataPtr;
  NodeTree<T> *left;
  NodeTree<T> *right;

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

  NodeTree();
  NodeTree(const T &);

  ~NodeTree();

  T *&getDataPtr();
  T &getData();
  NodeTree<T> *&getLeft();
  NodeTree<T> *&getRight();

  void setDataPtr(T *);
  void setData(const T &);
  void setLeft(NodeTree *);
  void setRight(NodeTree *);
};

// -------- ------- ------ ----- Implementation ----- ------ ------- --------

template <class T>
NodeTree<T>::NodeTree() : dataPtr(nullptr), left(nullptr), right(nullptr) {}

template <class T>
NodeTree<T>::NodeTree(const T &e) : dataPtr(new T(e)), left(nullptr), right(nullptr)
{
  if (dataPtr == nullptr)
  {
    throw Exception("Memoria insuficiente, creando nodo");
  }
}

template <class T>
NodeTree<T>::~NodeTree()
{
  delete dataPtr;
  left = nullptr;
  right = nullptr;
}

template <class T>
T *& NodeTree<T>::getDataPtr()
{
  return dataPtr;
}

template <class T>
T & NodeTree<T>::getData()
{
  if (dataPtr == nullptr) {
    throw Exception("Dato inexistente, getData");
  }
  return *dataPtr;
}

template <class T>
NodeTree<T> *& NodeTree<T>::getLeft()
{
  return left;
}

template <class T>
NodeTree<T> *& NodeTree<T>::getRight()
{
  return right;
}

template <class T>
void NodeTree<T>::setDataPtr(T *p)
{
  dataPtr = p;
}

template <class T>
void NodeTree<T>::setData(const T &e)
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
void NodeTree<T>::setLeft(NodeTree *p)
{
  left = p;
}

template <class T>
void NodeTree<T>::setRight(NodeTree *p)
{
  right = p;
}

#endif // __NODETREE_H__