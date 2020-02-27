#include "Matrix.h"
#include <chrono>//chrono
#include "Logger.h"

//Does the actual work form the wrapper
int Fib(Matrix A, int n){
  return A.pow(n).getElement(1,0);
}

//Finds the nth fibinacci number
int Fibinacci(int n){
  Matrix A(2,2);
  A.setMatrix(0,0,0);
  A.setMatrix(0,1,1);
  A.setMatrix(1,0,1);
  A.setMatrix(1,1,1);
  return Fib(A, n);
}

//Times the * funtions of two matricies
Matrix timeMulti(Matrix A, Matrix B){
  Matrix rtn;
  //The "auto" type determines the corret type at compile-time
  auto start=std::chrono::system_clock::now();

    rtn = A*B;


  auto end=std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
  std::cout<<"Finished at: "<<std::ctime(&end_time)<<"elapsed time: "<<elapsed_seconds.count()<<"s\n";
  Logger::logln("elapsed time(s): " + std::to_string(elapsed_seconds.count()));
  return rtn;
}

//Times the + funtions of two matricies
Matrix timeAdd(Matrix A, Matrix B){
  Matrix rtn;
  //The "auto" type determines the corret type at compile-time
  auto start=std::chrono::system_clock::now();

    rtn = A+B;


  auto end=std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
  std::cout<<"Finished at: "<<std::ctime(&end_time)<<"elapsed time: "<<elapsed_seconds.count()<<"s\n";
  Logger::logln("elapsed time(s): " + std::to_string(elapsed_seconds.count()));
  return rtn;
}

//Times the - funtions of two matricies
Matrix timeSub(Matrix A, Matrix B){
  Matrix rtn;
  //The "auto" type determines the corret type at compile-time
  auto start=std::chrono::system_clock::now();

    rtn = A-B;


  auto end=std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
  std::cout<<"Finished at: "<<std::ctime(&end_time)<<"elapsed time: "<<elapsed_seconds.count()<<"s\n";
  Logger::logln("elapsed time(s): " + std::to_string(elapsed_seconds.count()));
  return rtn;
}












int main(){
  Logger::init("Result");

std::cout<<Fibinacci(6)<<std::endl;
std::cout<<std::endl;


try{
  //initilizations
  Matrix nx1(5, 1);
  nx1.setMatrix(2);
  std::cout<<"n x 1: \n";
  nx1.print();
  Matrix upperTri(4, 4);
  upperTri.setTriangleMatrix();
  std::cout<<"Triangle Matrix: \n";
  upperTri.print();
  Matrix init(4, 4);
  init.init();
  std::cout<<"Diangal 1s: \n";
  init.print();
  Matrix reinit(4, 4);
  reinit.Reinit();
  std::cout<<"Diagnal 0s: \n";
  reinit.print();


//operations
  std::cout<<"(n x 1 * 1 x n): \n";
  Matrix OneNX(1,5);
  OneNX.setMatrix(2);
  OneNX.print();
  Matrix x = (nx1 * OneNX);
  std::cout<<"test\n";
  x.print();
  std::cout<<"Triangle Matrix * Diagnal 1s: \n";
  (upperTri * init).print();
  std::cout<<"Diangal 1s * Diagnal 0s: \n";
  (init * reinit).print();
  std::cout<<"Diagnal 0s * 2: \n";
  (reinit * 2).print();





  int nSizes[] = {10,100,500,1000,1500,2000};
  int nSize = 6;
  Logger::logln("Multiply");
  std::cout<<"Multiply"<<std::endl;
  for(int i=0; i<nSize; i++){
    Matrix tester(nSizes[i], nSizes[i]);
    Matrix tester2(nSizes[i], nSizes[i]);
    tester2 = timeMulti(tester, tester2);
  }
  std::cout<<"Add"<<std::endl;
   Logger::logln("Add");
    for(int i=0; i<nSize; i++){
    Matrix tester(nSizes[i], nSizes[i]);
    Matrix tester2(nSizes[i], nSizes[i]);
    tester2 = timeAdd(tester, tester2);
  }
  std::cout<<"Subtract"<<std::endl;
   Logger::logln("Subtract");
    for(int i=0; i<nSize; i++){
    Matrix tester(nSizes[i], nSizes[i]);
    Matrix tester2(nSizes[i], nSizes[i]);
    tester2 = timeSub(tester, tester2);
  }







}catch(std::string s){
  std::cout<<s<<std::endl;
}catch(...){
  std::cout<<"Unknown error"<<std::endl;
}

  std::cout<<std::endl;
  // A.print();
  return 0;
}
