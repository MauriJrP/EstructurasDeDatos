#pragma once

class PrimitiveDataTypes
{
public:
  void PrintValuesTable(){}

private:
  struct primitive
  {
    char _char;
    unsigned char _unsignedChar;
    short int _short;
    unsigned short int _unsignedShort;
    long _long;
    unsigned long int _unsignedLong;
    float _float;
    double _double;
  } values;
};