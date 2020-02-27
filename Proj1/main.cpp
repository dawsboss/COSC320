#include "Matrix.cpp"

//Does the actual work form the wrapper
int Fib(Matrix<int> A, int n){
  return A.pow(n).getElement(1,1);
}

//Finds the nth fibinacci number
int Fibinacci(int n){
  Matrix<int> A(2,2);
  A.setMatrix(0,0,0);
  A.setMatrix(0,1,1);
  A.setMatrix(1,0,1);
  A.setMatrix(1,1,1);
  return Fib(A, n);
}






int main(){
  // Matrix B(4, 4);
  // Matrix A(4, 4);
  // A.setTriangleMatrix();
  // A.print();
  // B.setMatrix(8);
  // //A = A+B;
  // try{
  //   A = A*B;
  // }catch(std::string s){
  //   std::cout<<s<<std::endl;
  // }catch(...){
  //   std::cout<<"unknown error \n";
  // }





std::cout<<Fibinacci(4)<<std::endl;

try{
  //initilizations
  Matrix<int> nx1(5, 1);
  nx1.setMatrix(2);
  std::cout<<"n x 1: \n";
  nx1.print();
  Matrix<int> upperTri(4, 4);
  upperTri.setTriangleMatrix();
  std::cout<<"Triangle Matrix: \n";
  upperTri.print();
  Matrix<int>  init(4, 4);
  init.init();
  std::cout<<"Diangal 1s: \n";
  init.print();
  Matrix<int>  reinit(4, 4);
  reinit.Reinit();
  std::cout<<"Diagnal 0s: \n";
  reinit.print();


//operations
  std::cout<<"(n x 1 * 1 x n): \n";
  Matrix<int>  OneNX(1,5);
  OneNX.setMatrix(2);
  OneNX.print();
  Matrix<int>  x = (nx1 * OneNX);
  std::cout<<"test\n";
  x.print();
  std::cout<<"Triangle Matrix * Diagnal 1s: \n";
  (upperTri * init).print();
  std::cout<<"Diangal 1s * Diagnal 0s: \n";
  (init * reinit).print();
  std::cout<<"Diagnal 0s * 2: \n";
  (reinit * 2).print();



}catch(std::string s){
  std::cout<<s<<std::endl;
}catch(...){
  std::cout<<"Unknown error"<<std::endl;
}

  std::cout<<std::endl;
  // A.print();
  return 0;
}
