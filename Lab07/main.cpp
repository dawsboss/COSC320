#include <iostream>
#include "math.h"

bool isPrime(size_t);


size_t Hash1(size_t);
void displayHash(size_t);
size_t Hash2(std::string);
size_t Hash3(std::string);








int main(){
	std::cout<<"Testing Hash1: "<<std::endl;
	int HashNum = 50120;
	std::cout<<"hashing number: "<<HashNum<<std::endl;
	displayHash(Hash1(50120));
	std::cout<<"HasNum hased: Testing to make sure it worked: "<<Hash1(50120)<<std::endl;

	std::cout<<"Hash this: 29 \nHash: "<<Hash1(29)<<" \nConfirm Hash: "<<Hash1(29)<<std::endl;

	std::cout<<"Hash this: 1569 \n Hash: "<<Hash1(1569)<<" \nConfirm Hash: "<<Hash1(1569)<<std::endl;


	std::cout<<"Testing Hash2: \n";

	std::string toHash = "The dog ran outside and ran down the street";
	std::cout<<"Hash this: "<<toHash<<" \nHash: "<<Hash2(toHash)<<" \nConfirm Hash: "<<Hash2(toHash)<<std::endl;

	toHash = "I have no money in my banmk account, SAD PANDA!";
	std::cout<<"Hash this: "<<toHash<<" \nHash: "<<Hash2(toHash)<<" \nConfirm Hash: "<<Hash2(toHash)<<std::endl;

	std::cout<<"Input a string: "<<std::endl;
	std::getline(std::cin, toHash);
	std::cout<<"Hash this: "<<toHash<<" \nHash: "<<Hash2(toHash)<<" \nConfirm Hash: "<<Hash2(toHash)<<std::endl;


	std::cout<<"Testing Hash3: \n";


	toHash = "The dog ran outside and ran down the street";
	std::cout<<"Hash this: "<<toHash<<" \nHash: "<<Hash3(toHash)<<" \nConfirm Hash: "<<Hash3(toHash)<<std::endl;

	toHash = "I have no money in my banmk account, SAD PANDA!";
	std::cout<<"Hash this: "<<toHash<<" \nHash: "<<Hash3(toHash)<<" \nConfirm Hash: "<<Hash3(toHash)<<std::endl;

	std::cout<<"Input a string: "<<std::endl;
	std::getline(std::cin, toHash);
	std::cout<<"Hash this: "<<toHash<<" \nHash: "<<Hash3(toHash)<<" \nConfirm Hash: "<<Hash3(toHash)<<std::endl;


	return 0;
}





bool isPrime(size_t num){
	//std::cout<<"num in isPrime: "<<num<<std::endl;
	if(num == 1){
		return true;
	}
	for(int i=2; i<num/2; i++){
		if(num%i == 0){
			//std::cout<<"		False\n";
			return false;
		}
	}
//	std::cout<<"		True\n";
	return true;
}





size_t Hash1(size_t toHash){
	size_t w = 32;
	//std::cout<<"W = "<<W<<std::endl;
	size_t P = 24;
	size_t A=997;



	size_t a = A*toHash;
	size_t one = 1;
	size_t mod = a & ((one<<w)-one);
	return mod>>(w-P);


	//return (int)((A*toHash)%(W))/(exp2(64-P));
}

void displayHash(size_t h){
	std::cout<<"Hash: "<< h <<"\n";
}


size_t Hash2(std::string s){
		size_t A = 997;

	size_t sum=0;
	for(int i=0; i<s.length(); i++){
		sum += ((int)s[i]);
	}

	size_t w = 32;
	size_t P = 24;



	size_t a = A*sum;
	size_t one = 1;
	size_t mod = a & ((one<<w)-one);
	return mod>>(w-P);


	// return (int)((A*sum)%W)/(exp2(64-P));
}


size_t Hash3(std::string s){
	size_t sum = 0;
	size_t A = 997;
	for(int i=0; i<s.length(); i++){
		sum += (int)s[i] + A;
	}

	return sum%569;
}
