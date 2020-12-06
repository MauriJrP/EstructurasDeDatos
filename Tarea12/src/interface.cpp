#include "../include/interface.h"

using namespace std;

Interface::Interface(BinaryTree<int> &myBinaryTree)
{
  userInterface(myBinaryTree);
}

void Interface::userInterface(BinaryTree<int> &myBinaryTree)
{
  default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
  uniform_int_distribution<int> distribution(0, 1000);
  auto dice = bind(distribution, generator);

  int value;
  int numbers;

  cout << "Numeros a generar:";
  cin >> numbers;
  cout << numbers << endl;

  for( int i(0); i < numbers; i++ ) {
    try {
      value = dice();
      myBinaryTree.insertData(value);
      // cerr << value << "\n";
    } catch (BinaryTree<int>::Exception err){
      cout << err.what() << endl << endl;
    }
  }
  // BinaryTree<int> myListAuxiliary(myBinaryTree);
  // myBinaryTree.parsePreOrder();


}