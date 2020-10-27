#include "../include/interface.h"

Interface::Interface(List<int, 100000> &myList)
{
  userInterface(myList);
}

void Interface::userInterface(List<int, 100000> &myList)
{
  default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
  uniform_int_distribution<int> distribution(0, 1000000);
  auto dice = bind(distribution, generator);

  int value;

  for( int i(0); i < 100000; i++ ) {
    try {
      value = dice();
      myList.insert(value, i - 1);
    } catch (ListException e){
      cout << e.what() << endl << endl;
    }
  }
  List<int, 100000> myListAuxiliary(myList);

  unsigned t0, t1;
  double time;

  cout << "\nOrdenando Por Bubble Sort\n";
  t0 = clock();
  myList.bubbleSort();
  t1 = clock();
  time = (double(t1-t0)/CLOCKS_PER_SEC);
  cout << "Tiempo: " << time << " segundos\n";

  myList = myListAuxiliary;

  cout << "\nOrdenando Por Insert Sort\n";
  t0 = clock();
  myList.insertSort();
  t1 = clock();
  time = (double(t1-t0)/CLOCKS_PER_SEC);
  cout << "Tiempo: " << time << " segundos\n";

  myList = myListAuxiliary;

  cout << "\nOrdenando Por Select Sort\n";
  t0 = clock();
  myList.selectSort();
  t1 = clock();
  time = (double(t1-t0)/CLOCKS_PER_SEC);
  cout << "Tiempo: " << time << " segundos\n";

  myList = myListAuxiliary;
  cout << "\nOrdenando Por Shell Sort\n";
  t0 = clock();
  myList.shellSort();
  t1 = clock();
  time = (double(t1-t0)/CLOCKS_PER_SEC);
  cout << "Tiempo: " << time << " segundos\n";

  myList = myListAuxiliary;

  cout << "\nOrdenando Por Merge Sort\n";
  t0 = clock();
  myList.mergeSort();
  t1 = clock();
  time = (double(t1-t0)/CLOCKS_PER_SEC);
  cout << "Tiempo: " << time << " segundos\n";

  myList = myListAuxiliary;

  cout << "\nOrdenando Por Quick Sort\n";
  t0 = clock();
  myList.quickSort();
  t1 = clock();
  time = (double(t1-t0)/CLOCKS_PER_SEC);
  cout << "Tiempo: " << time << " segundos\n";
}