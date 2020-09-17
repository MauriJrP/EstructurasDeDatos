class StructuredDataTypes
{
public:
  void matrixConstructor();

  void matrixAdd();

  void matrixMultiply();

  float valueAtPositionOfMatrixToMultiply(int row, int column);

  void MatrixesPrint();

  void matrixPrint(float matrix[10][10]);

private:
  int matrixSize;
  float matrixA[10][10], matrixB[10][10], matrixSum[10][10], matrixProduct[10][10];
};