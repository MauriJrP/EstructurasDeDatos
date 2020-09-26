#include "../include/Inventory.h"

using namespace std;

Inventory::Inventory()
{
}

Inventory::Inventory(const Inventory &i) : inventory(i.inventory)
{
}

Product Inventory::getInventory() const
{
  return inventory[500];
}

std::string Inventory::getStoreName() const
{
  return storeName;
}

bool Inventory::registredProduct(const std::string &c)
{
  for ( int i = 0; i <= productCount; i++ ) {
    if ( inventory[i] == c ) {
      intBuffer2 = i; // product to edit stock
      return true;
    }
  }
  return false;
}

void Inventory::addProduct()
{
  cout << "Codigo de barras(13 digitos): ";
  cin >> stringBuffer;
  bool existingProduct = registredProduct(stringBuffer);
  if ( existingProduct == false ) {
    inventory[productCount].setBarCode(stringBuffer);
    cout << "Nombre: ";   cin >> stringBuffer;
    inventory[productCount].setName(stringBuffer);
    cout << "Peso en gramos: "; cin >> floatBuffer;
    inventory[productCount].setWeight(floatBuffer);
    cout << "Precio de mayoreo: "; cin >> floatBuffer;
    inventory[productCount].setWholesalePrice(floatBuffer);
    cout << "Precio al menudeo: "; cin >> floatBuffer;
    inventory[productCount].setRetailPrice(floatBuffer);
    cout << "Cantidad a ingresar: "; cin >> intBuffer;
    inventory[productCount].setExistence(intBuffer, "add");
    productCount++;
  } else {
    cout << "Cantidad a ingresar: "; cin >> intBuffer;
    inventory[intBuffer2].setExistence(intBuffer, "add");
  }
}

void Inventory::removeProduct()
{
  cout << "Codigo de barras(13 digitos): ";  cin >> stringBuffer;
  bool existingProduct = registredProduct(stringBuffer);
  if ( existingProduct ) {
    cout << "Cantidad a eliminar: "; cin >> intBuffer;
    for ( int i = 0; i <= productCount; i++ ) {
      if ( inventory[i] == stringBuffer ) {
        inventory[intBuffer2].setExistence(intBuffer, "remove");
        (inventory[i] <= 0)
        ? cout << "La cantidad del producto ahora es 0" << endl
        : cout << "Se han eliminado correctamente" << endl;
      }
    }
  } else {
    cout << "No existe ese producto...";
  }
}

void Inventory::showInventory()
{
  for ( int i = 0; i < productCount; i++ ) {
    cout << inventory[i].toString() << endl;
  }
}


void Inventory::setStoreName(const std::string &s)
{
  storeName = s;
}

bool Inventory::operator==(const Inventory &s) const
{
  return storeName == s.storeName;
}

bool Inventory::operator!=(const Inventory &s) const
{
  return storeName != s.storeName;
}

bool Inventory::operator<(const Inventory &s) const
{
  return storeName < s.storeName;
}

bool Inventory::operator<=(const Inventory &s) const
{
  return storeName <= s.storeName;
}

bool Inventory::operator>(const Inventory &s) const
{
  return storeName > s.storeName;
}

bool Inventory::operator>=(const Inventory &s) const
{
  return storeName >= s.storeName;
}

Inventory &Inventory::operator=(const Inventory &inv)
{
  for ( int i = 0; i < arrayLength; i++ ) {
    inventory[i] = inv.inventory[i];
  }
  return *this;
}
