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

    HeapObj(){
      data = {};
      key = -2147483648;//TODO make this -inf -2,147,483,648 is the biggest number tha an int can go to
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
  T Peek();
  void Insert(T, int);
  void print();
  void MaxHeapify(int);
};

#include "HeapQ.cpp"

#endif
