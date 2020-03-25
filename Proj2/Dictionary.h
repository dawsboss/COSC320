#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include "SUList.h"

class Dictionary{

	private:
		int numOfHashes = 16384;
		int statOfHashes [16384];

		struct HashItems{
			int numberOfUse=0;	
			std::string data;
		};

		SUList<HashItems> HashTable[16384];

		int Hash(std::string);

	public:
		Dictionary();
		Dictionary(const Dictionary&);
		~Dictionary();
		Dinctionary operator= (const Dictionary&);

		void insert(std::string data);






};
#endif
