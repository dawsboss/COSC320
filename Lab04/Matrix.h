#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
// #include "Logger.h"

class Matrix{
private:
  int** arr;//Matrix
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
  void print();//prints out matrix as if it was a matrix
  void init();//initializes values to the whole matrix
  
  //sets the matrix to have all the same number x
  void setMatrix(int);



  Matrix operator+(Matrix B);//Add two matrixies together
  Matrix operator-(Matrix B);//subtract matrix A from matrix B
  Matrix operator*(Matrix B);//Multiply Matrix A and B
  //Extra Credit add a multiply operator that allows to mulitply by scalors
  Matrix operator*(int B);


};


#endif
