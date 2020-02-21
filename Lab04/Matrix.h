#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
// #include "Logger.h"

class Matrix{
private:
  int** arr;//Matrix
  unsigned long long n;//Rows
  unsigned long long m;//Columns

public:
  Matrix();//Defualt Constructor
  Matrix(unsigned long long , unsigned long long );
  Matrix(const Matrix&);
  ~Matrix();//Deconstructor
  Matrix* operator=(const Matrix& B);//= operator

  unsigned long long getN(){ return n; }
  unsigned long long getM(){ return m; }
  void print();//prints out matrix as if it was a matrix
  void init();//initializes values to the whole matrix

//  unsigned long long operator[][](int, int);//allows you to call [][] operaot as if te matrix was an array
  //off brand verssion below
  int getArrSpot(unsigned long long, unsigned long long);
//
  //offBrand verssion
  void setArrSpot(unsigned long long, unsigned long long, int);


  Matrix operator+(Matrix B);//Add two matrixies together
  Matrix operator-(Matrix B);//subtract matrix A from matrix B
  Matrix operator*(Matrix B);//Multiply Matrix A and B
  //Extra Credit add a multiply operator that allows to mulitply by scalors
  Matrix operator*(int B);


};


#endif
