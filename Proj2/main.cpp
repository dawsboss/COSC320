#include <iostream>
#include "Dictionary.h"
#include <fstream>


int main(){

	std::ifstream readIn;
	readIn.open("english.txt");

	Dictionary d;

	std::string holder;
//	while(!readIn.eof()){
	while(readIn>>holder){
		//readIn>>holder;
		d.insert(holder);
	}

	d.printAtateOfHash();



	readIn.close();
	return 0;
}
