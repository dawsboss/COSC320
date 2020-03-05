

//Takes the element at the bottom and gives it the new value of k for it's key and pushes it up the heap // This will need another version to say which element you want to change in the future for implementation
template<class T>
void HeapQ<T>::IncreaseKey(int k){
  if(k < this->arr[heapSize].key)
    throw "New key smaller than old key";
  int index = heapSize;
  this->arr[index].key = k;
  while(index > 1 && this->arr[index/2].key < this->arr[index].key){
    swap(this->arr[index], this->arr[index/2]);
    index = index/2;
  }
}

//Extends the array by 2 times it
template<class T>
void HeapQ<T>::ExpandArray(){
  this->length *= 2;
  HeapObj<T>* newArr = new HeapObj<T>[this->length];
  for(int i=0; i<heapSize+1; i++){
    newArr[i] = this->arr[i];
  }
  delete [] this->arr;
  this->arr = newArr;
}

//Switches andresses of two provided HeapObjs
template<class T>
void HeapQ<T>::swap(HeapObj<T>& x, HeapObj<T>& y){
  HeapObj<T> temp = x;
  x=y;
  y=temp;
}

//Defualt constructor
template<class T>
HeapQ<T>::HeapQ(){
  this->arr = new HeapObj<T>[3];
  this->length = 3;
  this->heapSize = 0;
}


//Copy Constructor
template<class T>
HeapQ<T>::HeapQ(HeapQ<T>& B){
   this->length = B.length;
   this->heapSize = B.heapSize;
   this->arr = new HeapObj<T>[this->length];
   for(int i=0; i < this->length; i++){
     this->arr[i] = B.arr[i];
  }
}


//Deconstructor
template<class T>
HeapQ<T>::~HeapQ(){
  delete [] arr;
}


//= operator
template<class T>
HeapQ<T>* HeapQ<T>::operator=(HeapQ& B){
  if((this) == &B){
    return (this);
  }
  if(length > 0){
    delete [] arr;
  }
   this->heapSize = B.heapSize;
   this->length = B.length;
   this->arr = new HeapObj<T>[this->length];
   for(int i=0; i < this->length; i++){
     this->arr[i] = B.arr[i];
  }
  return this;
}


//Dequeues the biggest element
template<class T>
T HeapQ<T>::ExtractMax(){
  if(heapSize==0)
    throw "Heap is empty";
  swap(arr[1], arr[this->heapSize--]);
  MaxHeapify(1);
  return arr[this->heapSize+1].data;
}


//Looks at data at the top of a queue
template<class T>
T HeapQ<T>::Peek(){
  if(heapSize == 0)
    throw "Nothing in heap";
  return arr[1].data;
}


//Inserts a new array location
template<class T>
void HeapQ<T>::Insert(T d, int k){
  HeapObj<T> newObj(d,k-1);// = new HeapObj<T>();
  // newObj.key = k-1;
  // newObj.data = d;
  if(heapSize+1 == length)
    ExpandArray();
  arr[++this->heapSize] = newObj; // relies on T::operator=
  IncreaseKey(k);
}


//prints out whole queue
template<class T>
void HeapQ<T>::print(/*int i, int d*/){
  std::cout<<std::endl;
  int startNode = 1/*i*/;
  for(int w=0; w<log2(heapSize+1)/*d*/; w++){
    for(int j=startNode; j < (startNode + exp2(w)); j++){
      if(j <= this->heapSize){
        std::cout<<arr[j].data<<" ";
      }else{
        std::cout<<"* ";
      }
    }
    std::cout<<std::endl;
    startNode*=2;
  }
  std::cout<<std::endl;
}


//makes sure the parrent of children are the biggest
template<class T>
void HeapQ<T>::MaxHeapify(int i){
  int l = this->arr->left(i);
  int r = this->arr->right(i);
  //Find the largest among node i and its children, and swap with i
  int Largest;
  if(l <= this->heapSize && this->arr[l].key > this->arr[i].key){
    Largest = l;
  }else{
    Largest = i;
  }
  if(r <= this->heapSize && this->arr[r].key > this->arr[Largest].key){
    Largest = r;
  }
  if(Largest != i){
    //We may have violated the heap propertis, so recurse downward
    swap(this->arr[i], this->arr[Largest]);
    MaxHeapify(Largest);
  }
}
