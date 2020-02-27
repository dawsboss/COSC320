#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
// #include "Logger.h"
template <class DataType>
class Matrix{
private:
  DataType** arr;//Matrix
  unsigned long long Rows;//n
  unsigned long long Columns;//m

public:
  Matrix();//Defualt Constructor
  Matrix(unsigned long long , unsigned long long );
  Matrix(const Matrix&);
  ~Matrix();//Deconstructor
  Matrix* operator=(const Matrix& B);//= operator

  unsigned long long getN(){ return Rows; }
  unsigned long long getM(){ return Columns; }
  DataType getElement(unsigned long long, unsigned long long);//Gives access to the arr[][] rows columns
  void print();//prints out matrix as if it was a matrix

  //initilizaes a matrix with top left 0s and bottom right 0s and the middle 1s
  void init();
  //Reverse of init in that the diangal is all 0 and everything else is 1s
  void Reinit();
  //sets the matrix to have all the same number x
  void setMatrix(DataType);
  //Makes
  void setTriangleMatrix();
  //gives access to the arr[rows][column]
  void setMatrix(int, int, DataType);

  //raises this matrix to a given n power
  Matrix pow(int);
  Matrix operator+(Matrix B);//Add two matrixies together
  Matrix operator-(Matrix B);//subtract matrix A from matrix B
  Matrix operator*(Matrix B);//Multiply Matrix A and B
  //Extra Credit add a multiply operator that allows to mulitply by scalors
  Matrix operator*(int B);


};


#endif
