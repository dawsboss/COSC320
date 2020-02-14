//Grant Dawson COSC 320
#include <iostream>
#include <chrono>//chrono
#include <stdlib.h>//rand
#include <time.h>//time
#include <fstream>//File Writer
#include <sstream> // for to_string
#include "Logger.h"//Logs into files


void MaxHeapify();
void BuildMaxHeap();
void HeapSort();





template <datatype T>
struct<T> Heap {
  int* arr; // the underlying array
  int length; // should always be the size of arr
  int heap_size; // will change based on which portion of arr is a valid heap
  // give the struct an [] operator to pass through access to arr
  // we return an int reference so we can assign into the structure,
  // otherwise it would only return a copy of the indexed element
  Heap(int len, int* a){
    arr = a;
    length = len;
    heap_size = 0;
  }

  ~Heap(){
    delete [] arr;
  }

  int left(int i){
    return 2*i;
  }
  int right(int i){
    return 2*i+1;
  }

  int& operator[](int i){
    // good idea to also check that 1 <= i <= length!
    if(i<=0 || i>length){
      return arr[0];
    }
    return arr[i-1]; // so A[1] is the first and A[n] is the last
  }
};











void swap(int& x, int& y){
  int temp=x;
  x=y;
  y=temp;
}


int SwapCounter=0;

//Random: makes and populates an array of a given size with random integers between 1-100
int* makeRandomArray(int len){
	int* rtn=new int[len];
	for(int i=0;i<len;i++){
		 rtn[i]=1+rand()%100;//1-100
	}
	return rtn;
}

//Accending: makes and populates an array of a given size in a accending order
int* makeAccendingArray(int len){
	int* rtn=new int[len];
	for(int i=0;i<len;i++){
		rtn[i]=i;
    std::cout<<rtn[i]<<" ";
	}
  std::cout<<std::endl;
	return rtn;
}

//Decending: makes and populates an array of a given size in a deccending order
int* makeDecendingArray(int len){
	int* rtn=new int[len];
	int j=0;
	for(int i=len-1;i>=0;i--){
		rtn[i]=j;
		j++;
	}
	return rtn;
}

//isSorted: checks to make sure that the array is sorrted
bool isSorted(Heap* A){
	for(int i=1;i<A->length;i++){
		if((*A)[i-1]>(*A)[i]){
			return false;
		}
	}
	return true;
}

void printArray(Heap* A){
	for(int i=1;i<A->length;i++){
		std::cout<<(*A)[i]<<" ";
	}
	std::cout<<std::endl;
}


















void MaxHeapify(Heap* A, int i){
  int l = A->left(i);
  int r = A->right(i);
  //Find the largest among node i and its children, and swap with i
  int Largest;
  if(l <= A->heap_size && (*A)[l] > (*A)[i]){
    Largest = l;
  }else{
    Largest = i;
  }
  if(r <= A->heap_size && (*A)[r] > (*A)[Largest]){
    Largest = r;
  }
  if(Largest != i){
    //We may have violated the heap propertis, so recurse downward
    swap((*A)[i], (*A)[Largest]);
    MaxHeapify(A,Largest);
    printArray(A);
  }
}

void BuildMaxHeap(Heap* A){
  A->heap_size = A->length;
  for(int i=(A->length)/2; i>=1; i--){
    MaxHeapify(A,i);
  }
}

void HeapSort(Heap* A){
  BuildMaxHeap(A);
  for(int i = A->length ; i > 0; i--){
    //We know A[i] is the largest among A[1,...,i], so move it
    //to the back, and consider it removed from heap
    swap((*A)[1], (*A)[i]);
    A->heap_size--;
    //We moved one of the smaller elements to the root so we have to clean up
    MaxHeapify(A,1);
  }
}



void printHeap(Heap* A){
  for(int i=0; i<A->length; i++){
    for(int j=0;j<10;j++){


      if(double(i/(j*j)) == 0){
        std::cout<<std::endl;
      }
    }
    std::cout<<" "<<(*A)[i]<<" ";
  }
}










//Takes a sorting algorithm calls it and prints it's meta data
void timeSort(void (*sort)(Heap*), Heap* A){
  //The "auto" type determines the corret type at compile-time
  auto start=std::chrono::system_clock::now();

  sort(A);

	// if(!isSorted(A)){
	// 	Logger::log("Did not Sort!----------------------------------------------------- Error: Oof");
	// 	std::cout<<"You are big dumb and it ain't no sorted"<<std::endl;
	// 	return;
	// }

  auto end=std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
  std::cout<<"Finished at: "<<std::ctime(&end_time)<<"elapsed time: "<<elapsed_seconds.count()<<"s\n";
	Logger::log("elapsed time(s): " + std::to_string(elapsed_seconds.count()));
}









int main(){
  Logger::init("Bruh");


  int* arr = makeRandomArray(10);
  Heap* tester = new Heap(10, arr);
  printArray(tester);
  timeSort(HeapSort, tester);
  printArray(tester);


  Logger::close();
  return 0;
}
