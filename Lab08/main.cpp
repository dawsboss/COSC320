#include "BinaryTree.h"
#include <chrono>//chrono
#include "Logger.h"


//Takes a sorting algorithm calls it and prints it's meta data
double TimeI = 0;
double TimeS = 0;
double TimeR = 0;
void timeFuncInsert(BinaryTree , int k);
void timeFuncRemove(BinaryTree , int k);
void timeFuncSearch(BinaryTree , int k);




int main(){
	Logger::init("Bruh");
	srand(time(NULL));
	try{
		std::cout<<"Testing insert and delete: \n";
		BinaryTree T;
		std::cout<<"Inserting 10,5,15 \n";
		T.insert(10);
		T.insert(5);
		T.insert(15);
		T.print();
		std::cout<<"Inserting 2 and 6\n";
		T.insert(2);
		T.insert(6);
		T.print();
		std::cout<<"Removing 5\n";
		//T.remove(5);
		T.print();
		std::cout<<"Re-inserting 5\n";
		//T.insert(5);
		T.print();

		std::cout<<std::endl;

		std::cout<<"Testing Succesor: \n";
		std::cout<<"5's successor is: "<<T.successor(5)<<std::endl;

		std::cout<<"10's successor is: "<<T.successor(10)<<std::endl;

		std::cout<<std::endl;

		std::cout<<"Testing max and min: \n";
		std::cout<<"The min of the tree is: "<<T.minimum()<<std::endl;
		std::cout<<"The max of the tree is: "<<T.maximum()<<std::endl;

		std::cout<<std::endl;

		std::cout<<"Testing search and inOrder:"<<std::endl;

		std::cout<<"Lets search for 15: ";
		if(T.search(15)){
			std::cout<<"15 is in the tree!"<<std::endl;
		}else{
			std::cout<<"15 is not in the tree!"<<std::endl;
		}

		std::cout<<"Search for 11: ";
		if(T.search(11)){
			std::cout<<"11 is in the tree!"<<std::endl;
		}else{
			std::cout<<"11 is not in the tree!"<<std::endl;
		}

		std::cout<<"In order: ";
		T.inOrder();

	}catch(std::string s){
		std::cout<<s<<" \n";
	}catch(...){
		std::cout<<"Unknown error \n";
	}



	BinaryTree OneThousand;
	int num;

	for(int j=1; j<=10; j++){
		std::cout<<1000*j<<" element tree operations\n"<<std::endl;
		Logger::logln(std::to_string(1000*j)+" Tree");
		for(int i=0; i<1000;i++){
			num = 1+rand()%50;
			OneThousand.insert(num);
		}

		//THis will run the Insert, remove, search function 10 times each
		for(int i = 0; i<30; i++){
			num = 1+rand()%50;

			std::cout<<"Is "<<num<<" in the tree? ";
			if(OneThousand.search(num)){
				std::cout<<"Yes!\n";
			}else{
				std::cout<<"No!\n";
			}
			timeFuncSearch(OneThousand, num);

			//num = 1+rand()%50;
			std::cout<<"Removing "<<num<<": \n";
			timeFuncRemove(OneThousand, num);

			//num = 1+rand()%50;
			std::cout<<"Inserting "<<num<<": \n";
			timeFuncInsert(OneThousand, num);
		}
		Logger::logln("Inserting time: "+std::to_string(TimeI));
		Logger::logln("Removing time: "+std::to_string(TimeR));
		Logger::logln("Searching time: "+std::to_string(TimeS));
		TimeI = 0;
		TimeR = 0;
		TimeS = 0;


		Logger::ln();
	}




	Logger::close();


	return 0;
}


void timeFuncInsert(BinaryTree B, int k){
	//The "auto" type determines the corret type at compile-time
	auto start=std::chrono::system_clock::now();
	try{
		B.insert(k);
	}catch(std::string s){
		std::cout<<s<<std::endl;
	}catch(...){
		std::cout<<"Unknown error"<<std::endl;
	}


	// if(!isSorted(A)){
	// 	Logger::log("Did not Sort!----------------------------------------------------- Error: Oof");
	// 	std::cout<<"You are big dumb and it ain't no sorted"<<std::endl;
	//  	return;
	// }

	auto end=std::chrono::system_clock::now();
	auto elapsed = end - start;
	std::chrono::duration<double> elapsed_seconds = end-start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	std::cout<<"Finished at: "<<std::ctime(&end_time)<<"elapsed time: "<<elapsed_seconds.count()<<"s\n";
	//Logger::logln("INSERT:=    elapsed time(s): " + std::to_string(elapsed_seconds.count()));
	TimeI += std::chrono::duration<double>(elapsed).count();
}

void timeFuncRemove(BinaryTree B, int k){
	//The "auto" type determines the corret type at compile-time
	auto start=std::chrono::system_clock::now();

	try{
		B.remove(k);
	}catch(std::string s){
		std::cout<<s<<std::endl;
	}catch(...){
		std::cout<<"Unknown error"<<std::endl;
	}

	// if(!isSorted(A)){
	// 	Logger::log("Did not Sort!----------------------------------------------------- Error: Oof");
	// 	std::cout<<"You are big dumb and it ain't no sorted"<<std::endl;
	//  	return;
	// }

	auto end=std::chrono::system_clock::now();
	auto elapsed = end - start;
	std::chrono::duration<double> elapsed_seconds = end-start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	std::cout<<"Finished at: "<<std::ctime(&end_time)<<"elapsed time: "<<elapsed_seconds.count()<<"s\n";
	//Logger::logln("REMOVE: elapsed time(s): " + std::to_string(elapsed_seconds.count()));
	TimeR += std::chrono::duration<double>(elapsed).count();
}

void timeFuncSearch(BinaryTree B, int k){
	//The "auto" type determines the corret type at compile-time
	auto start=std::chrono::system_clock::now();

	try{
			B.search(k);
	}catch(std::string s){
		std::cout<<s<<std::endl;
	}catch(...){
		std::cout<<"Unknown error"<<std::endl;
	}


	// if(!isSorted(A)){
	// 	Logger::log("Did not Sort!----------------------------------------------------- Error: Oof");
	// 	std::cout<<"You are big dumb and it ain't no sorted"<<std::endl;
	//  	return;
	// }

	auto end=std::chrono::system_clock::now();
	auto elapsed = end - start;
	std::chrono::duration<double> elapsed_seconds = end-start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	std::cout<<"Finished at: "<<std::ctime(&end_time)<<"elapsed time: "<<elapsed_seconds.count()<<"s\n";
	//Logger::logln("SEARCH: elapsed time(s): " + std::to_string(elapsed_seconds.count()));
	TimeS += std::chrono::duration<double>(elapsed).count();
}
