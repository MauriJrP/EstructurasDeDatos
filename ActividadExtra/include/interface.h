#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include <iostream>
#include <random>
#include <chrono>
#include <functional>
#include <ctime>
#include "./binaryTree.h"
#include "./list.h"

class Interface
{
private:

  void userInterface(BinaryTree<int> &);
public:
  Interface(BinaryTree<int> &);
};

#endif // __INTERFACE_H__