#include "Matrix.h"

int main(){
  std::cout<<"Test\n";
  unsigned long long x=4;
  unsigned long long y=4;
  Matrix B(x,y);

  Matrix A(x,y);
  A.init();
  B.init();

    A = A*3;
    std::cout<<"Test8\n";
    A.print();
  return 0;
}
