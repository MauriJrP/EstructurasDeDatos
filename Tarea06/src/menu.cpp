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
    cout << "3.- Busqueda Lineal" << endl;
    cout << "4.- Busqueda Binaria" << endl;
    cout << "5.- Ordenar Por Nombre" << endl;
    cout << "6.- Ordenar Por Autor" << endl;
    cout << "7.- Salir" << endl << endl;
    cout << "opcion: "; cin >> option;
    if ( option != 7 ) {
      callMethod(option, myList);
      getchar();
      system("clear");
    }
  } while ( option != 7 );
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
    cout << "Posicion: "; cin >> position;
    myList.remove(position);
    break;
  case 3:
    songBuffer.setName(getInputNameSong());  //also change nameFile
    intBuffer = myList.linearSearch(songBuffer);
    (intBuffer == -1)
      ? cout << "Cancion no encontrada"
      : cout << "Posicion: " << intBuffer << '\n' << myList.recover(intBuffer).toString();
    break;
  case 4:
    songBuffer.setName(getInputNameSong());  //also change nameFile
    intBuffer = myList.binarySearch(songBuffer);
    (intBuffer == -1)
      ? cout << "Cancion no encontrada"
      : cout << "Posicion: " << intBuffer << '\n' << myList.recover(intBuffer).toString();
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

void Menu::chooseSortMethod(List<Song> &myList, const int &value) {
  cout << "\n1.- Bubble Sort \n";
  cout << "2.- Insert Sort \n";
  cout << "3.- Select Sort \n";
  cout << "4.- Shell Sort \n\n";
  cout << "Metodo: ";
  int option{0};
  cin >> option;
  switch (option)
  {
  case 1:
    value == 1 ? myList.bubbleSort(Song::compareByName) : myList.bubbleSort(Song::compareByAuthor);
    break;
  case 2:
    value == 1 ? myList.insertSort(Song::compareByName) : myList.insertSort(Song::compareByAuthor);
    break;
  case 3:
    value == 1 ? myList.selectSort(Song::compareByName) : myList.selectSort(Song::compareByAuthor);
    break;
  case 4:
    value == 1 ? myList.shellSort(Song::compareByName) : myList.shellSort(Song::compareByAuthor);
    break;
  default:
    cout << "Opcion invalida\n";
    break;
  }
}