#include <iostream>
#include <fstream>
#include "Dictionary.h"
#include <chrono>
#include "math.h"
#include <sstream>

int main(){

	std::ifstream readIn;
	readIn.open("english.txt");

	//Hashing ditionary
	Dictionary d;
	std::string holder;

	auto start = std::chrono::system_clock::now();
	while(readIn>>holder){
		d.insert(holder);
	}
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end-start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	std::cout<<"Finished at: "<<std::ctime(&end_time)<<"elapsed time: "<<elapsed_seconds.count()<<"s\n";
	d.printAtateOfHash();
	//Hash table made

	std::string input = "2";
	
	//If the world is in there then print yeet if not we need ot do work to find something for it	
	if(d.search(input)){
		std::cout<<"Yeet\n";
	}else{
	for(int i=0;i<5;i++){
		for(){
		
		}
	}

		std::cout<<"No yeet\n";
	}
	
	
	getline(std::cin, input);

	//Takes the given text and puts it into a string stream
	std::stringstream ss;
	ss << input;

	//Runs through the whole string stream and tests each word
	holder;
	while(ss >> holder){
	if(d.search(holder)){
		std::cout<<"Yeet\n";
	}else{
		std::cout<<"No yeet\n";
	}			
		
	}

	readIn.close();
	return 0;
}
