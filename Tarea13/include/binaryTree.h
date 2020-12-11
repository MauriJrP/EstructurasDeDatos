#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

#include <iostream>
#include "./node.h"

// -------- ------- ------ ----- Definition ----- ------ ------- --------

template <class T>
class BinaryTree
{
public:
  typedef Node<T> *Position;

private:
  Position root;

  void copyAll(const BinaryTree<T> &, Position &r = nullptr);

  void insertData(Position &, const T &); // Position = sub tree

  Position &findData(Position &, const T &);

  Position &getLowest(Position &);
  Position &getHighest(Position &);

  void parsePreOrder(Position &);
  void parseInOrder(Position &);
  void parsePostOrder(Position &);

  int getBalanceFactor(Node<T> *&);

  void simpleLeftRotation(Node<T> *&);
  void simpleRightRotation(Node<T> *&);
  void doubleLeftRotation(Node<T> *&);
  void doubleRightRotation(Node<T> *&);

  void doBalancing(Node<T> *&);

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

  BinaryTree();
  BinaryTree(const BinaryTree &);

  ~BinaryTree();

  bool isEmpty() const;

  void insertData(const T &);

  void deleteData(Position &);

  T retrieve(Position &) const;

  int getHeight(Position &); //sub tree level

  Position &findData(const T &);

  Position &getLowest();
  Position &getHighest();
  Position &getLeftSubTree();
  Position &getRightSubTree();

  bool isLeaf(Position &) const; // Es hoja?

  int getHeight(); //tree

  void parsePreOrder();
  void parseInOrder();
  void parsePostOrder();

  void deleteAll(Position &);

  BinaryTree &operator=(const BinaryTree &);
};

// -------- ------- ------ ----- Implementation ----- ------ ------- --------

using namespace std;

template <class T>
BinaryTree<T>::BinaryTree() : root(nullptr)
{
}

template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree &newBinaryTree) : root(nullptr)
{
  copyAll(newBinaryTree);
}

template <class T>
BinaryTree<T>::~BinaryTree()
{
  deleteAll(root);
}

// -------- ------- ------ ----- Auxiliary Methods ----- ------ ------- --------

template <class T>
void BinaryTree<T>::copyAll(const BinaryTree<T> &newBinaryTree, Position &r)
{
  if (r == nullptr)
  {
    return;
  }

  insertData(r->getData());
  copyAll(r->getLeft());
  copyAll(r->getRight());
}

// -------- ------- ------ ----- Interface methods ----- ------ ------- --------

template <class T>
void BinaryTree<T>::insertData(const T &data)
{
  insertData(root, data);
}

template <class T>
typename BinaryTree<T>::Position &BinaryTree<T>::findData(const T &data)
{
  return findData(root, data);
}

template <class T>
typename BinaryTree<T>::Position &BinaryTree<T>::getLowest()
{
  return getLowest(root);
}

template <class T>
typename BinaryTree<T>::Position &BinaryTree<T>::getHighest()
{
  return getHighest(root);
}

template <class T>
int BinaryTree<T>::getHeight()
{
  return getHeight(root);
}

template <class T>
void BinaryTree<T>::parsePreOrder()
{
  parsePreOrder(root);
}

template <class T>
void BinaryTree<T>::parseInOrder()
{
  parseInOrder(root);
}

template <class T>
void BinaryTree<T>::parsePostOrder()
{
  parsePostOrder(root);
}

// -------- ------- ------ ----- Methods ----- ------ ------- --------

template <class T>
void BinaryTree<T>::insertData(Position &r, const T &data) //r = root
{
  if (r == nullptr)
  { //is leaf
    try
    {
      if ((r = new Node<T>(data)) == nullptr)
      {
        throw Exception("Memoria no disponible, insertData");
      }
    }
    catch (typename Node<T>::Exception ex)
    {
      throw Exception(ex.what());
    }
  }
  else
  {
    if (data < r->getData())
    {
      insertData(r->getLeft(), data);
    }
    else
    {
      insertData(r->getRight(), data);
    }
    doBalancing(r);
  }
}

template <class T>
typename BinaryTree<T>::Position &BinaryTree<T>::findData(Position &r, const T &data)
{
  if (r == nullptr or r->getData() == data)
  {
    return r;
  }

  if (data < r->getData())
  {
    return findData(r->getLeft(), data);
  }

  return findData(r->getRight(), data);
}

template <class T>
typename BinaryTree<T>::Position &BinaryTree<T>::getLowest(Position &r)
{
  if (r == nullptr or r->getLeft() == nullptr)
  {
    return r;
  }

  return getLowest(r->getLeft());
}

template <class T>
typename BinaryTree<T>::Position &BinaryTree<T>::getHighest(Position &r)
{
  if (r == nullptr or r->getRight() == nullptr)
  {
    return r;
  }

  return getHighest(r->getRight());
}

template<class T>
typename BinaryTree<T>::Position& BinaryTree<T>::getLeftSubTree()
{
  return root->getLeft();
}

