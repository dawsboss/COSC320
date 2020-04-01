output: main.o BinaryTree.o
	g++ -g -std=c++11 main.o BinaryTree.o -o main

main.o: main.cpp 
	g++ -c -g -std=c++11 main.cpp

BinaryTree.o: BinaryTree.cpp BinaryTree.h
	g++ -c -g -std=c++11 BinaryTree.cpp

clean:
	rm *.o -f main

submit:
	make clean; zip Lab08.zip *
