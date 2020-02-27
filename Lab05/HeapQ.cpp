#include "HeapQ.h"



template<class T>
void HeapQ<T>::IncreaseKey(){

}


//Extends the array when needed
template<class T>
void HeapQ<T>::ExpandArray(){
  this->length *= 2;
  int* newArr = new HeapObj<T>[this->length];
  for(int i=0; i<heapSize; i++){
    newArr[i] = this->arr[i];
  }
  this->arr = newArr;
}

//Defualt constructor
template<class T>
HeapQ<T>::HeapQ(){
  this->arr = new HeapObj<T>[100];
  this->length = 100;
  this->heapSize = 0;
}


//Copy Constructor
template<class T>
HeapQ<T>::HeapQ(HeapQ<T>& B){
   this->length = B.length;
   this->heapSize = B.heapSize;
   this->arr = new HeapObj<T>[this->length];
   for(int i=0; i < this->length; i++){
     this->arr[i] = B.arr[i];
  }
}


//Deconstructor
template<class T>
HeapQ<T>::~HeapQ(){
  delete [] arr;
}


//= operator
template<class T>
HeapQ<T>& HeapQ<T>::operator=(HeapQ B){
  if(length > 0){
    delete [] arr;
  }
   this->heapSize = B.heapSize;
   this->length = B.length;
   this->arr = new HeapObj<T>[this->length];
   for(int i=0; i < this->length; i++){
     this->arr[i] = B.arr[i];
  }
}


//Dequeues the biggest element
template<class T>
HeapObj<T> HeapQ<T>::ExtractMax(){

}


//Looks at data at the top of a queue
template<class T>
HeapObj<T> HeapQ<T>::Peek(){

}


//Inserts a new array location
template<class T>
void HeapQ<T>::Insert(T, int){

}


//prints out whole queue
template<class T>
void HeapQ<T>::print(){

}
