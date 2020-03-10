#include <iostream>//pritning
#include "Logger.h"//File writer
#include <chrono>//chrono

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

unsigned long long Hires=0;
double Times = 0;
void shuffle(int*, int);
int* makeRandomArray(int);
void swap(int&, int&);
int* makeCanadates(int);
int hireAlgorithm(int*, int);
void timeSort(void (*sort)(int[], int, int), int*, int);
void QuickSort(int A[], int, int);
void RandQuickSort(int A[], int, int);
int Partition(int*, int, int);
bool isSorted(int*, int);
void MergeSort(int A[], int, int);
void Merge(int*, int, int, int, int);
bool HeapisSorted(Heap* A);

//For Heap
void timeSortHeap(void (*sort)(Heap*), Heap*);
void HeapSort(Heap*);
void MaxHeapify(Heap*, int);
void BuildMaxHeap(Heap*);


int main(){
  srand(time(NULL));
  Logger::init("Result");
  int* canadates = makeCanadates(10);
  shuffle(canadates, 10);
  std::cout<<"test \n";
  for(int i=0; i<10;i++){
    std::cout<<canadates[i]<<" ";
  }




  int sizes[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 150, 200, 250, 300, 350, 400, 450, 500,1000,1500,2000,2500,3000,3500,4000,4500,5000};
  int size = 27;
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

  Logger::ln();
  std::cout<<std::endl;

  std::cout<<"Press enter to continue"<<std::endl;
  std::cin.ignore();
  //Test Heap, Quick, Merge, and RandQuick Sorts
  int* arr;
  std::string sorters[] = {"MergeSort", "QuickSort", "RandQuickSort"};
  typedef void (*fn) (int*,int, int);
  static fn Sorters[] = {MergeSort, QuickSort, RandQuickSort};
  for(int j=0; j<3; j++){
    for(int i=10000; i<1100000; i+=50000){
      std::cout<<"Back to the top"<<std::endl;
      for(int k=0; k<20; k++){
        arr = makeRandomArray(i);
        shuffle(arr, i);
        timeSort(Sorters[j], arr, i);
        delete [] arr;
      }
      std::cout<<sorters[j]<<": Avg # of hires for "<<i<<": "<<(Hires/20)<<std::endl;
      Logger::logln(sorters[j] + ": Avg # of hires for "+ std::to_string(i) + ": " + std::to_string(Hires/20));
      Logger::logln(" Time: "+ std::to_string(Times/20.0));
      Hires = 0;
      Times = 0;
    }
  }

/*HEAP STUFF: */
  Heap* tester;
  for(int i=10000; i<1100000; i+=50000){
    std::cout<<"Back to the top"<<std::endl;
    for(int k=0; k<20; k++){
      arr = makeRandomArray(i);
      shuffle(arr, i);
      tester = new Heap(i, arr);
      timeSortHeap(HeapSort, tester);
      delete tester;
    }
    std::cout<<"HeapSort: Avg # of hires for "<<i<<": "<<(Hires/20)<<std::endl;
    Logger::logln("HeapSort: Avg # of hires for "+ std::to_string(i) + ": " + std::to_string(Hires/20));
    Logger::logln(" Time: "+ std::to_string(Times/20.0));
    Hires = 0;
    Times = 0;
  }






  delete [] canadates;



  return 0;
}



void shuffle(int* oldArr, int len){
  int rand1;
  int rand2;
  for(int i = 0; i<(len); i++){
    rand2 = (int)rand() % (len-i) + i;
    rand1 = (int)rand() % (len-i) + i;
    swap(oldArr[rand1], oldArr[rand2]);
  }
}

int* makeRandomArray(int len){
	int* rtn=new int[len];
	for(int i=0;i<len;i++){
		 rtn[i]=1+rand()%100;//1-100
	}
	return rtn;
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
  auto elapsed = end - start;
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
  std::cout<<"Finished at: "<<std::ctime(&end_time)<<"elapsed time: "<<elapsed_seconds.count()<<"s\n";

  Times += std::chrono::duration<double>(elapsed).count();
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

//Partition: it cuts an array based on a piviot point. whwere it takes a piviot and then moves it to its co0rrect spot in the everything right it greater
//and everything to left is less (in my case) or equal
int Partition(int* A, int start, int end){
  int piviot = A[end-1];
  int loc = start-1;
  for(int i=start; i<end-1; i++){
    if(A[i]<=piviot){
      swap(A[++loc],A[i]);
      Hires++;
    }
  }
  swap(A[loc+1],A[end-1]);
  Hires++;
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

//RandQuickSort: Although extremly similar to QuickSort this will make the Partition randomly choosen
void RandQuickSort(int A[], int start, int end){
    if(start<end){
      int rand1 = (int)rand() % (end -start);
      swap(A[rand1], A[end]);
      int p = Partition(A,start,end);
      QuickSort(A,start,p);
      QuickSort(A,p+1,end);
    }
}


//Merge: takes two given arrays and puts them together sorted
void Merge(int* arr, int s1, int s2, int e1, int e2){
  int i=s1,j=s2,k=0;
  int rtn [(e1-s1)+(e2-s2)];
  while(i<(e1) && j<(e2)){
    Hires++;
    if(arr[i]<arr[j]){
      rtn[k++]=arr[i++];
    }else{
			rtn[k++]=arr[j++];
		}
  }
	while(i<(e1)){
    Hires++;
    rtn[k++]=arr[i++];
	}
	while(j<(e2)){
    Hires++;
    rtn[k++]=arr[j++];
	}
  for(int w=0;w<((e1-s1)+(e2-s2)); w++){
    Hires++;
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
	if(start < end-1){

		int mid = (end+start)/2;
		MergeSort(A,start,mid);
		MergeSort(A, mid, end);
    Merge(A, start, mid, mid, end);
	}
}







/* HEAP STUFF:*/








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
    Hires++;
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
    Hires++;
    A->heap_size--;
    //We moved one of the smaller elements to the root so we have to clean up
    MaxHeapify(A,1);
  }
}












//Takes a sorting algorithm calls it and prints it's meta data
void timeSortHeap(void (*sort)(Heap*), Heap* A){
  //The "auto" type determines the corret type at compile-time
  auto start=std::chrono::system_clock::now();

  sort(A);

	 if(!HeapisSorted(A)){
	 	Logger::log("Did not Sort!----------------------------------------------------- Error: Oof");
	 	std::cout<<"You are big dumb and it ain't no sorted"<<std::endl;
	 	return;
	 }

  auto end=std::chrono::system_clock::now();
  auto elapsed = end - start;
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
  std::cout<<"Finished at: "<<std::ctime(&end_time)<<"elapsed time: "<<elapsed_seconds.count()<<"s\n";

  Times += std::chrono::duration<double>(elapsed).count();
}

//Heap verssion of isSorted
bool HeapisSorted(Heap* A){
	for(int i=1;i<A->length;i++){
		if((*A)[i-1]>(*A)[i]){
			return false;
		}
	}
	return true;
}
