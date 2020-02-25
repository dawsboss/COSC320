#include "Matrix.h"

int main(){
  unsigned long long x=4;
  unsigned long long y=4;
  Matrix B(x,y);
  Matrix A(x,y);
  A.setMatrix(2);
  A.print();
  B.setMatrix(8);
  //A = A+B;
  try{
    A = A*B;
  }catch(std::string s){
    std::cout<<s<<std::endl;
  }catch(...){
    std::cout<<"unknown error \n";
  }


  std::cout<<std::endl;
  A.print();
  return 0;
}
