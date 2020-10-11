#ifndef __TOPOSFIX_H__
#define __TOPOSFIX_H__

#include <iostream>
#include "stack.h"
#include <string>
#include "queue.h"

class ToPosfix
{
private:
  Stack<char> myStack;

  int getImportance(const char &);
  bool isOperator(const char &);
  bool isGrouper(const char &);
public:
  ToPosfix();
  ToPosfix(const ToPosfix &);

  std::string infixToPosfix(Queue<char> &);
};

#endif // __POSFIX_H__