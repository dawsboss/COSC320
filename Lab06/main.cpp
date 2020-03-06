#include <iostream>//pritning
#include "HeapQ.h"//Not needed but used later for shuffle
#include "Logger.h"

void shuffle(int*, int);
void swap(int&, int&);
int* makeCanadates(int);
int hireAlgorithm(int*, int);


int main(){
  Logger::init("Bruh");
  int* canadates = makeCanadates(10);
  shuffle(canadates, 10);
  std::cout<<"test \n";
  for(int i=0; i<10;i++){
    std::cout<<canadates[i]<<" ";
  }




  int sizes[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 150, 200, 250, 300, 350, 400, 450, 500};
  int size = 18;
  std::cout<<std::endl;
  int sum = 0;
  for(int j=0; j<size; j++){
    for(int i=0; i<sizes[j]; i++){
      int cost = hireAlgorithm(canadates, 10);
      shuffle(canadates, 10);
      //std::cout<<"10 applicants # of hires: "<<cost<<std::endl;
      //Logger::logln("10 applicants # of hires: " + std::to_string(cost));
      sum += cost;
    }
    int avg = sum/sizes[j];
    Logger::logln("Avg "+std::to_string(sizes[j])+" # of emplyees: "+std::to_string(avg));
    std::cout<<"Average "<<sizes[j]<<": "<<avg<<" # of hires"<<std::endl;
  }
  
  
  
  
  
  
  
  
  delete [] canadates;



  return 0;
}



void shuffle(int* oldArr, int len){
  int rand1;
  int rand2; 
  for(int i = 0; i<(len*len)*len; i++){
    rand2 = (int)rand() % len;
    rand1 = (int)rand() % len;
    swap(oldArr[rand1], oldArr[rand2]);
  }
}

void swap(int& x, int& y){
  int temp=x;
  x=y;
  y=temp;
}

int* makeCanadates(int len){
  int* rtn = new int[len];
  for(int i=0; i<len; i++){
    rtn[i]=i+1;
  }
  return rtn;
}

//Runs our hiring algorthim but counts how many hires there were for the given array
int hireAlgorithm(int* arr, int len){
  int cost;
  int largest=0;//Makes dummy hire
  cost = 2;
  for(int i=1; i<len; i++){
    if(arr[i] > arr[largest]){
      largest = i;//Hire
      cost += 1;
    }
   // cost+=1;//Interview cost
  }
  return cost;
}
