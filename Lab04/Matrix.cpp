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
  Rows = 0;
  Columns = 0;
}
Matrix::Matrix(unsigned long long An, unsigned long long Am){
  Rows=An;
  Columns=Am;
  arr = new int* [An];
  for(unsigned long long i=0; i<this->Rows; i++){
    arr[i]=new int [Am];
  }
}

Matrix::Matrix(const Matrix& B){
  this->Rows=B.Rows;
  this->Columns=B.Columns;
  this->arr = new int* [this->Rows];
   for(unsigned long long i=0; i<this->Rows; i++){
    arr[i]=new int [this->Columns];
  }

  for(unsigned long long i=0; i<this->Rows; i++){
    for(unsigned long long j=0; j<this->Columns; j++){
      this->arr[i][j] = B.arr[i][j];
    }
  }

}

Matrix::~Matrix(){
  for(unsigned long long i=0; i<this->Rows; i++){
    delete[] arr[i];
  }
  delete [] arr;
}

//= operator
Matrix* Matrix::operator=(const Matrix& B){
  if((this) == &B){
    return (this);
  }
  for(unsigned long long i=0; i<this->Columns; i++){
    delete[] arr[i];
  }
  delete [] arr;

  this->Rows=B.Rows;
  this->Columns=B.Columns;
  this->arr = new int* [this->Rows];
   for(unsigned long long i=0; i<this->Rows; i++){
    arr[i]=new int [this->Columns];
  }

  for(unsigned long long i=0; i<this->Rows; i++){
    for(unsigned long long j=0; j<this->Columns; j++){
      this->arr[i][j] = B.arr[i][j];
    }
  }

  return (this);
}

//Gives access to the arr[][] rows columns
int Matrix::getElement(unsigned long long i, unsigned long long j){
      return this->arr[i][j];
}


//prints the matrix just like it wouls appear as a matrix
void Matrix::print(){
  if(this->Rows == 0 || this->Columns == 0){
    std::cout<<"Matrix empty\n";
  }
  for (int j = 0; j < this->Rows; j++) {
    for (int i = 0; i < this->Columns; i++) {
        std::cout << this->arr[j][i] <<" ";
    }
    std::cout<<std::endl;
  }
  std::cout<<std::endl;
}

//initilizaes a matrix with top left 0s and bottom right 0s and the middle 1s
void Matrix::init(){
  if(this->Rows == 0 || this->Columns == 0){
    std::cout<<"No room (m or n == 0)\n";
  }
  for (int j = 0; j < this->Rows; ++j) {
    for (int i = 0; i < this->Columns; ++i) {
      if(i==j){
        this->arr[j][i] = 1;
      }else{
	       this->arr[j][i] = 0;
      }
    }
  }
}

//Reverse of init in that the diangal is all 0 and everything else is 1s
void Matrix::Reinit(){
  if(this->Rows == 0 || this->Columns == 0){
    std::cout<<"No room (m or n == 0)\n";
  }
  for (int j = 0; j < this->Rows; ++j) {
    for (int i = 0; i < this->Columns; ++i) {
      if(i!=j){
        this->arr[j][i] = 1;
      }else{
         this->arr[j][i] = 0;
      }
    }
  }
}


//sets all items in the matrix
void Matrix::setMatrix(int x){
  if(this->Rows == 0 || this->Columns == 0){
    std::cout<<"No room (m or n == 0)\n";
  }
  for (int j = 0; j < this->Rows; ++j) {
    for (int i = 0; i < this->Columns; ++i) {
	     this->arr[j][i] = x;
    }
  }
}

//Makes athe give matrix have the top half of the array 0s
void Matrix::setTriangleMatrix(){
  if(this->Rows == 0 || this->Columns == 0){
    std::cout<<"No room (m or n == 0)\n";
  }
  int counter=Columns-1;
  for (int j = 0; j < this->Rows; ++j) {
    for (int i = 0; i < this->Columns; ++i) {
      if(i==j || i>=j){
        this->arr[j][i] = 1;
      }else{
         this->arr[j][i] = 0;
      }
    }
  }
}


//gives access to the arr[][]
void Matrix::setMatrix(int i, int j, int data){
  this->arr[i][j] = data;
}


//raises this matrix to a given n power
Matrix Matrix::pow(int n){
  if(n==1)
    return *(this);
  Matrix tmp = this->pow(n/2);
  if(n%2 == 1){
    return tmp*tmp*(*this);
  }
  return tmp*tmp;
}

//Add two matrixies together
Matrix Matrix::operator+(Matrix B){
  //Catches edge case that the two given matrixies are not the same size
  if( this->Rows!=B.getN() || this->Columns!=B.getM() ){
    std::string x = "The matrixes don't have the same size""The matrixes don't have the same size";
    throw x;
  }
  std::cout<<"Test1\n";
  Matrix rtn(this->Rows, this->Columns);
  std::cout<<"Test3\n";
  for(int i=0; i<this->Rows; i++){
    for(int j=0; j<this->Columns; j++){
      // rtn[i][j] = (this->arr[i][j] + B.arr[i][j]);
      rtn.arr[i][j] = (this->arr[i][j] + B.arr[i][j]);
    }
  }
  std::cout<<"Test4\n";
  return rtn;
}

//subtract matrix A from matrix B
Matrix Matrix::operator-(Matrix B){
  //Catches eadge case that the two given matrixies are not the same size
  if( this->Rows!=B.getN() || this->Columns!=B.getM() ){
    std::string x = "The matrixes don't have the same size";
    throw x;
  }
  Matrix rtn(this->Rows, this->Columns);
  for(int i=0; i<this->Rows; i++){
    for(int j=0; j<this->Columns; j++){
      // rtn[i][j] = (this->arr[i][j] + B.arr[i][j]);
      rtn.arr[i][j] = (this->arr[i][j] - B.arr[i][j]);
    }
  }
    return rtn;

}

//Multiply Matrix A and B
Matrix Matrix::operator*(Matrix B){
  if( this->Columns != B.Rows ){
    std::string x = "The matrixes don't have the same size";
    throw x;
  }
  Matrix rtn(this->Rows, B.Columns);
  for(int both = 0; both < this->Rows; both++){
    for(int i = 0; i < B.Columns; i++){
      int sum=0;
      for(int j = 0; j < this->Columns; j++){
	        sum+= this->arr[both][j]*B.arr[j][i];
      }
      rtn.arr[both][i] = sum;
    }
  }
  return rtn;
}

//Multiply Matrix A by a scalor
Matrix Matrix::operator*(int B){
  //Catches edge case that the two given matrixies are not the same size
  if( this->Rows ==0 || this->Columns ==0 ){
    std::string x = "The matrixes don't have the same size";
    throw x;
  }
  Matrix rtn(this->Rows, this->Columns);
  for(int i=0; i<this->Rows; i++){
    for(int j=0; j<this->Columns; j++){
      // rtn[i][j] = (this->arr[i][j] + B.arr[i][j]);
      rtn.arr[i][j] = (this->arr[i][j] * B);
    }
  }
    return rtn;
}
