#include "Matrix.h"

// #include <iostream>
// #include "Logger.h"
//
// class Matrix{
// private:
//   int** arr;//Matrix
//   unsigned long long n;//Rows
//   unsigned long long m;//Columns
//
// public:
//   Matrix();//Defualt Constructor
//   Matrix(unsigned long long , unsigned long long );
//   Matrix(const Matrix&);
//   ~Matrix();//Deconstructor
//
//
//   Matrix* operator+(Matrix B);//Add two matrixies together
//   Matrix* operator-(Matrix B);//subtract matrix A from matrix B
//   Matrix* operator*(Matrix B);//Multiply Matrix A and B
//
//
// };
//
//
// };

Matrix::Matrix(){
  n = 0;
  m = 0;
}
Matrix::Matrix(unsigned long long An, unsigned long long Am){
  n=An;
  m=Am;
  arr = new int* [An];
  for(unsigned long long i=0; i<this->m; i++){
    arr[i]=new int [Am];
  }
}

Matrix::Matrix(const Matrix& x){
  this->arr = x.arr;
  this->m = x.m;
  this->n = x.n;
}

Matrix::~Matrix(){
  for(unsigned long long i=0; i<this->m; i++){
    delete[] arr[i];
  }
  delete [] arr;
}

//= operator
Matrix* Matrix::operator=(const Matrix& B){
  // for (unsigned long long j = 0; j < this->n; j++) {
  //   for (unsigned long long i = 0; i < this->m; i++) {
  //       this->setArrSpot(i,j,B.getArrSpot(i,j));
  //   }
  // }
  this->arr = B.arr;
  return (this);
}



void Matrix::print(){
  if(this->n == 0 || this->m == 0){
    std::cout<<"Matrix empty\n";
  }
  for (int j = 0; j < this->n; j++) {
    for (int i = 0; i < this->m; i++) {
        std::cout << this->arr[j][i] <<" ";
    }
    std::cout<<std::endl;
  }
}

void Matrix::init(){
  if(this->n == 0 || this->m == 0){
    std::cout<<"No room (m or n == 0)\n";
  }
  for (int j = 0; j < this->n; ++j) {
    for (int i = 0; i < this->m; ++i) {
        this->arr[j][i] = 1;
    }
  }
}

int Matrix::getArrSpot(unsigned long long i, unsigned long long j){
  if(i >= this->n || j >= this->m){
    throw "Out of bounds";
  }
  return this->arr[i][j];
}

void Matrix::setArrSpot(unsigned long long i, unsigned long long j, int data){
  if(i >= this->n || j >= this->m){
    throw "Out of bounds";
  }
  this->arr[i][j] = data;
}


//Add two matrixies together
Matrix Matrix::operator+(Matrix B){
  //Catches edge case that the two given matrixies are not the same size
  if( this->n!=B.getN() || this->m!=B.getM() ){
    throw "The matrixes don't have the same size";
  }
  std::cout<<"Test1\n";
  Matrix rtn(this->n, this->m);
  std::cout<<"Test3\n";
  for(int i=0; i<this->n; i++){
    for(int j=0; j<this->m; j++){
      // rtn[i][j] = (this->arr[i][j] + B.arr[i][j]);
      rtn.setArrSpot(i,j,(this->arr[i][j] + B.arr[i][j]));
    }
  }
  std::cout<<"Test4\n";
  return rtn;
}

//subtract matrix A from matrix B
Matrix Matrix::operator-(Matrix B){
  //Catches edge case that the two given matrixies are not the same size
  if( this->n!=B.getN() || this->m!=B.getM() ){
    throw "The matrixes don't have the same size";
  }
  Matrix rtn(this->n, this->m);
  for(int i=0; i<this->n; i++){
    for(int j=0; j<this->m; j++){
      // rtn[i][j] = (this->arr[i][j] + B.arr[i][j]);
      rtn.setArrSpot(i,j,(this->arr[i][j] - B.getArrSpot(i,j)));
    }
  }
    return rtn;

}

//Multiply Matrix A and B
Matrix Matrix::operator*(Matrix B){

}

Matrix Matrix::operator*(int B){
  //Catches edge case that the two given matrixies are not the same size
  if( this->n ==0 || this->m ==0 ){
    throw "The matrixes don't have the same size";
  }
  Matrix rtn(this->n, this->m);
  for(int i=0; i<this->n; i++){
    for(int j=0; j<this->m; j++){
      // rtn[i][j] = (this->arr[i][j] + B.arr[i][j]);
      rtn.setArrSpot(i,j,(this->arr[i][j] * B));
    }
  }
    return rtn;
}
