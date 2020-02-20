//Grant Dawson COSC 320
#include <iostream>
#include <chrono>//chrono
#include <stdlib.h>//rand
#include <time.h>//time
#include <fstream>//File Writer
#include <sstream> // for to_string
#include "Logger.h"//Logs into files
#include <math.h> //log2()









//heap structure that hokds all data about and the heap it's slef
struct Heap {
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


void MaxHeapify(Heap* A, int i);
void BuildMaxHeap(Heap* A);
void printHeap(Heap* A, int i, int d);
void HeapSort(Heap* A);
void printHeapV2(Heap* A, int i, int d);









//takes two adresses and switches their data
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
		rtn[i]=i+1;
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
//prints array nothing special
void printArray(Heap* A){
	for(int i=1;i<A->length;i++){
		std::cout<<(*A)[i]<<" ";
	}
	std::cout<<std::endl;
}

















//makes sure the parrent of children are the biggest
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
    SwapCounter++;
    MaxHeapify(A,Largest);
  }
}
//Makes a maxHeap for the heapsorter to use
void BuildMaxHeap(Heap* A){
  A->heap_size = A->length;
  for(int i=(A->length)/2; i>=1; i--){
    MaxHeapify(A,i);
  }
  // printHeap(A, 1, log2(A->length));
  // std::cout<<std::endl;
  // printHeapV2(A, 3, log2(A->length));
}
//Takes a max heap and sorts it into a accending array
void HeapSort(Heap* A){
  BuildMaxHeap(A);
  for(int i = A->length ; i > 0; i--){
    //We know A[i] is the largest among A[1,...,i], so move it
    //to the back, and consider it removed from heap
    swap((*A)[1], (*A)[i]);
    SwapCounter++;
    A->heap_size--;
    //We moved one of the smaller elements to the root so we have to clean up
    MaxHeapify(A,1);
  }
}


//prints heap from a given i-index, d-depth
void printHeap(Heap* A, int i, int d){
  int startNode = i;
  for(int w=log2(i); w < log2(i)+d+1; w++){
    for(int j=startNode; j < (startNode + exp2(w + log2(i)))/(i); j++){
        if(j <= A->length){
          std::cout<<(*A)[j]<<" ";
        }else{
          std::cout<<"* ";
        }
    }
      startNode*=2;
    std::cout<<std::endl;
  }
}

//Much better logic version of the one above
void printHeapV2(Heap* A, int i, int d){
  int startNode = i;
  for(int w=0; w<d; w++){
    for(int j=startNode; j < (startNode + exp2(w)); j++){
      if(j <= A->length){
        std::cout<<(*A)[j]<<" ";
      }else{
        std::cout<<"* ";
      }
    }
    std::cout<<std::endl;
    startNode*=2;
  }
}









//Takes a sorting algorithm calls it and prints it's meta data
void timeSort(void (*sort)(Heap*), Heap* A){
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
  Logger::init("Results");

  //
  // int* arr = makeRandomArray(10);
  // Heap* tester = new Heap(10, arr);
  // printArray(tester);
  // timeSort(HeapSort, tester);
  // printArray(tester);





    srand(time(NULL));
  	//all the sizes I am doing
  	int size[] = {10, 100, 500, 1000, 2500, 5000, 7500, 10000, 25000, 50000, 75000, 100000, 250000, 500000, 750000, 1000000};
  	//Number of sizes
  	int sizes = 16;
  	//array that we will be editing
  	int* array = new int[1];
    Heap* tester = new Heap(100, array);
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
  							Logger::logln("------------------------  Heap : Random : Size: " + std::to_string(size[i]) + "  ------------------------");
  							delete tester;
               	array=makeRandomArray(size[i]);
                tester = new Heap(size[i], array);
              	break;
            case(1):
  							std::cout<<"Heap : Accending:";
  							Logger::logln("Heap : Accending ");
  							delete tester;
  							array=makeAccendingArray(size[i]);
                tester = new Heap(size[i], array);
              	break;
            case(2):
  							std::cout<<"Heap : Deccending:";
  							Logger::logln("Heap : Decending ");
  							delete tester;
              	array=makeDecendingArray(size[i]);
                tester = new Heap(size[i], array);
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
  	Logger::logln("End");








  delete tester;
  Logger::close();
  return 0;
}
