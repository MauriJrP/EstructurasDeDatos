#include <iostream>
#include <typeinfo>
#include <climits>
#include <cfloat>
#include <cstdlib>
#include <iomanip>
#include <limits>

#include "clases.h"

using namespace std;

class StructuredDataTypes
{
public:
  void matrixConstructor() {
    cout << "Ingresa el tamano de las matrices: " << endl;
    cin >> matrixSize;
    while ((matrixSize < 3) || (matrixSize > 10)) {
      cout << "Debe ser un numero entre 3 y 10: " << endl;
      cin >> matrixSize;
    }
    for ( int i = 0; i < matrixSize; i++ ) {
      for ( int j = 0; j < matrixSize; j++ ) {
        matrixA[i][j] = float(rand() % 100) / 100 + rand() % 200  - 100;
        matrixB[i][j] = float(rand() % 100) / 100 + rand() % 200  - 100;
      }
    }
  }

  void matrixAdd(){
    for ( int i = 0; i < matrixSize; i++ ) {
      for ( int j = 0; j < matrixSize; j++ ) {
        matrixSum[i][j] = matrixA[i][j] + matrixB[i][j];
      }
    }
  }

  void matrixMultiply(){
    for ( int i = 0; i < matrixSize; i++ ) {
      for ( int j = 0; j < matrixSize; j++ ) {
        matrixProduct[i][j] = valueAtPositionOfMatrixToMultiply(i, j);
      }
    }
  }

  float valueAtPositionOfMatrixToMultiply(int row, int column) {
    float valueAtPosition = 0;
    for ( int i = 0; i < matrixSize; i++ ) {
      valueAtPosition += matrixA[row][i] * matrixB[i][column];
    }
    return valueAtPosition;
  }

  void MatrixesPrint() {
    cout << "Matriz A:\n\n";
    matrixPrint(matrixA);
    cout << "Matriz B:\n\n";
    matrixPrint(matrixB);
    cout << "Matriz A + B:\n\n";
    matrixPrint(matrixSum);
    cout << "Matriz A * B:\n\n";
    matrixPrint(matrixProduct);

  }

  void matrixPrint(float matrix[10][10]) {
    for ( int i = 0; i < matrixSize; i++ ) {
      cout << " | ";
      for ( int j = 0; j < matrixSize; j++ ) {
        cout << fixed << setprecision(2) << matrix[i][j];
		(matrix[i][j] < 10 && matrix[i][j] > -10) ? cout << "    \t" : cout << "   \t" ;
      }
      cout << endl;
    }
  cout << endl;
  }

private:
  int matrixSize;
  float matrixA[10][10], matrixB[10][10], matrixSum[10][10], matrixProduct[10][10];
};

int main()
{
  // system("cls");
  char option;
  bool cycleMenu = true;
  do
  {
    cout << "a.- Tamano y rangos de los Tipos de Datos Primitivos" << endl;
    cout << "b.- Ejemplo de tipo de dato abstracto" << endl;
    cout << "c.- Salir" << endl;
    cout << "Elige un opcion:" << endl;
    cin >> option;
    // system("cls");
    switch (option)
    {
    case 'a': //Primitive data types
      PrimitiveDataTypes ValuesTable;
      ValuesTable.PrintValuesTable();
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
    if (option != 'c')
      cout << endl;
      // system("pause");
  } while (cycleMenu);
}
