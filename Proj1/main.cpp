#include "Matrix.cpp"
#include <fstream> // file reading

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
    std::cout<<"Results: Amount of each product needed:\n";

    //for(int i=0; i<CompanyCounter; i++){
     // std::cout<<Companies[i]<<" ";
    //}
    std::cout<<std::endl;
    for(int i=0; i<CompanyCounter; i++){
      std::cout<<Companies[i]<<": "<<result.getElement(i,0)<<" ";
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
}
