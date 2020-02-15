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





template <class DataType>
struct Heap {
  DataType* arr; // the underlying array
  int length; // should always be the size of arr
  int heap_size; // will change based on which portion of arr is a valid heap
  // give the struct an [] operator to pass through access to arr
  // we return an int reference so we can assign into the structure,
  // otherwise it would only return a copy of the indexed element
  Heap(int len, DataType* a){
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

  DataType& operator[](int i){
    // good idea to also check that 1 <= i <= length!
    if(i<=0 || i>length){
      return arr[0];
    }
    return arr[i-1]; // so A[1] is the first and A[n] is the last
  }
};










template <class DataType>
void swap(DataType& x, DataType& y){
  int temp=x;
  x=y;
  y=temp;
}


int SwapCounter=0;

//Random: makes and populates an array of a given size with random integers between 1-100
template <class DataType>
DataType* makeRandomArray(int len){
	DataType* rtn=new DataType[len];
	for(int i=0;i<len;i++){
		 rtn[i]=1+rand()%100;//1-100
	}
	return rtn;
}

//Accending: makes and populates an array of a given size in a accending order
template <class DataType>
DataType* makeAccendingArray(int len){
	DataType* rtn=new DataType[len];
	for(int i=0;i<len;i++){
		rtn[i]=i;
	}
	return rtn;
}

//Decending: makes and populates an array of a given size in a deccending order
template <class DataType>
DataType* makeDecendingArray(int len){
	DataType* rtn=new DataType[len];
	int j=0;
	for(int i=len-1;i>=0;i--){
		rtn[i]=j;
		j++;
	}
	return rtn;
}

//isSorted: checks to make sure that the array is sorrted
template <class DataType>
bool isSorted(Heap<DataType>* A){
	for(int i=1;i<A->length;i++){
		if((*A)[i-1]>(*A)[i]){
			return false;
		}
	}
	return true;
}

template <class DataType>
void printArray(Heap<DataType>* A){
	for(int i=1;i<A->length;i++){
		std::cout<<(*A)[i]<<" ";
	}
	std::cout<<std::endl;
}

















template <class DataType>
void MaxHeapify(Heap<DataType>* A, int i){
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
    swap<DataType>((*A)[i], (*A)[Largest]);
    SwapCounter;
    MaxHeapify(A,Largest);
  }
}

template <class DataType>
void BuildMaxHeap(Heap<DataType>* A){
  A->heap_size = A->length;
  for(int i=(A->length)/2; i>=1; i--){
    MaxHeapify(A,i);
  }
}

template <class DataType>
void HeapSort(Heap<DataType>* A){
  BuildMaxHeap(A);
  for(int i = A->length ; i > 0; i--){
    //We know A[i] is the largest among A[1,...,i], so move it
    //to the back, and consider it removed from heap
    swap<DataType>((*A)[1], (*A)[i]);
    SwapCounter;
    A->heap_size--;
    //We moved one of the smaller elements to the root so we have to clean up
    MaxHeapify(A,1);
  }
}


template <class DataType>
void printHeap(Heap<DataType>* A){
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
template <class DataType>
void timeSort(void (*sort)(Heap<DataType>*), Heap<DataType>* A){
  //The "auto" type determines the corret type at compile-time
  auto start=std::chrono::system_clock::now();

  sort(A);

	if(!isSorted(A)){
		Logger::log("Did not Sort!----------------------------------------------------- Error: Oof");
		std::cout<<"You are big dumb and it ain't no sorted"<<std::endl;
		return;
	}

  auto end=std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
  std::cout<<"Finished at: "<<std::ctime(&end_time)<<"elapsed time: "<<elapsed_seconds.count()<<"s\n";
	Logger::logln("elapsed time(s): " + std::to_string(elapsed_seconds.count()));
}








int main(){
  Logger::init("Bruh");
  //
  //
  // int* arr = makeRandomArray(100);
  //
  // Heap<double>* tester = new Heap<double>(100, arr);
  // printArray(tester);
  // timeSort(HeapSort, tester);
  // printArray(tester);

  // delete [] arr;

















  //Creates where our data will go from the tests
	// Logger::init("test");





	srand(time(NULL));
	//all the sizes I am doing
	int size[] = {10, 100, 500, 1000, 2500, 5000, 7500, 10000, 25000, 50000};
	//Number of sizes
	int sizes = 10;
	//array that we will be editing
	double* array = new double[1];
  Heap<double>* tester = new Heap<double>(100, array);
	// //This is used for using the logger and saying what function we are working with
	// std::string sorters[] = {HeapSort};
  // typedef void (*fn) (int*,int, int);
	// static fn Sorters[] = {MergeSort, QuickSort};
//for loop 1 - goes through all array sizes (size[10])
//for loop 2 - goes through all types of sorting types we have (Merge, Quick)
//for loop 3 - goes through all types of arrays to be sorted (Random, Accending, Decending)
  for(int i=0; i<sizes; i++){
    for(int FuncI=0;FuncI<1;FuncI++){
      for(int j=0;j<3;j++){
				SwapCounter=0;
        switch(j){
           case(0):
					 		std::cout<<"Heap : Random:";
							Logger::logln("Heap : Random : # of elements: " + std::to_string(size[i]));
							delete tester;
             	array=makeRandomArray<double>(size[i]);
              tester = new Heap<double>(size[i], array);
            	break;
          case(1):
							std::cout<<"Heap : Accending:";
							Logger::logln("Heap : Accending ");
							delete tester;
							array=makeAccendingArray<double>(size[i]);
              tester = new Heap<double>(size[i], array);
            	break;
          case(2):
							std::cout<<"Heap : Deccending:";
							Logger::logln("Heap : Decending ");
							delete tester;
            	array=makeDecendingArray<double>(size[i]);
              tester = new Heap<double>(size[i], array);
            	break;
           }
					 //printing results and tetsting the sorters
					 std::cout<<" Number of elements: "<<size[i]<<std::endl;
					 timeSort(HeapSort, tester);

           std::cout<<"Swaps: "<<SwapCounter<<std::endl;
           Logger::logln(" Swaps: " + std::to_string(SwapCounter));
      }
    }
  }
	Logger::ln();
	Logger::log("End");





  delete tester;
  Logger::close();
  return 0;
}
