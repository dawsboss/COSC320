#include <iostream>
#include "Dictionary.h"
#include <sstream>

int main(){
	//Hashing ditionary
	Dictionary d;
	d.init("english.txt");
	//Hash table made

	std::string input = "2";

	//If the world is in there then print yeet if not we need ot do work to find something for it

	getline(std::cin, input);




	d.autoCorrect(input);

	return 0;
}
