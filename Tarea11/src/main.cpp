#include <iostream>
#include <string>

#include "../include/queue.h"
#include "../include/toPosfix.h"

using namespace std;

int main(int argc, const char** argv) {
  string stringBuffer{""};

  cout << "Expresion Infija: ";
  getline(cin, stringBuffer);

  Queue<char> infixExpression;
  for ( int i{0}; i < stringBuffer.length(); i++ ) {
    infixExpression.enqueue(stringBuffer[i]);
  }

  ToPosfix converter;
  stringBuffer = converter.infixToPosfix(infixExpression);

  Queue<char> posfixExpression;
  for ( int i{0}; i < stringBuffer.length(); i++ ) {
    posfixExpression.enqueue(stringBuffer[i]);
  }

  cout << "Expresion Posfija: ";
  for ( int i{0}; i < stringBuffer.length(); i++ ) {
    cout << posfixExpression.dequeue();
  }

  cout << endl;
  return 0;
}