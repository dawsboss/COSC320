#ifndef HEAPQ_H
#define HEAPQ_H

#include <iostream>
#include <math.h> //log2()

template<class T>
  struct HeapObj{
    T data;
    int key;
  };

template<class T>
class HeapQ{
private:
  int length;
  int heapSize;
  HeapObj<T>* arr;

  void IncreaseKey();
  void ExpandArray();

public:

  HeapQ();
  HeapQ(HeapQ&);
  ~HeapQ();
  HeapQ& operator=(HeapQ);


  HeapObj<T> ExtractMax();
  HeapObj<T> Peek();
  void Insert(T, int);
  void print(int,int);

};


#endif
