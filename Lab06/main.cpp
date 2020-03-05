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
  std::cout<<std::endl;
  int sum = 0;
  for(int i=0; i<10; i++){
    int cost = hireAlgorithm(canadates, 10);
    shuffle(canadates, 10);
    std::cout<<"10 applicants cost (1-Interview/2-Hire): "<<cost<<std::endl;
    Logger::logln("10 applicants cost (1-Interview/2-Hire): " + std::to_string(cost));
    sum += cost;
  }
  int avg = sum/10;
  Logger::logln("Avg: "+std::to_string(avg));
  std::cout<<"Average: "<<avg<<std::endl;
  delete [] canadates;



  return 0;
}



void shuffle(int* oldArr, int len){
  int rand1;
  int rand2;
  int size = {10};
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

int hireAlgorithm(int* arr, int len){
  int cost;
  int largest=0;//Makes dummy hire
  cost = 2;
  for(int i=1; i<len; i++){
    if(arr[i] > arr[largest]){
      largest = i;//Hire
      cost += 2;
    }
    cost+=1;//Interview cost
  }
  return cost;
}
