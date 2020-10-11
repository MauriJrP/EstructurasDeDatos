#include <iostream>

#include <random>
#include <chrono>
#include <functional>

#include "../include/queue.h"

using namespace std;

int main(int argc, const char** argv) {
  // Menu myMenu = Menu();
  default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
  uniform_int_distribution<int> distribution(111, 999);
  auto dice = bind(distribution, generator);

  Queue<int> myQueue;
  int value;

  for( int i(0); i < 17; i++ ) {
    try {
      value = dice();
      cout << "Encolando: " << value << endl;
      myQueue.enqueue(value);
    } catch (QueueException e){
      cout << e.what() << endl << endl;
    }
  }

  Queue<int> myQueue2;
  myQueue2 = myQueue;

  cout << endl;

  cout << "Frente: " << myQueue.getFront() << endl << endl;

  cout << "Contenido de cola: " << endl;

  while (!myQueue.isEmpty()) {
    cout << myQueue.dequeue() << endl;
  }

  cout << "Contenido de cola2: " << endl;

  while (!myQueue2.isEmpty()) {
    cout << myQueue2.dequeue() << endl;
  }
  cout << endl << endl;

  return 0;
}


// -------- ------- ------ ----- stack ----- ------ ------- --------
// #include <iostream>
// #include "../include/menu.h"

// #include <random>
// #include <chrono>
// #include <functional>

// #include "../include/stack.h"

// using namespace std;

// int main(int argc, const char** argv) {
//   // Menu myMenu = Menu();
//   default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
//   uniform_int_distribution<int> distribution(111, 999);
//   auto dice = bind(distribution, generator);

//   Stack<int> myStack;
//   int value;

//   for( int i(0); i < 10; i++ ) {
//     try {
//       value = dice();
//       cout << "Apilando: " << value << endl;
//       myStack.push(value);
//     } catch (StackException e){
//       cout << e.what() << endl << endl;
//     }
//   }

//   Stack<int> myStack2(myStack);
//   cout << endl;
//   cout << "Tope: " << myStack.getTop() << endl << endl;
//   cout << "Volcado de pila: " << endl;

//   while (!myStack.isEmpty()) {
//     cout << myStack.pop() << endl;
//   }
//   while (!myStack2.isEmpty()) {
//     cout << myStack2.pop() << endl;
//   }


//   cout << endl << endl;

//   return 0;
// }