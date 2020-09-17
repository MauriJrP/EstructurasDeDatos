#include <iostream>
#include <climits>
#include <cfloat>
#include <cstdlib>
#include <iomanip>
#include <limits>

#include "clases.h"

using namespace std;

void PrimitiveDataTypes::PrintValuesTable()
  {
    cout << "Tipo de dato\t\t\tTamano en bits\tValor minimo\tValor maximo\n\n";
    cout << "Caracter con signo" << "\t\t" << sizeof(values._char) * 8 << "\t\t" << CHAR_MIN << "\t\t" << CHAR_MAX << endl;
    cout << "Caracter sin signo" << "\t\t" << sizeof(values._unsignedChar) * 8 << "\t\t" << numeric_limits<unsigned char>::min() << "\t\t" << UCHAR_MAX << endl;
    cout << "Entero corto con signo" << "\t\t" << sizeof(values._short) * 8 << "\t\t" << SHRT_MIN << "\t\t" << SHRT_MAX << endl;
    cout << "Entero corto sin signo" << "\t\t" << sizeof(values._unsignedShort) * 8 << "\t\t"<< numeric_limits<unsigned short int>::min() << "\t\t" << USHRT_MAX << endl;
    cout << "Entero largo con signo" << "\t\t" << sizeof(values._long) * 8 << "\t\t" << LONG_MIN << "\t" << LONG_MAX << endl;
    cout << "Entero largo sin signo" << "\t\t" << sizeof(values._unsignedLong) * 8 << "\t\t" <<  numeric_limits<unsigned long int>::min() << "\t\t" << ULONG_MAX << endl;
    cout << "Real de precision simple" << "\t" << sizeof(values._float) * 8 << "\t\t" << FLT_MIN << "\t" << FLT_MAX << endl;
    cout << "Real de doble precision" << "\t\t" << sizeof(values._double) * 8 << "\t\t" << DBL_MIN << "\t" << DBL_MAX << endl;
  }

// private:
//   struct primitive
//   {
//     char _char;
//     unsigned char _unsignedChar;
//     short int _short;
//     unsigned short int _unsignedShort;
//     long _long;
//     unsigned long int _unsignedLong;
//     float _float;
//     double _double;
//   } values;
// };