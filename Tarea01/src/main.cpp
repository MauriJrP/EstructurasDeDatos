#include <iostream>
#include <cstdlib>
#include <iomanip>

#include "../include/PrimitiveDataTypes.h"
#include "../include/StructuredDataTypes.h"

using namespace std;

int main()
{
  system("clear");
  char option;
  bool cycleMenu = true;
  // srand(time(NULL));
  do
  {
    cout << "a.- Tamano y rangos de los Tipos de Datos Primitivos" << endl;
    cout << "b.- Ejemplo de tipo de dato abstracto" << endl;
    cout << "c.- Salir" << endl;
    cout << "Elige un opcion:" << endl;
    cin >> option;
    system("clear");
    switch (option)
    {
    case 'a': //Primitive data types
      PrimitiveDataTypes ValuesTable;
      ValuesTable.PrintValuesTable();
      cout << endl;
      break;
    case 'b': // Structured data types
      StructuredDataTypes Matrix;
      Matrix.matrixConstructor();
      Matrix.matrixAdd();
      Matrix.matrixMultiply();
      Matrix.MatrixesPrint();
      break;
    case 'c':
      cycleMenu = false;
      cout << "Programa terminado" << endl;
      break;
    default:
      break;
    }
  } while (cycleMenu);
}