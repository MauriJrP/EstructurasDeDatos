#include "../include/Menu.h"

using namespace std;

Menu::Menu(){}

void Menu::chooseOption()
{
  system("clear");
  do {
    cout << "LISTA DE EXITOS" << endl << endl;
    playlist.print();
    cout << "\n1.- Insertar cancion" << endl;
    cout << "2.- Eliminar cancion" << endl;
    cout << "3.- Salir" << endl << endl;
    cout << "opcion: "; cin >> option;
    if ( option != 3 ) {
      callMethod(option);
      getchar();
      getchar();
      system("clear");
    }
  } while ( option != 3 );
}

void Menu::callMethod(const int& option)
{
  char data;
  int position;
  switch (option)
  {
  case 1:
    if (playlist.isFull()) {
      cout << "La lista esta llena..." << endl;
      break;
    }
    cin.ignore();
    cout << "Nombre: "; getline(cin, stringBuffer);
    songBuffer.setName(stringBuffer);
    cout << "Autor: "; getline(cin, stringBuffer);
    songBuffer.setAuthor(stringBuffer);
    cout << "Interprete: "; getline(cin, stringBuffer);
    songBuffer.setInterpreter(stringBuffer);
    cout << "Posicion: " << endl; cin >> intBuffer;
    songBuffer.setPosition(intBuffer);
    playlist.insert(songBuffer, songBuffer.getPosition());
    break;
  case 2:
    cout << "Posicion: "; cin >> position;
    playlist.remove(position);
    break;
  default:
    break;
  }
}
