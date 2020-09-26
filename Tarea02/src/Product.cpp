#include "../include/Product.h"

using namespace std;

Product::Product()
{
}

Product::Product(const Product &product) : entryDate(product.entryDate), existence(product.existence), weight(product.weight), wholesalePrice(product.wholesalePrice), retailPrice(product.retailPrice), barCode(product.barCode), name(product.name) {}

Product::Product(Date _entryDate, int _existence, float _weight, float _wholesalePrice, float _retailPrice, string _barCode, string _name)
{
  entryDate = _entryDate;
  existence = _existence;
  weight = _weight;
  wholesalePrice = _wholesalePrice;
  retailPrice = _retailPrice;
  barCode = _barCode;
  name = _name;
}

std::string Product::getBarCode() const
{
  return barCode;
}

std::string Product::getName() const
{
  return name;
}

float Product::getWeight() const
{
  return weight;
}

Date Product::getEntryDate() const
{
  return entryDate;
}

float Product::getWholesalePrice() const
{
  return wholesalePrice;
}

float Product::getRetailPrice() const
{
  return retailPrice;
}

float Product::getExistence() const
{
  return existence;
}

std::string Product::toString() const
{
  string product;
  product = "Codigo: " + barCode;
  product += " | Nombre: " + name;
  product += " | Peso: " +  to_string((weight));
  product += " | Fecha: " +  entryDate.toString();
  product += " | Precio Mayoreo: " +  to_string(wholesalePrice);
  product += " | Precio Menudeo: " +  to_string(retailPrice);
  product += " | Existencia: " +  to_string(existence);
  return product;
}

void Product::setBarCode(const std::string &b)
{
  barCode = b;
}

void Product::setName(const std::string &n)
{
  name = n;
}

void Product::setWeight(const float &w)
{
  weight = w;
}

void Product::setEntryDate(const Date &e)
{
  entryDate = e;
}

void Product::setWholesalePrice(const float &w)
{
  wholesalePrice = w;
}

void Product::setRetailPrice(const float &r)
{
  retailPrice = r;
}

void Product::setExistence(const int &e, const string &operation)
{
  (operation == "add") ? existence += e : existence -= e;
  if (existence < 0) {
    existence = 0;
  }
}

bool Product::operator==(const string &b) const
{
  return barCode == b;
}

bool Product::operator!=(const string &b) const
{
  return barCode != b;
}

bool Product::operator<(const int &_existence) const
{
  return existence < _existence;
}

bool Product::operator<=(const int &_existence) const
{
  return existence <= _existence;
}

bool Product::operator>(const int &_existence) const
{
  return existence > _existence;
}

bool Product::operator>=(const int &_existence) const
{
  return existence >= _existence;
}

Product &Product::operator=(const Product &p)
{
  barCode = p.barCode;
  return *this;
}
