#include "Matrix.cpp"
//#include "Logger.h"//File writer
#include <chrono>//chrono



template<class T>
Matrix<T> calculateData(Matrix<T> input, Matrix<T> demand){
  try{
    Matrix<T>Identity = input;
    Identity.init();
    return (Identity - input).Inverse() * demand;
  }catch(std::string s){
   std::cout<<s<<std::endl;
  }catch(...){
   std::cout<<"Unknown error"<<std::endl;
  }
}























int main(){
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


  // //operations
    std::cout<<"(n x 1 * 1 x n): \n";
    Matrix<int>  OneNX(1,5);
    OneNX.setMatrix(2);
    OneNX.print();
    Matrix<int>  x = (nx1 * OneNX);
    x.print();
    std::cout<<"Triangle Matrix * Diagnal 1s: \n";
    (upperTri * init).print();
    std::cout<<"Diangal 1s * Diagnal 0s: \n";
    (init * reinit).print();
    std::cout<<"Diagnal 0s * 2: \n";
    (reinit * 2).print();


    Matrix<double> test(2,2);
    test.setElement(0,0,2);
    test.setElement(0,1,0);
    test.setElement(1,0,0);
    test.setElement(1,1,3);
  	test.print();


    std::cout<<"Testing inverse on 2x2"<<std::endl;
    Matrix<double> testInv = test.Inverse();
  	Matrix<double> Identity = testInv*test;
  	testInv.print();
  	Identity.print();



    Matrix<double> test1(3,3);
    test1.setElement(0,0,8);
    test1.setElement(0,1,1);
    test1.setElement(0,2,3);
    test1.setElement(1,0,4);
    test1.setElement(1,1,5);
    test1.setElement(1,2,3);
    test1.setElement(2,0,1);
    test1.setElement(2,1,2);
    test1.setElement(2,2,7);



  	test1.print();
    testInv = test1.Inverse();
  	Identity = testInv*test1;
  	testInv.print();
  	Identity.print();

    std::cout<<"THIS IS THE PROJECT"<<std::endl;


    test1.setElement(0,0,.6);
    test1.setElement(0,1,.02);
    test1.setElement(0,2,.1);
    test1.setElement(1,0,.3);
    test1.setElement(1,1,.2);
    test1.setElement(1,2,.4);
    test1.setElement(2,0,.2);
    test1.setElement(2,1,.4);
    test1.setElement(2,2,.3);

    Matrix<double> demand(3, 1);
    demand.setElement(0,0,20);
    demand.setElement(1,0,34);
    demand.setElement(2,0,80);

    test1.print();

    // demand.print();

    std::cout<<"Test Inverter"<<std::endl;

    Matrix<double>test1Inv = test1.Inverse();
    (test1 * test1Inv).print();

    std::cout<<"Solve Project"<<std::endl;

    Matrix<double> Ans = calculateData(test1, demand);
    Ans.print();
















    //Desired driver portion
    Matrix<int>test2Inv(2,2);
    test2Inv.setMatrix(2);
    for(int i=2; i<10; i++){
      Matrix<int> Driverlad(i,i);
      Driverlad.setMatrix(i);
      Matrix<int> DriverLad2(i,i);
      DriverLad2.setMatrix(i);
      std::cout<<"Driverlad and DriverLad2: \n";
      Driverlad.print();
      DriverLad2.print();

      //Addition testing
      std::cout<<"Add: \n";
      auto start=std::chrono::system_clock::now();

      (Driverlad + DriverLad2).print();

      auto end=std::chrono::system_clock::now();
      auto elapsed = end - start;
      std::chrono::duration<double> elapsed_seconds = end-start;
      std::time_t end_time = std::chrono::system_clock::to_time_t(end);
      std::cout<<"Finished at: "<<std::ctime(&end_time)<<"elapsed time: "<<elapsed_seconds.count()<<"s \n"<<"Counter: "<<Driverlad.numOfOp;
      Driverlad.numOfOp = 0;
      Driverlad.setMatrix(i);
      DriverLad2.setMatrix(i);
      std::cout<<std::endl;
      std::cout<<std::endl;


      //Subtraction testing
      std::cout<<"Subtract: \n";
      start=std::chrono::system_clock::now();

      (Driverlad - DriverLad2).print();

      end=std::chrono::system_clock::now();
      elapsed = end - start;
      elapsed_seconds = end-start;
      end_time = std::chrono::system_clock::to_time_t(end);
      std::cout<<"Finished at: "<<std::ctime(&end_time)<<"elapsed time: "<<elapsed_seconds.count()<<"s \n"<<"Counter: "<<Driverlad.numOfOp;
      Driverlad.numOfOp = 0;
      Driverlad.setMatrix(i);
      DriverLad2.setMatrix(i);
      std::cout<<std::endl;
      std::cout<<std::endl;


      //Multiply testing
      std::cout<<"Multiply: \n";
      start=std::chrono::system_clock::now();

      (Driverlad * DriverLad2).print();

      end=std::chrono::system_clock::now();
      elapsed = end - start;
      elapsed_seconds = end-start;
      end_time = std::chrono::system_clock::to_time_t(end);
      std::cout<<"Finished at: "<<std::ctime(&end_time)<<"elapsed time: "<<elapsed_seconds.count()<<"s \n"<<"Counter: "<<Driverlad.numOfOp;
      Driverlad.numOfOp = 0;
      Driverlad.setMatrix(i);
      DriverLad2.setMatrix(i);
      std::cout<<std::endl;
      std::cout<<std::endl;


      //Invert testing
      // std::cout<<"Reset DriverLad2:\n";
      // DriverLad2.setRandMatrix();
      // DriverLad2.print();
      // std::cout<<"Invert DriverLad2: \n";
      // start=std::chrono::system_clock::now();
      //
      // test2Inv = DriverLad2.Inverse();
      // (DriverLad2.Inverse()).print();
      //
      // end=std::chrono::system_clock::now();
      // elapsed = end - start;
      // elapsed_seconds = end-start;
      // end_time = std::chrono::system_clock::to_time_t(end);
      // std::cout<<"Finished at: "<<std::ctime(&end_time)<<"elapsed time: "<<elapsed_seconds.count()<<"s\n";
      // Driverlad.setMatrix(i);
      // DriverLad2.setMatrix(i);



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
