#include "../include/menu.h"

using namespace std;

Menu::Menu(List<Song> &myList)
{
  userInterface(myList);
}

void Menu::userInterface(List<Song> &myList)
{
  system("clear");
  do {
    cout << "LISTA DE EXITOS" << endl << endl;
    myList.print();
    cout << "\n1.- Insertar cancion" << endl;
    cout << "2.- Eliminar cancion" << endl;
    cout << "3.- Buscar Por Cancion" << endl;
    cout << "4.- Buscar Por Cantante" << endl;
    cout << "5.- Ordenar Por Nombre" << endl;
    cout << "6.- Ordenar Por Interprete" << endl;
    cout << "7.- Salir" << endl << endl;
    cout << "opcion: "; cin >> option;
    if ( option != 7 ) {
      callMethod(option, myList);
      getchar();
      system("clear");
    }
  } while ( option != 7 );

  cout << "Lista 1:\n";
  myList.print();
  cout << "Borrando Lista 1...\n";
  myList.deleteAll();
  cout << "Lista 1:\n";
  myList.print();
  cout << "Lista 2:\n";
  myList2.print();
}



void Menu::callMethod(const int &option, List<Song> &myList)
{
  char data{' '};
  int position{0};
  Song mySong = Song();
  switch (option)
  {
  case 1:
    if (myList.isFull()) {
      cout << "La lista esta llena..." << endl;
      break;
    }
    songBuffer.setName(getInputNameSong());
    cout << "Autor: "; getline(cin, stringBuffer);
    songBuffer.setAuthor(stringBuffer);
    cout << "Interprete: "; getline(cin, stringBuffer);
    songBuffer.setInterpreter(stringBuffer);
    cout << "Posicion: "; cin >> intBuffer;
    songBuffer.setPosition(intBuffer);
    try {
      myList.insert(songBuffer, songBuffer.getPosition());
    } catch(ListException error) {}
    break;
  case 2:
    cout << "Haciendo copia de la lista 1...\n";
    myList2 = myList;
    cout << "Posicion a eliminar: "; cin >> position;
    myList.remove(position);
    break;
  case 3:
    songBuffer.setName(getInputNameSong());  //also change nameFile
    chooseSearchMethod(myList, 1, songBuffer);
    getchar();
    // getchar();
    break;
  case 4:
    songBuffer.setInterpreter(getInputInterpreter());
    chooseSearchMethod(myList, 2, songBuffer);
    getchar();
    break;
  case 5:
    chooseSortMethod(myList, 1);  // compareByName
    break;
  case 6:
    chooseSortMethod(myList, 2);  // compareByAuthor
    break;
  default:
    break;
  }
}

std::string Menu::getInputNameSong()
{
  string stringBuffer{""};
  cin.ignore();
  cout << "Nombre: "; getline(cin, stringBuffer);
  return stringBuffer;
}

std::string Menu::getInputInterpreter()
{
  string stringBuffer{""};
  cin.ignore();
  cout << "Interprete: "; getline(cin, stringBuffer);
  return stringBuffer;
}

void Menu::chooseSearchMethod(List<Song> &myList, const int &method, Song &value)
{
  cout << "\n1.- Busqueda Lineal \n";
  cout << "2.- Busqueda Binaria \n";
  cout << "Metodo: ";
  int option{0};
  cin >> option;
  switch (option)
  {
  case 1:
    method == 1
      ? intBuffer = myList.linearSearch(value, Song::compareByName)
      : intBuffer = myList.linearSearch(value, Song::compareByInterpreter);
    (intBuffer == -1)
      ? cout << "Cancion no encontrada"
      : cout << "Posicion: " << intBuffer << '\n' << myList.recover(intBuffer).toString();
    break;
  case 2:
    method == 1
      ? intBuffer = myList.binarySearch(value, Song::compareByName)
      : intBuffer = myList.binarySearch(value, Song::compareByInterpreter);
    (intBuffer == -1)
      ? cout << "Cancion no encontrada"
      : cout << "Posicion: " << intBuffer << '\n' << myList.recover(intBuffer).toString();
  default:
    break;
  }
}

void Menu::chooseSortMethod(List<Song> &myList, const int &value) {
  cout << "\n1.- Bubble Sort \n";
  cout << "2.- Insert Sort \n";
  cout << "3.- Select Sort \n";
  cout << "4.- Shell Sort \n";
  cout << "5.- Merge Sort \n";
  cout << "6.- Quick Sort \n\n";
  cout << "Metodo: ";
  int option{0};
  cin >> option;
  switch (option)
  {
  case 1:
    value == 1 ? myList.bubbleSort(Song::compareByName) : myList.bubbleSort(Song::compareByInterpreter);
    break;
  case 2:
    value == 1 ? myList.insertSort(Song::compareByName) : myList.insertSort(Song::compareByInterpreter);
    break;
  case 3:
    value == 1 ? myList.selectSort(Song::compareByName) : myList.selectSort(Song::compareByInterpreter);
    break;
  case 4:
    value == 1 ? myList.shellSort(Song::compareByName) : myList.shellSort(Song::compareByInterpreter);
    break;
  case 5:
    value == 1 ? myList.mergeSort(Song::compareByName) : myList.mergeSort(Song::compareByInterpreter);
    break;
  case 6:
    value == 1 ? myList.quickSort(Song::compareByName) : myList.quickSort(Song::compareByInterpreter);
    break;
  default:
    cout << "Opcion invalida\n";
    break;
  }
}