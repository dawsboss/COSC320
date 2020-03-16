#include "Matrix.h"

template<class DataType>
Matrix<DataType>::Matrix(){
  Rows = 0;
  Columns = 0;
}

template <class DataType>
Matrix<DataType>::Matrix(unsigned long long An, unsigned long long Am){
  Rows=An;
  Columns=Am;
  arr = new DataType* [An];
  for(unsigned long long i=0; i<this->Rows; i++){
    arr[i]=new DataType [Am];
  }
}

template<class DataType>
Matrix<DataType>::Matrix(const Matrix& B){
  this->Rows=B.Rows;
  this->Columns=B.Columns;
  this->arr = new DataType* [this->Rows];
   for(unsigned long long i=0; i<this->Rows; i++){
    arr[i]=new DataType [this->Columns];
  }

  for(unsigned long long i=0; i<this->Rows; i++){
    for(unsigned long long j=0; j<this->Columns; j++){
      this->arr[i][j] = B.arr[i][j];
    }
  }

}

template<class DataType>
Matrix<DataType>::~Matrix(){
  for(unsigned long long i=0; i<this->Rows; i++){
    delete[] arr[i];
  }
  delete [] arr;
}

//= operator
template<class DataType>
Matrix<DataType>* Matrix<DataType>::operator=(const Matrix& B){
  if((this) == &B){
    return (this);
  }
  //if the Matrix B is empty already
  if(this->Rows==0 || this->Columns==0){

  }else{
    for(unsigned long long i=0; i<this->Columns; i++){
      delete[] arr[i];
    }
    delete [] arr;
  }

  this->Rows=B.Rows;
  this->Columns=B.Columns;
  this->arr = new DataType* [this->Rows];
   for(unsigned long long i=0; i<this->Rows; i++){
    arr[i]=new DataType [this->Columns];
  }

  for(unsigned long long i=0; i<this->Rows; i++){
    for(unsigned long long j=0; j<this->Columns; j++){
      this->arr[i][j] = B.arr[i][j];
    }
  }

  return (this);
}

//Gives access to the arr[][] rows columns
template<class DataType>
DataType Matrix<DataType>::getElement(unsigned long long i, unsigned long long j){
      return this->arr[i][j];
}

template<class T>
void Matrix<T>::setElement(int i, int j, T data){
  this->arr[i][j] = data;
}  //gives access to the arr[rows][column]


//prints the matrix just like it wouls appear as a matrix
template<class DataType>
void Matrix<DataType>::print(){
  if(this->Rows == 0 || this->Columns == 0){
    std::cout<<"Matrix empty\n";
  }
  for (unsigned long long j = 0; j < this->Rows; j++) {
    for (unsigned i = 0; i < this->Columns; i++) {
        std::cout << this->arr[j][i] <<" ";
    }
    std::cout<<std::endl;
  }
  std::cout<<std::endl;
}

//initilizaes a matrix with top left 0s and bottom right 0s and the middle 1s
template<class DataType>
void Matrix<DataType>::init(){
  if(this->Rows == 0 || this->Columns == 0){
    std::cout<<"No room (m or n == 0)\n";
  }
  for (unsigned long long j = 0; j < this->Rows; ++j) {
    for (unsigned long long i = 0; i < this->Columns; ++i) {
      if(i==j){
        this->arr[j][i] = 1;
      }else{
	       this->arr[j][i] = 0;
      }
    }
  }
}

//Reverse of init in that the diangal is all 0 and everything else is 1s
template<class DataType>
void Matrix<DataType>::Reinit(){
  if(this->Rows == 0 || this->Columns == 0){
    std::cout<<"No room (m or n == 0)\n";
  }
  for (unsigned long long j = 0; j < this->Rows; ++j) {
    for (unsigned long long i = 0; i < this->Columns; ++i) {
      if(i!=j){
        this->arr[j][i] = 1;
      }else{
         this->arr[j][i] = 0;
      }
    }
  }
}


//sets all items in the matrix
template<class DataType>
void Matrix<DataType>::setMatrix(DataType x){
  if(this->Rows == 0 || this->Columns == 0){
    std::cout<<"No room (m or n == 0)\n";
  }
  for (unsigned long long j = 0; j < this->Rows; ++j) {
    for (unsigned long long i = 0; i < this->Columns; ++i) {
	     this->arr[j][i] = x;
    }
  }
}

