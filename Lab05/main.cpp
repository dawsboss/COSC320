#include <iostream>
#include "HeapQ.h"


int main(){
  HeapQ<std::string> h;
  h.Insert("Grant", 10);
  h.Insert("Alice", 1);
  h.Insert("Bob", 11);
  h.Insert("Jeff", 2);
  h.print();
  std::string y = h.ExtractMax();
  std::cout<<y<<std::endl;
  h.print();

  HeapQ<double> g;
  g.Insert(10, 10);
  g.Insert(11,5);
  g.Insert(8,1);
  g.Insert(8,11);
  g.print();
  int x = g.ExtractMax();
  g.print();
  std::cout<<x<<std::endl;
  return 0;
}
