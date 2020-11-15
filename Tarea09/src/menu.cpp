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
    cout << myList.toString();
    cout << "\n1.- Insertar cancion" << endl;
    cout << "2.- Eliminar cancion" << endl;
    cout << "3.- Buscar Por Cancion" << endl;
    cout << "4.- Buscar Por Cantante" << endl;
    cout << "5.- Salir" << endl << endl;
    cout << "opcion: "; cin >> option;
    if ( option != 5 ) {
      callMethod(option, myList);
      getchar();
      system("clear");
    }
  } while ( option != 5 );

  cout << "Lista 1:\n";
  cout << myList.toString();
  cout << "Borrando Lista 1...\n";
  myList.deleteAll();
  cout << "Lista 1:\n";
  cout << myList.toString();
  cout << "Lista 2:\n";
  cout << myList2.toString();
}

void Menu::callMethod(const int &option, List<Song> &myList)
{
  char data{' '};
  Song mySong = Song();
  List<Song>::Position position;
  switch (option)
  {
  case 1:
    songBuffer.setName(getInputNameSong());
    cout << "Autor: "; getline(cin, stringBuffer);
    songBuffer.setAuthor(stringBuffer);
    cout << "Interprete: "; getline(cin, stringBuffer);
    songBuffer.setInterpreter(stringBuffer);
    cout << "\n1.- Al principio\n";
    cout << "2.- Al final\n";
    cout << "3.- Antes de...\n";
    cout << "4.- Despues de...\n";
    cout << "Posicion: "; cin >> intBuffer;

    try {
      switch (intBuffer)
      {
      case 1:
        myList.insert(songBuffer, myList.getFirst());
        break;
      case 2:
        myList.insert(songBuffer, myList.getLast());
        break;
      case 3:
        mySong.setName(getInputNameSong());
        position = myList.linearSearch(mySong, Song::compareByName);
        myList.insert(songBuffer, myList.getPreviousPos(position));
        break;
      case 4:
        mySong.setName(getInputNameSong());
        position = myList.linearSearch(mySong, Song::compareByName);
        myList.insert(songBuffer, myList.getNextPos(position));
        break;
      default:
        break;
      }
    } catch(List<Song>::Exception error) {
      cout << error.what();
      getchar();
    }
    break;
  case 2:
    cout << "Haciendo copia de la lista 1...\n";
    myList2 = myList;
    songBuffer.setName(getInputNameSong());
    position = myList.linearSearch(songBuffer, Song::compareByName);
    try {
      myList.remove(position);
    } catch(List<Song>::Exception error) {
      cout << error.what();
      getchar();
    }
    break;
  case 3:
    songBuffer.setName(getInputNameSong());  //also change nameFile
    search(myList, 1, songBuffer);
    break;
  case 4:
    songBuffer.setInterpreter(getInputInterpreter());
    search(myList, 2, songBuffer);
    break;
  default:
    break;
  }
}

std::string Menu::getInputNameSong()
{
  string stringBuffer{""};
  cin.ignore();
  cout << "Nombre de cancion: "; getline(cin, stringBuffer);
  return stringBuffer;
}

std::string Menu::getInputInterpreter()
{
  string stringBuffer{""};
  cin.ignore();
  cout << "Interprete: "; getline(cin, stringBuffer);
  return stringBuffer;
}

void Menu::search(List<Song> &myList, const int &method, Song &value)
{
  List<Song>::Position position;
  method == 1
    ? position = myList.linearSearch(value, Song::compareByName)
    : position = myList.linearSearch(value, Song::compareByInterpreter);
  (position == nullptr)
    ? cout << "Cancion no encontrada"
    : cout << "Posicion: " << position << '\n' << myList.recover(position).toString();
}