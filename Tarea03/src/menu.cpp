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
    cout << "5.- Salir" << endl << endl;
    cout << "opcion: "; cin >> option;
    if ( option != 5 ) {
      callMethod(option, myList);
      getchar();
      system("clear");
    }
  } while ( option != 5 );
}

std::string Menu::getInputNameSong()
{
  string stringBuffer{""};
  cin.ignore();
  cout << "Nombre: "; getline(cin, stringBuffer);
  return stringBuffer;
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
  default:
    break;
  }
}
