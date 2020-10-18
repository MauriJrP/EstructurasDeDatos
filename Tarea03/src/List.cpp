#include "../include/List.h"

using namespace std;


List::List (){
  lastValue = -1;
}


bool List::isValid(const int& position)
{
  return ( position > -1 && position < SIZE);
}

bool List::isEmpty()
{
  return lastValue == -1;
}

bool List::isFull()
{
  return lastValue == SIZE - 1;
}

void List::insert(const Song &value, const int &position)
{
  try
  {
    if ( position > lastValue + 1 || !isValid(position) || isFull() ) {
      throw "error";
    } else {
      for (int i = lastValue + 1; i > position; i--) {
        list[i] = list[i-1];
      }
      list[position] = value;
      lastValue++;
    }
  }
  catch(...)
  {
    cout << "Error..." << endl;
  }
}

void List::remove(const int &position)
{
  if ( isEmpty() || !isValid(position) ){
    cout << "error..." << endl;
  } else {
    for ( int i = position; i < lastValue; i++)
    {
      list[i] = list[i + 1];
    }
    lastValue--;
  }
}

int List::first()
{
  return lastValue > -1
    ? 0
    : -1;
}

int List::last()
{
  return lastValue > -1 ? lastValue : -1;
}

int List::previous(const int &position)
{
  if ( isEmpty() || !isValid(position) || position == 0 ) {
    return -1;
  } else {
    return position - 1;
  }
}

int List::next(const int &position)
{
  if ( isEmpty() || !isValid(position) || position == SIZE - 1 )
    return -1;
  else
    return position + 1;
}

int List::find(Song &value)
{
  string stringBuffer = value.getName();
  for (int i = 0; i <= lastValue; i++)
  {
    if (list[i].getName() == stringBuffer) return i;
  }
  return -1;
}

Song List::recover(const int &position)
{
  if ( !isEmpty() || isValid(position) ) {
    return list[position];
  }
  cout << "Error...";
  throw "error";
}

void List::sort()
{
}

void List::print()
{
  for (int i = 0; i <= lastValue; i++)
  {
    cout << "Posicion: " + to_string(i + 1) << list[i].toString() << endl;
  }
}

void List::reset()
{
  lastValue = -1;
}
