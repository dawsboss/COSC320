#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include "SUList.h"
#include "math.h"
#include "Logger.h"
#include <fstream>
#include <chrono>
#include <sstream>

class Dictionary{

	private:
		static const int numOfHashes = 8192;
		int stateOfHashes [numOfHashes];

		struct HashItems{
			//int numberOfUse=0; This could be cool because then I can add a real spell checker that can
				//suggest worlds based on how close they were and the most used first
			std::string data;

			HashItems(){
				data = "";
			}
			HashItems(std::string s){
				data = s;
			}
			bool operator==(const HashItems& x){
				return data==x.data;
			}
		};


		SUList<HashItems> HashTable[numOfHashes];

		size_t Hash(std::string);

	public:
		Dictionary();
		Dictionary(const Dictionary&);
		~Dictionary();
		Dictionary& operator= (const Dictionary&);

		void init(std::string);

		void autoCorrect(std::string);
		SUList<std::string> __autoCorrect(std::string);

		void insert(std::string data);
		bool search(std::string);

		void printAtateOfHash();
};
#endif
