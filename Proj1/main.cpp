#include "Matrix.cpp"

template<class T>
Matrix<T> calculateData(Matrix<T> input, Matrix<T> demand){
  Matrix<T>Identity = input;
  Identity.init();
  return (Identity - input).Inverse() * demand;

}

// int main(int argc, char** arg){
//   //Makes sure we get one file
//   if(argc<1){
//     cout<<"Incorrect arguments : ./main \"FileName\"\n\t FileName - This is the file you want to program to read from"<<endl;
//     return 69;
//   }
//   //Catch if the file open fails
//   if(argc<2||atoi(arg[1])>10||atoi(arg[1])<2){
//     cout<<"Incorrect arguments : ./main n\n\t n - Height of the first stack(2-10)"<<endl;
//     return 1;
//   }

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
  std::cout<<"test\n";
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
  Matrix<double> testInv = test.Inverse();
	Matrix<double> Identity = testInv*test;
	testInv.print();
	Identity.print();



  Matrix<double> test1(3,3);
  test1.setElement(0,0,14);
  test1.setElement(0,1,7);
  test1.setElement(0,2,4);
  test1.setElement(1,0,7);
  test1.setElement(1,1,10);
  test1.setElement(1,2,1);
  test1.setElement(2,0,4);
  test1.setElement(2,1,1);
  test1.setElement(2,2,2);



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

}catch(std::string s){
  std::cout<<s<<std::endl;
}catch(...){
  std::cout<<"Unknown error"<<std::endl;
}

  std::cout<<std::endl;
  // A.print();
  return 0;
}
