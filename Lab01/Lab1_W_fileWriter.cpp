#include <iostream>
#include <chrono>//chrono
#include <stdlib.h>//rand
#include <time.h>//time
#include <fstream>//File Writer
#include "../../Logger/Logger"//Logger

int SwapCounter=0;

//Random: makes and populates an array of a given size with random integers between 1-100
int* makeRandomArray(int len){
	int* rtn = new int[len];
	for(int i=0;i<len;i++){
		 rtn[i]=1+rand()%100;//1-100
	}
	return rtn;
}

//Accending: makes and populates an array of a given size in a accending order
int* makeAccendingArray(int len){
	int* rtn = new int[len];
	for(int i=0;i<len;i++){
		rtn[i]=i;
	}
	return rtn;
}

//Decending: makes and populates an array of a given size in a deccending order
int* makeDecendingArray(int len){
	int* rtn = new int[len];
	int j=0;
	for(int i=len-1;i>=0;i--){
		rtn[i]=j;
		j++;
	}
	return rtn;
}

//isSorted: checks to make sure that the array is sorrted
bool isSorted(int* arr, int len){
	for(int i=1;i<len;i++){
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
}


//Bubble Sort:  swap adjacent out-of-order elements until no swaps need to be made
void BubbleSort(int* arr, int len){
  Logger::log("Ree?");
  std::ofstream myfile;
	myfile.open ("Results.txt");
	myfile << "BubbleSort: \n";

	std::cout<<"BubbleSort:"<<std::endl;
	//Bad version
  /*for(int i=0;i<len;i++){
		for(int j=0;j<len;j++){
			if(arr[i]>arr[i+1]){
				swap(arr[i],arr[i+1]);
			}
		}
	}*/
	//good version
	bool swapped=true;
	//while somehting is wrong
	while(swapped){
		swapped=false;
		for(int i=0; i<len-1; i++){
			if(arr[i]>arr[i+1]){
				swap(arr[i],arr[i+1]);
				swapped = true;
        SwapCounter++;
			}
		}
	}
		myfile.close();
}

//TODO:nsertion Sort:  take the “next” element and “insert” it into the proper place in the current prefixby swapping left with larger elements
void InsertionSort(int* arr, int len){
	std::ofstream myfile;
	myfile.open ("Results.txt");
	myfile << "InsertionSort: \n";

	std::cout<<"InsertionSort:"<<std::endl;
	int j;
  for(int i=1; i<len;i++){
    j=i;
    while(j>0 && (arr[j]<arr[j-1])){
      swap(arr[j],arr[j-1]);
			SwapCounter++;
			j=j-1;
    }
  }
		myfile.close();
}

//Selection Sort: find the smallest element of the current suffix and move it to the end of the currentprefix.
void SelectionSort(int* arr, int len){
	std::ofstream myfile;
	myfile.open ("Results.txt");
	myfile << "SelectionSort: \n";

	std::cout<<"SelectionSort:"<<std::endl;
	int* min;
  for(int i=0;i<len;i++){
    min = arr+i;
    for(int j=i;j<len;j++){
      if(arr[j]<*min){
        min = arr+j;
      }
    }
    swap(*min,arr[i]);
    SwapCounter++;
  }
	myfile.close();
}


/*
ofstream myfile;
myfile.open ("Results.txt");
myfile << "Writing this to a file.\n";
myfile.close();*/




void timeSort(void (*sort)(int*, int), int* arr, int len){
  //The "auto" type determines the corret type at compile-time
  auto start=std::chrono::system_clock::now();

  sort(arr,len);

  auto end=std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
  std::cout<<"Finished at: "<<std::ctime(&end_time)<<"elapsed time: "<<elapsed_seconds.count()<<"s\n";
}


int main(){
  Logger::init("bruh");
  Logger::log("Bruh");
  Logger::close();
  
  std::ofstream myfile;
	myfile.open ("Results.txt");

	srand(time(NULL));
	int size[] = {10, 100, 500, 1000, 2500, 5000, 7500, 10000, 25000, 50000};
	int sizes = 1;
	int* array;
  typedef void (*fn) (int*, int);
	static fn Sorters[] = {BubbleSort, SelectionSort, InsertionSort};



  for(int i=0; i<sizes; i++){
    for(int FuncI=0;FuncI<3;FuncI++){
      for(int j=0;j<3;j++){
        switch(j){
           case(0):
					 		std::cout<<"Random:"<<std::endl;
							myfile << "Random:\n";
             	array=makeRandomArray(size[i]);
            	break;
          case(1):
							myfile << "Accending:\n";
							std::cout<<"Accending:"<<std::endl;
							array=makeAccendingArray(size[i]);
            	break;
          case(2):
							myfile << "Deccending: \n";
							std::cout<<"Deccending:"<<std::endl;
            	array=makeDecendingArray(size[i]);
            	break;


           }
					 timeSort(Sorters[FuncI], array, size[i]);
					 myfile << "Swaps: "<<SwapCounter<<"\n";
					 myfile.close();
					 std::cout<<"Swaps: "<<SwapCounter<<std::endl;
					 SwapCounter=0;
					 for(int w=0;w<size[i];w++){
						std::cout<<array[w]<<" "<<std::endl;
        	 }
      }
    }
  }





  /*
  for(int i=0;i<sizes;i++){
		array = makeRandomArray(size[i]);
	  //InsertionSort(array,size[i]);
    timeSort(InsertionSort, array, size[i]);
    for(int j=0;j<size[i];j++){
      std::cout<<array[j]<<" "<<std::endl;
    }









    delete []  array;
	}
*/

  delete [] array;
	return 0;
}
