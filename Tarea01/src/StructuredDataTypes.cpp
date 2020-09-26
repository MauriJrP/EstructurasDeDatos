#include "../include/StructuredDataTypes.h"

using namespace std;

void StructuredDataTypes::matrixConstructor() {
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

void StructuredDataTypes::matrixAdd(){
  for ( int i = 0; i < matrixSize; i++ ) {
    for ( int j = 0; j < matrixSize; j++ ) {
      matrixSum[i][j] = matrixA[i][j] + matrixB[i][j];
    }
  }
}

void StructuredDataTypes::matrixMultiply(){
  for ( int i = 0; i < matrixSize; i++ ) {
    for ( int j = 0; j < matrixSize; j++ ) {
      matrixProduct[i][j] = valueAtPositionOfMatrixToMultiply(i, j);
    }
  }
}

float StructuredDataTypes::valueAtPositionOfMatrixToMultiply(int row, int column) {
  float valueAtPosition = 0;
  for ( int i = 0; i < matrixSize; i++ ) {
    valueAtPosition += matrixA[row][i] * matrixB[i][column];
  }
  return valueAtPosition;
}

void StructuredDataTypes::MatrixesPrint() {
  cout << "Matriz A:\n\n";
  matrixPrint(matrixA);
  cout << "Matriz B:\n\n";
  matrixPrint(matrixB);
  cout << "Matriz A + B:\n\n";
  matrixPrint(matrixSum);
  cout << "Matriz A * B:\n\n";
  matrixPrint(matrixProduct);
}

void StructuredDataTypes::matrixPrint(float matrix[10][10]) {
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