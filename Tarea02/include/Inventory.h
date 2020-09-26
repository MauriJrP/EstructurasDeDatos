#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include <iostream>
#include <cstring>
#include "Product.h"

class Inventory
{
private:
  Product inventory[500];
  std::string storeName = "Tienda 1";

  //these attributes will only be used by the same class
  int arrayLength = sizeof(inventory) / sizeof(inventory[0]);
  int productCount = 0;
  std::string stringBuffer; int intBuffer, intBuffer2; float floatBuffer;
public:
  Inventory();
  Inventory(const Inventory &);

  Product getInventory() const;
  std::string getStoreName() const;

  void addProduct();

  void removeProduct();

  void showInventory();

  bool registredProduct(const std::string&);

  // I didn't know if a setter to an array should change the whole array or just one position of it
  // void setInventory(const Product &);
  void setStoreName(const std::string&);

  bool operator == (const Inventory&) const;
  bool operator != (const Inventory&) const;
  bool operator < (const Inventory&) const;
  bool operator <= (const Inventory&) const;
  bool operator > (const Inventory&) const;
  bool operator >= (const Inventory&) const;

  Inventory &operator = (const Inventory&);
};

#endif // __INVENTORY_H__