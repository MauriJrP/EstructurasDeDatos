#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include <iostream>
#include <random>
#include <chrono>
#include <functional>
#include <ctime>
#include "../include/list.h"

class Interface
{
private:

  void userInterface(List<int, 100000> &);
public:
  Interface(List<int, 100000> &);
};

#endif // __INTERFACE_H__