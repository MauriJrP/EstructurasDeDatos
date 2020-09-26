#include "../include/Menu.h"

using namespace std;

Menu::Menu(){}

void Menu::chooseOption()
{
  system("clear");
  do {
    cout << "Inventario de: "<< inventary.getStoreName() << endl << endl;
    cout << "1.- Cambiar nombre de la tienda" << endl;
    cout << "2.- Aniadir producto" << endl;
    cout << "3.- Retirar producto" << endl;
    cout << "4.- Mostrar inventario" << endl;
    cout << "5.- Salir" << endl << endl;
    cout << "opcion: "; cin >> option;
    if ( option != 5 ) {
      callMethod(option);
      getchar();
      if ( option != 1 ) getchar();
      system("clear");
    }
  } while ( option != 5 );
}

void Menu::callMethod(const int& option)
{
  switch (option)
  {
  case 1:
    cout << "Nombre: "; cin >> stringBuffer;
    inventary.setStoreName(stringBuffer);
    break;
  case 2:
    inventary.addProduct();
    break;
  case 3:
    inventary.removeProduct();
    break;
  case 4:
    inventary.showInventory();
    break;
  default:
    break;
  }
}
