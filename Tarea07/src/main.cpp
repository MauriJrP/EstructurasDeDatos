#include "../include/list.h"
#include "../include/interface.h"

int main(int argc, const char** argv) {
  List<int, 100000> myList;
  Interface myInterface = Interface(myList);

  return 0;
}