#ifndef HEAPQ_H
#define HEAPQ_H

#include <iostream>
#include <math.h> //log2()

template<class T>
  struct HeapObj{
    T data;
    int key;

    int left(int i){
      return 2*i;
    }
    int right(int i){
      return 2*i+1;
    }
    int parrent(int i){
      if(i==0)
        return;//edge case
      if(i%2==0)
        return i/2;
      return (i/2)+1;
    }

    HeapObj(){
      data = {};
      key = -1000000;//TODO make this -inf
    }

    HeapObj(T d, int k){
      data = d;
      key = k;
    }

    HeapObj<T>& operator=(HeapObj<T>& x){
      if(this == &x)
        return *this;
      data = x.data;
      key = x.key;
      return *this;
    }
  };

template<class T>
class HeapQ{
private:
  int length;
  int heapSize;
  HeapObj<T>* arr;

  void IncreaseKey(int k);
  void ExpandArray();
  void swap(HeapObj<T>&, HeapObj<T>&);

public:

  HeapQ();
  HeapQ(HeapQ&);
  ~HeapQ();
  HeapQ& operator=(HeapQ);


  T ExtractMax();
  HeapObj<T> Peek();
  void Insert(T, int);
  void print();
  void MaxHeapify(int);
};

#include "HeapQ.cpp"

#endif
