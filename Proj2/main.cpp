#include <iostream>
#include "Dictionary.h"
#include <sstream>
#include <chrono>

int main(){
	//Hashing ditionary
	Dictionary d;
	d.init("english.txt");
	//Hash table made
	std::string input;

	getline(std::cin, input);

	double* info;


	info = d.autoCorrect(input);


	std::cout<<std::endl;
	std::cout<<"-----------------------"<<std::endl;
	std::cout<<"        Summary        "<<std::endl;
	std::cout<<"-----------------------"<<std::endl;
	std::cout<<"# of misspelled words: "<<info[0]<<std::endl;
	std::cout<<"# of suggestions: "<<info[1]<<std::endl;
	std::cout<<"elapsed time: "<<info[2]<<std::endl;


	return 0;
}
