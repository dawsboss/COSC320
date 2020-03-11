#include "Matrix.cpp"
#include <fstream> // file reading

template<class T>
Matrix<T> calculateData(Matrix<T> input, Matrix<T> demand){
  Matrix<T>Identity = input;
  Identity.init();
  return (Identity - input).Inverse() * demand;

}


void increaseArraySize(std::string* arr, int& size){
  std::string temp [size];
  for(int i=0; i < size; i++){
    temp[i] = arr[i];
  }
  delete [] arr;
  arr = new std::string [size*2];
  for(int i=0; i < size; i++){
    arr[i] = temp[i];
  }
  size*=2;
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

int main(int argc, char** argv){
  //Checks to make sure we have only what we need
  if(argc != 2){
    std::cout<<"Wrong arguments with comand ./main please use ./main *Filename.type*! \n";
    return 69;
  }
  //Makes obj to read with
  std::ifstream readIn;
  //Makes sure we open all good
  try{
    readIn.open(argv[1]);
    if(!readIn.is_open()){
      std::cout<<"File couldn't open/doesn't exist! \n";
      return 420;
    }
  }catch (std::ios_base::failure& e) {
    std::cerr << e.what() << '\n';
  }catch(...){
    //errors out if we have nothing to open
    std::cout<<"File couldn't open/doesn't exist! \n";
    return 420;
  }
  
    int CompanyCounter=0;
    std::string* Companies = new std::string[75];
    int numComp = 75;
    //Doing the calculations here for everything;
  while(!readIn.eof()){//Reads in all companies
    for(int i=0; readIn.peek() != '-'; i++){
      if(i >= numComp){
	increaseArraySize(Companies, numComp);
      }
      std::getline(readIn, Companies[i]);
      CompanyCounter++;
    }
    
    readIn.ignore(5,'\n');//Makes sure we get to the Matrix of numbers saftly
    
    
    Matrix<double> givenMatrix(CompanyCounter, CompanyCounter);
    double holder;
    
    for(int i=0; i<CompanyCounter; i++){
      for(int j=0; j<CompanyCounter; j++){
	readIn >> holder;//Reads in from file
	givenMatrix.setElement(i,j,holder);//Wrotes the read data to the matrix class
      }
    }
    
    readIn.ignore(5,'\n');//Get out of matrix 
    readIn.ignore(5,'\n');//Makes sure we get to the Matrix of numbers saftly
    
    Matrix<double> demand(CompanyCounter, 1);
    
    for(int i=0; i<CompanyCounter; i++){
      readIn >> holder;
      demand.setElement(i, 0, holder);
    }
    
    Matrix<double> result = calculateData(givenMatrix, demand);
    
    std::cout<<"-------------------------------\n";
    std::cout<<"Reseults: \n";
    
    for(int i=0; i<CompanyCounter; i++){
      std::cout<<Companies[i]<<" ";
    }
    std::cout<<std::endl;
    for(int i=0; i<CompanyCounter; i++){
      std::cout<<result.getElement(i,0)<<" ";
      std::cout<<std::endl;
    }
    std::cout<<"-------------------------------\n";
    
    readIn.ignore(5,'\n');//Get out of demand
    readIn.ignore(5,'\n');//Makes sure we get to the Matrix of numbers saftly
    
    
    CompanyCounter=0;
  }
  
  delete [] Companies;
  readIn.close();
  return 0;
  
  
  
  
  




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

}catch(std::string s){
  std::cout<<s<<std::endl;
}catch(...){
  std::cout<<"Unknown error"<<std::endl;
}

  std::cout<<std::endl;
  // A.print();
  return 0;
}
