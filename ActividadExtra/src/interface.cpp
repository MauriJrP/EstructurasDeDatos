#include "../include/interface.h"

using namespace std;

Interface::Interface(BinaryTree<int> &myBinaryTree)
{
  userInterface(myBinaryTree);
}

void Interface::userInterface(BinaryTree<int> &myBinaryTree)
{
  default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
  uniform_int_distribution<int> distribution(0, 1000000);
  auto dice = bind(distribution, generator);

  int value;
  int numbers;

  cout << "Numeros a generar:";
  cin >> numbers;

  for( int i(0); i < numbers; i++ ) {
    try {
      value = dice();
      myBinaryTree.insertData(value);
      cout << "\nInsetado: " << value;
    } catch (BinaryTree<int>::Exception err){
      cout << err.what() << endl << endl;
    }
  }

  cout << "\n\nPreorder: \n";
  myBinaryTree.parsePreOrder();

  cout << "\n\nInOrder: \n";
  myBinaryTree.parseInOrder();

  cout << "\n\nPostOrder: \n";
  myBinaryTree.parsePostOrder();

  cout << "\n\nAltura: " << myBinaryTree.getHeight();

  cout << "\nAltura Sub Arbol Izquierdo: ";
  cout << myBinaryTree.getHeight(myBinaryTree.getLeftSubTree());

  cout << "\nAltura Sub Arbol Derecho: ";
  cout << myBinaryTree.getHeight(myBinaryTree.getRightSubTree());

  cout << endl;
  List<int> myList(myBinaryTree.toList("pre"));
  cout << "\nLista: \n\n" << myList.toString();

}