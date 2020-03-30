#include "Dictionary.h"

//Hashing Algorithm
size_t Dictionary::Hash(std::string s){
  size_t A = 15489079;
  size_t sum=0;
  for(int i=0; i<s.length(); i++){
    sum += (size_t)  (s[i]);//TODO * 128^i
  }
  size_t w = 32;
  size_t P = log2(numOfHashes); // makes sure that the hash only chooses p bits and 2^p is 16384
  size_t a = A*sum;
  size_t one = 1;
  size_t mod = a & ((one<<w)-one);
  return mod>>(w-P);
}

//Defualt Constructor
Dictionary::Dictionary(){
  for(int i =0; i<this->numOfHashes; i++){
    stateOfHashes[i]=0;
  }
}

//Copy Constructor
Dictionary::Dictionary(const Dictionary& B){
  for(int i=0; i<this->numOfHashes; i++){
    this->stateOfHashes[i] = B.stateOfHashes[i];
    this->HashTable[i] = B.HashTable[i];
  }
}

Dictionary::~Dictionary(){
  //delete [] HashTable; This is the idea behind it
}

Dictionary& Dictionary::operator= (const Dictionary& B){
  if(this==&B){
    return *(this);
  }

  //delete [] HashTable; done in the SUList's = operator

  for(int i=0; i<this->numOfHashes; i++){
    this->stateOfHashes[i] = B.stateOfHashes[i];
    this->HashTable[i] = B.HashTable[i];
  }
}

void Dictionary::insert(std::string data){
  size_t hashed = Hash(data);
	std::cout<<"hashed: "<<hashed<<" data: "<<data<<std::endl;
	HashItems d(data);
  this->HashTable[hashed].putFront(d);
  this->stateOfHashes[hashed]++;
}


void Dictionary::printAtateOfHash(){
	int nothingInHash=0;
	for(int i=0; i<this->numOfHashes; i++){
		if(this->HashTable[i].size() != 0){
			//std::cout<<i<<" ";
		}else{
			nothingInHash++;
		}
	}
	
	int HeightCollision = 0;
	for(int i=1; i<this->numOfHashes; i++){
		if(this->HashTable[i].size() > this->HashTable[HeightCollision].size()){
			HeightCollision = i;
		}
	}
	std::cout<<"Highest Collision hash: "<<HeightCollision<<" Number of collisions: "<<this->HashTable[HeightCollision].size()<<std::endl;
	std::cout<<std::endl;
	std::cout<<"Number of hashes with nothing: "<<nothingInHash<<std::endl;
}


