//Grant Dawson COSC 320
#include <iostream>
#include <chrono>//chrono
#include <stdlib.h>//rand
#include <time.h>//time
#include <fstream>//File Writer
#include <sstream> // gay
#include "Logger"//Logs into files


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
	}
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
bool isSorted(int* arr, int e){
	for(int i=1;i<e-1;i++){
		if(arr[i-1]>arr[i]){
			return false;
		}
	}
	return true;
}

//swap: takes two indexes and swaps there places
void swap(int &s1, int &s2){
	int temp = s1;
	s1=s2;
	s2=temp;
	SwapCounter++;
}

//Merge: takes two given arrays and puts them together sorted
void Merge(int* arr, int s1, int s2, int e1, int e2){
  int i=s1,j=s2,k=0;
  int rtn [(e1-s1)+(e2-s2)];
  while(i<(e1) && j<(e2)){
		SwapCounter++;
		SwapCounter++;
    if(arr[i]<arr[j]){
			SwapCounter++;
      rtn[k++]=arr[i++];
    }else{
			rtn[k++]=arr[j++];
		}
  }
	while(i<(e1)){
		SwapCounter++;
    rtn[k++]=arr[i++];
	}
	while(j<(e2)){
		SwapCounter++;
    rtn[k++]=arr[j++];
	}
  for(int w=0;w<((e1-s1)+(e2-s2)); w++){
		SwapCounter++;
    arr[w+s1]=rtn[w];
  }
}

void pritnArray(int A[], int s, int e){
	for(int i=s;i<e;i++){
		std::cout<<A[i]<<" ";
	}
	std::cout<<std::endl;
}

//MergeSort: Takes an array and cuts it in "half" until there are only 2 or 1 elements left and then calls a merge fuction to re-merge them in a sorted manner
void MergeSort(int A[], int start, int end){
	int n = end-start;
	if(start < end-1){
		SwapCounter++;
		int mid = (end+start)/2;
		MergeSort(A,start,mid);
		MergeSort(A, mid, end);
    Merge(A, start, mid, mid, end);
	}
}









// int* MergeSort(int* A, int start, int end){
//   int n = end-start;
//   if(n>1){
//     int mid = n/2;
//     int* A1 = MergeSort(A, start, mid);
//     for(int i=0;i<mid;i++){
//       std::cout<<A1[i]<<"A1 "<<mid<<std::endl;
//     }
//     int* A2 = MergeSort(A, mid-1, end);
//     for(int i=0;i<end;i++){
//       std::cout<<A2[i]<<"A2"<<std::endl;
//     }
//     A = Merge(A1, mid, A2, n-mid);
//   }
//   return A;
// }



//Partition: it cuts an array based on a piviot point. whwere it takes a piviot and then moves it to its co0rrect spot in the everything right it greater
//and everything to left is less (in my case) or equal
int Partition(int* A, int start, int end){
  int piviot = A[end-1];
  int loc = start-1;
  for(int i=start; i<end-1; i++){
    if(A[i]<=piviot){
      swap(A[++loc],A[i]);
    }
  }
  swap(A[loc+1],A[end-1]);
  return loc+1;
}



//QuickSort: Calls partiotion and then takes the two haves and continues to call partition until there are no more elemts.
void QuickSort(int A[], int start, int end){
    if(start<end){
      int p = Partition(A,start,end);
      QuickSort(A,start,p);
      QuickSort(A,p+1,end);
    }
}


//Takes a sorting algorithm calls it and prints it's meta data
void timeSort(void (*sort)(int[], int, int), int* arr, int e){
  //The "auto" type determines the corret type at compile-time
  auto start=std::chrono::system_clock::now();

  sort(arr,0,e);

	if(!isSorted(arr, e)){
		Logger::log("Did not Sort!----------------------------------------------------- Error: Oof");
		std::cout<<"You are big dumb and it ain't no sorted"<<std::endl;
		return;
	}

  auto end=std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
  std::cout<<"Finished at: "<<std::ctime(&end_time)<<"elapsed time: "<<elapsed_seconds.count()<<"s\n";
	Logger::log("elapsed time(s): " + std::to_string(elapsed_seconds.count()));
}


int main(){
	//Creates where our data will go from the tests
	Logger::init("test");


	srand(time(NULL));
	//all the sizes I am doing
	int size[] = {10, 100, 500, 1000, 2500, 5000, 7500, 10000, 25000, 50000};
	//Number of sizes
	int sizes = 10;
	//array that we will be editing
	int* array = new int[1];
	//This is used for using the logger and saying what function we are working with
	std::string sorters[] = {"MergeSort", "QuickSort"};
  typedef void (*fn) (int*,int, int);
	static fn Sorters[] = {MergeSort, QuickSort};
//for loop 1 - goes through all array sizes (size[10])
//for loop 2 - goes through all types of sorting types we have (Merge, Quick)
//for loop 3 - goes through all types of arrays to be sorted (Random, Accending, Decending)
  for(int i=0; i<sizes; i++){
    for(int FuncI=0;FuncI<2;FuncI++){
      for(int j=0;j<3;j++){
				SwapCounter=0;
        switch(j){
           case(0):
					 		std::cout<<sorters[FuncI]<<" : Random:";
							Logger::log(sorters[FuncI] + " : Random : # of elements: " + sorters[FuncI]);
							delete [] array;
             	array=makeRandomArray(size[i]);
            	break;
          case(1):
							std::cout<<sorters[FuncI]<<" : Accending:";
							Logger::log(sorters[FuncI] + " : Accending ");
							delete [] array;
							array=makeAccendingArray(size[i]);
            	break;
          case(2):
							std::cout<<sorters[FuncI]<<" : Deccending:";
							Logger::log(sorters[FuncI] + " : Decending ");
							delete [] array;
            	array=makeDecendingArray(size[i]);
            	break;
           }
					 //printing results and tetsting the sorters
					 std::cout<<" Number of elements: "<<size[i]<<std::endl;
					 timeSort(Sorters[FuncI], array, size[i]);
					 if(FuncI==1){
						 std::cout<<"Swaps: "<<SwapCounter<<std::endl;
						 Logger::log(" Swaps: " + std::to_string(SwapCounter));
					 }else if(FuncI==0){
						 std::cout<<"Comparisions: "<<SwapCounter<<std::endl;
						 Logger::log(" Comparisions: " + std::to_string(SwapCounter));
					 }
      }
    }
  }
	Logger::log(" ");
	Logger::log("End");
  delete [] array;
	return 0;
}
