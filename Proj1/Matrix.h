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
  //Lab04:
  Matrix();//Defualt Constructor
  Matrix(unsigned long long , unsigned long long );
  Matrix(const Matrix&);
  ~Matrix();//Deconstructor
  Matrix* operator=(const Matrix& B);//= operator

  unsigned long long getN(){ return Rows; }
  unsigned long long getM(){ return Columns; }
  DataType getElement(unsigned long long, unsigned long long);//Gives access to the arr[][] rows columns
  void setElement(int, int, DataType);  //gives access to the arr[rows][column]
  void print();//prints out matrix as if it was a matrix

  //initilizaes a matrix with top left 0s and bottom right 0s and the middle 1s
  void init();
  //Reverse of init in that the diangal is all 0 and everything else is 1s
  void Reinit();
  //sets the matrix to have all the same number x
  void setMatrix(DataType);
  //Makes
  void setTriangleMatrix();


  //raises this matrix to a given n power
  Matrix pow(int);
  Matrix operator+(Matrix B);//Add two matrixies together
  Matrix operator-(Matrix B);//subtract matrix A from matrix B
  Matrix operator*(Matrix B);//Multiply Matrix A and B
  //Extra Credit add a multiply operator that allows to mulitply by scalors
  Matrix operator*(int B);












//TODO: New for proj1
void transposeMatixS(Matrix<DataType> *A, Matrix<DataType> *F){
  int i, k;
  for(i = 0; i < A -> rows; i++)
    for(k = 0; k < A -> cols; k++)
      F.setElement( k, i, A.getElement(i, k));
}




Matrix<DataType>& Inverse(){
  //TODO Edge cases


  Matrix<DataType> B(Rows/2, Columns/2);
  Matrix<DataType> C(Rows/2, Columns/2);
  Matrix<DataType> D(Rows/2, Columns/2);
  Matrix<DataType> CT(Rows/2, Columns/2);

  for(int i=0; i<Rows; i++){
    for(int j=0; j<Columns; j++){
      if(i>=0 && i<=Rows/2 && j>=0 && j<=Columns/2){//These if statements put the data from the this data into 4 seperate matrixies and the if statments put the data where it should go as it is seen
        B.setElement(i,j,this->arr[i][j]);
      }else if(i>=0 && i<=Rows/2 && j>=(Columns/2)+1 && j<=Columns){
        C.setElement(i,j,this->arr[i][j]);
      }else if(i>=(Rows/2)+1 && i<=Rows && j>=0 && j<=Columns/2){//Should just be the transpose of C but heck we will do it
        CT.setElement(i,j,this->arr[i][j]);
      }else if(i>=(Rows/2)+1 && i<=Rows && j>=(Columns/2)+1 && j<=Columns){
        D.setElement(i,j,this->arr[i][j]);
      }
      std::cout<<"error overflow"<<std::endl;
    }
  }


  Matrix<DataType> BPrime = B.inverse();
  Matrix<DataType> W = C*BPrime;
  Matrix<DataType> WT = W.transpose();
  Matrix<DataType> X = W*CT;
  Matrix<DataType> S = D-X;
  Matrix<DataType> V = S.inverse();
  Matrix<DataType> Y = V*W;
  Matrix<DataType> YT = Y.transpose();
  Matrix<DataType> T = YT*(-1);
  Matrix<DataType> U = Y*(-1);
  Matrix<DataType> Z = WT*Y;
  Matrix<DataType> R = BPrime+Z;
  Matrix<DataType> AInverse(Rows, Columns);
  for(int i=0; i<Rows; i++){
    for(int j=0; j<Columns; j++){
      if(i>=0 && i<=Rows/2 && j>=0 && j<=Columns/2){//These if statements put the data from the this data into 4 seperate matrixies and the if statments put the data where it should go as it is seen
        AInverse.setElement(i,j,B.getElement(i,j));
      }else if(i>=0 && i<=Rows/2 && j>=(Columns/2)+1 && j<=Columns){
        AInverse.setElement(i,j,C.getElement(i,j));
      }else if(i>=(Rows/2)+1 && i<=Rows && j>=0 && j<=Columns/2){//Should just be the transpose of C but heck we will do it
        AInverse.setElement(i,j,CT.getElement(i,j));
      }else if(i>=(Rows/2)+1 && i<=Rows && j>=(Columns/2)+1 && j<=Columns){
        AInverse.setElement(i,j,D.getElement(i,j));
      }
    }
  }

}









};


#endif