template<class T>
typename BinaryTree<T>::Position& BinaryTree<T>::getRightSubTree()
{
  return root->getRight();
}

template <class T>
void BinaryTree<T>::parsePreOrder(Position &r)
{
  if (r == nullptr)
  {
    return;
  }

  std::cout << r->getData() << ", ";
  parsePreOrder(r->getLeft());
  parsePreOrder(r->getRight());
}

template <class T>
void BinaryTree<T>::parseInOrder(Position &r)
{
  if (r == nullptr)
  {
    // cerr << "acabo\n";
    return;
  }
  // cerr << "no\n";

  parseInOrder(r->getLeft());
  std::cout << r->getData() << ", ";
  parseInOrder(r->getRight());
}

template <class T>
void BinaryTree<T>::parsePostOrder(Position &r)
{
  if (r == nullptr)
  {
    return;
  }

  parsePostOrder(r->getLeft());
  parsePostOrder(r->getRight());
  std::cout << r->getData() << ", ";
}

template <class T>
int BinaryTree<T>::getBalanceFactor(Node<T> *& r)
{
  return getHeight(r->getRight()) - getHeight(r->getLeft());
}

template <class T>
void BinaryTree<T>::simpleLeftRotation(Node<T> *&r)
{
  Node<T> *aux1(r->getRight());
  Node<T> *aux2(aux1->getLeft());

  r->setRight(aux2);
  aux1->setLeft(r);
  r = aux1;
}

template <class T>
void BinaryTree<T>::simpleRightRotation(Node<T> *&r)
{
  Node<T> *aux1(r->getLeft());
  Node<T> *aux2(aux1->getRight());

  r->setLeft(aux2);
  aux1->setRight(r);
  r = aux1;
}

template <class T>
void BinaryTree<T>::doubleLeftRotation(Node<T> *&r)
{
  Node<T> *aux1(r->getRight());
  Node<T> *aux2(r->getRight()->getLeft());
  Node<T> *aux3(aux2->getLeft());
  Node<T> *aux4(aux2->getRight());

  r->setRight(aux3);
  aux1->setLeft(aux4);
  aux2->setLeft(r);
  aux2->setRight(aux1);
  r = aux2;

  // simpleRightRotation(r->getRight());
  // simpleLeftRotation(r);
}

template <class T>
void BinaryTree<T>::doubleRightRotation(Node<T> *&r)
{
  Node<T> *aux1(r->getLeft());
  Node<T> *aux2(aux1->getRight());
  Node<T> *aux3(aux2->getRight());
  Node<T> *aux4(aux2->getLeft());

  r->setLeft(aux3);
  aux1->setRight(aux4);
  aux2->setRight(r);
  aux2->setLeft(aux1);
  r = aux2;

  // simpleLeftRotation(r->getLeft());
  // simpleRightRotation(r);
}

template <class T>
void BinaryTree<T>::doBalancing(Node<T> *&r)
{
  int balanceFactor;
  balanceFactor = getBalanceFactor(r);
  if (balanceFactor == -2) {
    if (getBalanceFactor(r->getLeft()) == -1) {
      simpleRightRotation(r);
    } else {
      doubleRightRotation(r);
    }
  } else if(balanceFactor == 2) {
    if (getBalanceFactor(r->getRight()) == 1) {
      simpleLeftRotation(r);
    } else {
      doubleLeftRotation(r);
    }
  }
}

template <class T>
bool BinaryTree<T>::isEmpty() const
{
  return root == nullptr;
}

template <class T>
void BinaryTree<T>::deleteData(Position &pos)
{
  if (root == nullptr or pos == nullptr)
  {
    throw Exception("Posicion invalida, deleteData");
  }

  if (isLeaf(pos))
  {
    delete pos;
    pos = nullptr;
  }
  else
  {
    Position replacementPos;
    if (pos->getLeft() != nullptr)
    {
      replacementPos = getHighest(pos->getLeft());
    }
    else
    {
      replacementPos = getLowest(pos->getRight());
    }

    pos->setData(replacementPos->getData());
    delete replacementPos;
    replacementPos = nullptr;
  }
}

template <class T>
T BinaryTree<T>::retrieve(Position &r) const
{
  return r->getData();
}

template <class T>
bool BinaryTree<T>::isLeaf(Position &r) const
{
  return r != nullptr and r->getLeft() == r->getRight();
}

template <class T>
int BinaryTree<T>::getHeight(Position &r)
{
  if (r == nullptr)
  {
    return 0;
  }

  int leftHeight(getHeight(r->getLeft()));
  int rightHeight(getHeight(r->getRight()));

  return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

template <class T>
void BinaryTree<T>::deleteAll(Position &r)
{
  if (r == nullptr)
  {
    return;
  }

  deleteAll(r->getLeft());
  deleteAll(r->getRight());
  delete r;
}

template <class T>
BinaryTree<T> &BinaryTree<T>::operator=(const BinaryTree &newBinaryTree)
{
  deleteAll();

  copyAll(newBinaryTree);

  return *this;
}

#endif // __BINARYTREE_H__