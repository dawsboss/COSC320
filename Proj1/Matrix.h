#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <math.h>
// #include "Logger.h"
template <class DataType>
class Matrix{
private:
  DataType** arr;//Matrix
  unsigned long long Rows;//n
  unsigned long long Columns;//m
  bool isSymetric(){
    for(int i=0; i<Rows; i++){
      for(int j=0; j<Columns; j++){
        if(this->arr[i][j]!=this->arr[j][i]){
          return false;
        }
      }
    }
    return true;
  }
  Matrix<DataType> pad(Matrix<DataType> oldMatrix, int k){//k being the number of needed rows/Columns
    Matrix<DataType> newMatrix();
  }

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
  Matrix<DataType> transpose(){
    int i, k;
    Matrix<DataType> rtn(this->Columns, this->Rows);
    for(i = 0; i < this->Rows; i++)
      for(k = 0; k < this->Columns; k++)
        rtn.setElement( k, i, this->getElement(i, k));

    return rtn;
  }


Matrix<DataType> Inverse(){
  Matrix<DataType> Temp = *this;
  if( this->Rows != this->Columns)
    throw "Matrix not square!";
  if(!isSymetric())
    throw "Matrix not symetric";
  if(log2(Rows) - (int)log2(Rows) !=0){
    Temp = pad(*this, log2(Rows) - (int)log2(Rows));
    Matrix<DataType> rtn(Rows,Columns);
    for(int i=0;i<Rows;i++){
      for(int j=0;j<Columns;j++){
        rtn.setElement(i,j,Temp.getElement(i,j));
      }
    }
    return rtn;
  }
  if(log2(Rows) - (int)log2(Rows) == 0)
    return this->_Inverse(Temp);

}

Matrix<DataType> _Inverse(Matrix<DataType> lad){
  //Assumes edge cases are statments
  //Private Inverse edition
  if(lad.Rows <= 1){
    Matrix<DataType> rtn(1,1);
    rtn.arr[0][0]=1.0/lad.getElement(0,0);
    return rtn;
  }

  Matrix<DataType> B(Rows/2, Columns/2);
  Matrix<DataType> C(Rows/2, Columns/2);
  Matrix<DataType> D(Rows/2, Columns/2);
  Matrix<DataType> CT(Rows/2, Columns/2);

  // for(int i=0; i<Rows; i++){
  //   for(int j=0; j<Columns; j++){
      // std::cout<<"Indexers: i:"<<i<<" j:"<<j<<std::endl;
      // if(i>=0 && i<Rows/2 && j>=0 && j<Columns/2){//These if statements put the data from the this data into 4 seperate matrixies and the if statments put the data where it should go as it is seen
      //   std::cout<<"B: Indexers: i:"<<i<<" j:"<<j<<std::endl;
      //   std::cout<<getElement(i,j)<<std::endl;
      //   B.setElement(i,j,lad.getElement(i,j));
      // }else if(i>=0 && i<Rows/2 && j>=(Columns/2) && j<Columns){
      //   std::cout<<"C: Indexers: i:"<<i<<" j:"<<j<<std::endl;
      //   std::cout<<getElement(i,j)<<std::endl;
      //   CT.setElement(i,j-(Columns),lad.getElement(i,j));
      // }else if(i>=(Rows/2) && i<Rows && j>=0 && j<Columns/2){//Should just be the transpose of C but heck we will do it
      //   std::cout<<"CT: Indexers: i:"<<i<<" j:"<<j<<std::endl;
      //   std::cout<<getElement(i,j)<<std::endl;
      //   C.setElement(i-(Rows),j,lad.getElement(i,j));
      // }else if(i>=(Rows/2) && i<Rows && j>=(Columns/2) && j<Columns){
      //   std::cout<<"D: Indexers: i:"<<i<<" j:"<<j<<std::endl;
      //   std::cout<<getElement(i,j)<<std::endl;
      //   D.setElement(i-(Rows),j-(Columns),lad.getElement(i,j));
      // }else{
      //   std::cout<<"error overflow"<<std::endl;
      // }
  for(int i=0; i<Rows; i++){
    for(int j=0; j<Columns; j++){
  		if(i<Rows/2 && j<Columns/2)//Top left
				B.setElement( i, j, lad.getElement(i,j) );
			else if(i>=Rows/2 && j<Columns/2)//Bottom left
				C.setElement( i-(Rows/2), j, lad.getElement(i,j) );
			else if(i<Rows/2 && j>=Columns/2)//Top right
				CT.setElement( i, j-(Columns/2), lad.getElement(i,j) );
			else if(i>=Rows/2 && j>=Columns/2)//bottom right
				D.setElement( i-(Rows/2), j-(Columns/2), lad.getElement(i,j) );
			else
				std::cout<<"Overflow Splitting"<<std::endl;

		}
	}


  Matrix<DataType> BPrime = B.Inverse();
  Matrix<DataType> W = C*BPrime;
  Matrix<DataType> WT = W.transpose();
  Matrix<DataType> X = W*CT;
  Matrix<DataType> S = D-X;
  Matrix<DataType> V = S.Inverse();
  Matrix<DataType> Y = V*W;
  Matrix<DataType> YT = Y.transpose();
  Matrix<DataType> T = YT*(-1);
  Matrix<DataType> U = Y*(-1);
  Matrix<DataType> Z = WT*Y;
  Matrix<DataType> R = BPrime+Z;
  Matrix<DataType> AInverse(Rows, Columns);
  for(int i=0; i<Rows; i++){
    for(int j=0; j<Columns; j++){
      if(i<Rows/2 &&  j<Columns/2){//These if statements put the data from the this data into 4 seperate matrixies and the if statments put the data where it should go as it is seen
        AInverse.setElement(i,j,B.getElement(i,j));
      }else if(i>=Rows/2 && j<(Columns/2)){
        AInverse.setElement(i, j, C.getElement(i-(Rows/2),j));
      }else if(i<(Rows/2) && j>=Columns/2){//Should just be the transpose of C but heck we will do it
        std::cout<<"I: "<<i<<" J:"<<j<<std::endl;
				AInverse.setElement(i, j, CT.getElement(i,j-(Columns/2)));
      }else if(i>=(Rows/2) && j>=(Columns/2)){
        AInverse.setElement(i, j, D.getElement(i-(Rows/2),j-(Columns/2)));
      }else{
				std::cout<<"Overflow Filling"<<std::endl;
			}
    }
  }

}









};


#endif
