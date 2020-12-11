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

  for( int i(0); i < numbers; i++ ) {
    try {
      value = dice();
      myBinaryTree.insertData(value);
    } catch (BinaryTree<int>::Exception err){
      cout << err.what() << endl << endl;
    }
  }
  // BinaryTree<int> myListAuxiliary(myBinaryTree);

  // cout << "\nPreorder: \n";
  // myBinaryTree.parsePreOrder();

  cout << "\n\nInOrder: \n";
  myBinaryTree.parseInOrder();

  // cout << "\n\nPostOrder: \n";
  // myBinaryTree.parsePostOrder();

  // cout << "\n\nAltura: " << myBinaryTree.getHeight();

  // cout << "\nMenor: ";
  // cout << myBinaryTree.retrieve(myBinaryTree.getLowest());

  // cout << "\nMayor: ";
  // cout << myBinaryTree.retrieve(myBinaryTree.getHighest());

  myBinaryTree.deleteData(myBinaryTree.getLowest());

  cout << "\n\nInOrder: \n";
  myBinaryTree.parseInOrder();

  // int data{0};
  // cout << "\nDato a buscar: "; cin >> data;
  // BinaryTree<int>::Position direction = myBinaryTree.findData(data);

  // if (direction == nullptr) {
  //   cout << "Dato no encontrado...";
  // } else {
  //   cout << "Posicion: " << direction;
  // }

}