#include <iostream>
#include "HeapQ.h"


int main(){
  std::string y;
  int x;
  HeapQ<std::string> h;
  h.Insert("Grant", 10);
  h.Insert("Alice", 1);
  h.Insert("Bob", 11);
  h.Insert("Jeff", 2);
  y = h.Peek();
  std::cout<<"Peeked:"<<y<<std::endl;
  h.print();
  y = h.ExtractMax();
  std::cout<<y<<std::endl;
  h.print();


  HeapQ<double> g;
  g.Insert(10, 10);
  g.Insert(11,5);
  g.Insert(8,1);
  g.Insert(8,11);
  x = g.Peek();
  std::cout<<"Peeked:"<<x<<std::endl;
  g.print();
  x = g.ExtractMax();
  g.print();
  std::cout<<x<<std::endl;
  return 0;
}
