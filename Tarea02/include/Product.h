#ifndef __PRODUCT_H__
#define __PRODUCT_H__

#include <iostream>
#include <cstring>
#include <cmath>
#include "Date.h"

class Product
{
private:
  Date entryDate;
  int existence;
  float weight, wholesalePrice, retailPrice;
  std::string barCode, name;
public:
  Product();
  Product(const Product&);
  Product(Date, int, float, float, float, std::string, std::string);

  std::string getBarCode() const;
  std::string getName() const;
  float getWeight() const;
  Date getEntryDate() const;
  float getWholesalePrice() const;
  float getRetailPrice() const;
  float getExistence() const;

  std::string toString() const;

  void setBarCode( const std::string& );
  void setName( const std::string& );
  void setWeight( const float& );
  void setEntryDate( const Date& );
  void setWholesalePrice( const float& );
  void setRetailPrice( const  float&);
  void setExistence( const int&, const std::string& );

  bool operator == (const std::string&) const;
  bool operator != (const std::string&) const;
  bool operator < (const int&) const;
  bool operator <= (const int&) const;
  bool operator > (const int&) const;
  bool operator >= (const int&) const;

  Product &operator = (const Product&);
};

#endif // __PRODUCT_H__