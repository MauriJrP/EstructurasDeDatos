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

string ToPosfix::infixToPosfix(Queue<char> &expression)
{
  char character;
  string result{""};
  while ( !expression.isEmpty() ) {
    character = expression.dequeue();
    if ( isOperator(character) ) {
      try {
        if ( myStack.getTop() != '(' ) {
          while ( getImportance(myStack.getTop()) >= getImportance(character) ) {
            result += myStack.pop();
          }
        }
      } catch (StackException e) {}
      myStack.push(character);
    } else if ( isGrouper(character) ) {
      if ( character == '(' ) {
        myStack.push(character);
      } else {
        try {
          while ( myStack.getTop() != '(' ) {
            result += myStack.pop();
          }
          myStack.pop();
        } catch (StackException e) {}
      }
    } else {
      result += character;
    }
  }

  while( !myStack.isEmpty() ) {
    result += myStack.pop();
  }
  return result;
}


