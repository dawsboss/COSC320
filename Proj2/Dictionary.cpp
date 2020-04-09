#include "Dictionary.h"

//Hashing Algorithm
size_t Dictionary::Hash(std::string s){
  size_t A = 15489079;
  size_t sum=0;
	size_t seven = 7;
  for(size_t i=0; i<s.length(); i++){
    sum += (size_t)  (s[i])<<(i*seven);
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

//Initilizes the dictionary to have words from the given file (INCLUDE file types, name*.filetype*)
void Dictionary::init(std::string fileName){
  std::ifstream readIn;
  readIn.open(fileName);
  std::string holder;
  int wordCounter=0;
  auto start = std::chrono::system_clock::now();

  while(readIn>>holder){
    this->insert(holder);
    wordCounter++;
  }

  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
  std::cout<<"Finished at: "<<std::ctime(&end_time)<<"elapsed time: "<<elapsed_seconds.count()<<"s\n";
  std::cout<<"Total words: "<<wordCounter<<std::endl;
  this->printAtateOfHash();
  readIn.close();
}


//Inserts a new word by hashing it and putting it in it's respective linked dlist
void Dictionary::insert(std::string data){
  size_t hashed = Hash(data);
	//std::cout<<"hashed: "<<hashed<<" data: "<<data<<std::endl;
	HashItems d(data);
  this->HashTable[hashed].putFront(d);
  this->stateOfHashes[hashed]++;
}

//Seachers the hash table for a given word
bool Dictionary::search(std::string s){
	return HashTable[Hash(s)].contains(HashItems(s));
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
  int lowestCollision = 0;
  double avrgColl = this->HashTable[0].size();;
	for(int i=1; i<this->numOfHashes; i++){
    avrgColl += this->HashTable[i].size();
		if(this->HashTable[i].size() > this->HashTable[HeightCollision].size()){
			HeightCollision = i;
		}
    if(this->HashTable[i].size() < this->HashTable[HeightCollision].size()){
			lowestCollision = i;
		}
	}
	Logger::init("Bruh");
	for(int i=0; i<this->numOfHashes; i++){
		Logger::log(i);
	}
	Logger::ln();
	for(int i = 0; i<this->numOfHashes; i++){
		Logger::log(this->HashTable[i].size());
	}

  std::cout<<"The average collissions per bucket: "<<(double)avrgColl/numOfHashes<<std::endl;
	std::cout<<"Highest Collision hash: "<<HeightCollision<<" Number of collisions: "<<this->HashTable[HeightCollision].size()<<std::endl;
  std::cout<<"Lowest Collision hash: "<<lowestCollision<< " Number of collissions: "<<this->HashTable[lowestCollision].size()<<std::endl;
	std::cout<<"Number of hashes with nothing: "<<nothingInHash<<std::endl;
  std::cout<<"Number of buckets: "<<numOfHashes<<std::endl;

  std::cout<<std::endl;

}
























void Dictionary::autoCorrect(std::string input){
  for(int i=0; i<input.length(); i++){
    if(ispunct(input[i])){
      input.erase(i--, 1);
    }
  }
  std::stringstream ss;
  ss << input;
  std::string holder;
  SUList<std::string> BadWordsSuggestions;
  SUList<std::string> GoodSuggestions;
  SUList<std::string> BadWordsSuggestions2;
  SUList<std::string> BadWordsSuggestions2Holder;
  SUList<std::string> GoodSuggestions2;
  SUList<std::string> GoodSuggestions2Holder;
  bool anyGoodSuggestions = false;
  bool anyGoodSuggestions2 = false;
  while (ss >> holder){
    if(!this->search(holder)){
      try{
        BadWordsSuggestions = __autoCorrect(holder);
        std::cout<<"\""<<holder<<"\" was detected as misspelled, suggestions for a one latter replace: "<<BadWordsSuggestions.size()<<std::endl;
        if(BadWordsSuggestions.size() < 1){
          std::cout<<"No corrections avaliable!"<<std::endl;
          continue;
        }
        for(int i=BadWordsSuggestions.size(); i>0; i--){
          if(this->search(BadWordsSuggestions[i])){
            GoodSuggestions.putFront(BadWordsSuggestions[i]);
            std::cout<<"*"<<BadWordsSuggestions[i]<<"* ";
            anyGoodSuggestions=true;
          }else{
            BadWordsSuggestions2 = __autoCorrect(BadWordsSuggestions[i]);
            //std::cout<<"BadWord 2 "<<BadWordsSuggestions.size()<<"i: "<<i<<std::endl;
            if(BadWordsSuggestions2.size() < 1){
              std::cout<<"No corrections avaliable!"<<std::endl;
              continue;
            }
            //BadWordsSuggestions2Holder = BadWordsSuggestions2Holder + BadWordsSuggestions2;
            for(int i=BadWordsSuggestions2.size(); i>0; i--){
              if(this->search(BadWordsSuggestions2[i])  && !GoodSuggestions2.contains(BadWordsSuggestions2[i])){
                GoodSuggestions2.putFront(BadWordsSuggestions2[i]);
                //std::cout<<BadWordsSuggestions2Holder[i]<<" ";
                anyGoodSuggestions2 = true;
              }
            }
          }
        }
        if(!anyGoodSuggestions)
          std::cout<<"No corrections avaliable!"<<std::endl;
      }catch(...){
        std::cout<<"REEEEEEEEEEEEEEEEEe"<<std::endl;
      }
      std::cout<<std::endl;
      // std::cout<<"Half way"<<std::endl;
      std::cout<<std::endl;
      std::cout<<"Suggestions for a two latter replace: "<<std::endl;
      if(GoodSuggestions2.size() < 1){
        std::cout<<"No corrections avaliable!"<<std::endl;
        continue;
      }
      if(!anyGoodSuggestions2)
        std::cout<<"No corrections avaliable!"<<std::endl;
      for(int i=GoodSuggestions2.size(); i>0; i--){
          std::cout<<"*"<<GoodSuggestions2[i]<<"* ";
      }
      std::cout<<std::endl;
      std::cout<<std::endl;
    }
    std::cout<<std::endl;
    BadWordsSuggestions.clear();
    GoodSuggestions.clear();
    BadWordsSuggestions2.clear();
    BadWordsSuggestions2Holder.clear();
    GoodSuggestions2.clear();
    GoodSuggestions2Holder = GoodSuggestions2Holder+GoodSuggestions;
  }
}


SUList<std::string> Dictionary::__autoCorrect(std::string input){
  std::string holder;
  SUList<std::string> BadWordsSuggestion;
    // std::cout<<std::endl;
    // std::cout<<std::endl;

        //change letters
        std::string editor = input;
        holder = editor;
        //std::cout<<"\""<<holder<<"\" was flagged as miss spelled! We suggest these as replacements: "<<std::endl;
        for(int w=0; w<editor.length(); w++){
          for(int j=97; j<=122; j++){
            editor[w] = (char)j;
            BadWordsSuggestion.putFront(editor);
            editor = holder;
          }
        }

        // std::cout<<std::endl;

        //Add letters
        std::string addlet;
        editor = holder;
        for(int w=0; w<=editor.length(); w++){
          for(int j=97; j<=122; j++){
            addlet = (char)j;
            editor.insert(w, addlet);
            BadWordsSuggestion.putFront(editor);
            editor = holder;
          }
        }

        // std::cout<<std::endl;

        //Delete a letter
        editor = holder;
        for(int w=0; w<editor.length(); w++){
            editor.erase(editor.begin() + w);
            BadWordsSuggestion.putFront(editor);
            editor = holder;
        }

        // std::cout<<std::endl;

        //Swap letters
        editor = holder;
        for(int w=1; w<editor.length(); w++){
            std::swap(editor[w-1], editor[w]);
            BadWordsSuggestion.putFront(editor);
            editor = holder;
        }
    return BadWordsSuggestion;
}
