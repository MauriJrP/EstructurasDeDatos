#include "../include/toPosfix.h"

using namespace std;

int ToPosfix::getImportance(const char &o)
{
  int importance{0};
  if ( o == '-' or o == '+' ) importance = 0;
  if ( o == '*' or o == '/' ) importance = 1;
  if ( o == '^' ) importance = 2;
  return importance;
}

bool ToPosfix::isOperator(const char &character)
{
  if ( character == '+'
    or character == '-'
    or character == '*'
    or character == '/'
    or character == '^' )
  {
    return true;
  }
  return false;
}

bool ToPosfix::isGrouper(const char &character)
{
  if ( character == '(' or character == ')' ) {
    return true;
  }
  return false;
}

ToPosfix::ToPosfix(){}

ToPosfix::ToPosfix(const ToPosfix &){}

string ToPosfix::infixToPosfix(const string &expression)
{
  string result{""};
  for ( int i{0}; i < expression.length(); i++ ) {
    if ( isOperator(expression[i]) ) {
      try {
        if ( myStack.getTop() != '(' ) {
          while ( getImportance(myStack.getTop()) >= getImportance(expression[i]) ) {
            result += myStack.pop();
          }
        }
      } catch (StackException e) {}
      myStack.push(expression[i]);
    } else if ( isGrouper(expression[i]) ) {
      if ( expression[i] == '(' ) {
        myStack.push(expression[i]);
      } else {
        try {
          while ( myStack.getTop() != '(' ) {
            result += myStack.pop();
          }
          myStack.pop();
        } catch (StackException e) {}
      }
    } else {
      result += expression[i];
    }
  }

  while( !myStack.isEmpty() ) {
    result += myStack.pop();
  }
  return result;
}