//Makes athe give matrix have the top half of the array 0s
template<class DataType>
void Matrix<DataType>::setTriangleMatrix(){
  if(this->Rows == 0 || this->Columns == 0){
    std::cout<<"No room (m or n == 0)\n";
  }
  for (unsigned long long j = 0; j < this->Rows; ++j) {
    for (unsigned long long i = 0; i < this->Columns; ++i) {
      if(i==j || i>=j){
        this->arr[j][i] = 1;
      }else{
         this->arr[j][i] = 0;
      }
    }
  }
}

//Gives a random value in every position in a matrix
template<class DataType>
void Matrix<DataType>::setRandMatrix(){
  if(this->Rows == 0 || this->Columns == 0){
    std::cout<<"No room (m or n == 0)\n";
  }
  for (unsigned long long j = 0; j < this->Rows; ++j) {
    for (unsigned long long i = 0; i < this->Columns; ++i) {
      this->arr[i][j] = (int)rand() % (100) + 1;
    }
  }
}



//raises this matrix to a given n power
template<class DataType>
Matrix<DataType> Matrix<DataType>::pow(int n){
  if(n==1)
    return *(this);
  Matrix<DataType> tmp = this->pow(n/2);
  if(n%2 == 1){
    return tmp*tmp*(*this);
  }
  return tmp*tmp;
}

//Add two matrixies together
template<class DataType>
Matrix<DataType> Matrix<DataType>::operator+(Matrix<DataType> B){
  //Catches edge case that the two given matrixies are not the same size

  if( this->Rows!=B.getN() || this->Columns!=B.getM() ){
    this->numOfOp++;
    std::string x = "The matrixes don't have the same size""The matrixes don't have the same size";
    throw x;
  }
  Matrix<DataType> rtn(this->Rows, this->Columns);
  for(unsigned long long i=0; i<this->Rows; i++){
    this->numOfOp++;
    for(unsigned long long j=0; j<this->Columns; j++){
      this->numOfOp+=2;
      rtn.arr[i][j] = (this->arr[i][j] + B.arr[i][j]);
    }
  }
  return rtn;
}

//subtract matrix A from matrix B
template<class DataType>
Matrix<DataType> Matrix<DataType>::operator-(Matrix<DataType> B){
  //Catches eadge case that the two given matrixies are not the same size
  if( this->Rows!=B.getN() || this->Columns!=B.getM() ){
    this->numOfOp++;
    std::string x = "The matrixes don't have the same size";
    throw x;
  }
  Matrix<DataType> rtn(this->Rows, this->Columns);
  for(unsigned long long i=0; i<this->Rows; i++){
    this->numOfOp++;
    for(unsigned long long j=0; j<this->Columns; j++){
      this->numOfOp+=2;
      rtn.arr[i][j] = (this->arr[i][j] - B.arr[i][j]);
    }
  }
    return rtn;

}

//Multiply Matrix A and B
template<class DataType>
Matrix<DataType> Matrix<DataType>::operator*(Matrix<DataType> B){
  if( this->Columns != B.Rows ){
    this->numOfOp++;
    std::string x = "The matrixes don't have the same size";
    throw x;
  }
  Matrix<DataType> rtn(this->Rows, B.Columns);
  for(unsigned long long both = 0; both < this->Rows; both++){
    this->numOfOp++;
    for(unsigned long long i = 0; i < B.Columns; i++){
      this->numOfOp++;
      DataType sum=0;
      for(unsigned long long j = 0; j < this->Columns; j++){
        this->numOfOp+=2;
	        sum += this->arr[both][j]*B.arr[j][i];
      }
      this->numOfOp++;
      rtn.arr[both][i] = sum;
    }
  }
  return rtn;
}

//Multiply Matrix A by a scalor
template<class DataType>
Matrix<DataType> Matrix<DataType>::operator*(int B){
  //Catches edge case that the two given matrixies are not the same size
  if( this->Rows ==0 || this->Columns ==0 ){
    this->numOfOp++;
    std::string x = "The matrixes don't have the same size";
    throw x;
  }
  Matrix<DataType> rtn(this->Rows, this->Columns);
  for(unsigned long long i=0; i<this->Rows; i++){
    this->numOfOp++;
    for(unsigned long long j=0; j<this->Columns; j++){
      this->numOfOp+=2;
      // rtn[i][j] = (this->arr[i][j] + B.arr[i][j]);
      rtn.arr[i][j] = (this->arr[i][j] * B);
    }
  }
    return rtn;
}
