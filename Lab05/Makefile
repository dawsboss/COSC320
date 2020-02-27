output: HeapQ.o main.o
	g++ -g -std=c++11 main.o HeapQ.o -o main
	
main.o: main.cpp
	g++ -c -g -std=c++11 main.cpp
	
HeapQ.o: HeapQ.cpp HeapQ.h
	g++ -c -g -std=c++11 HeapQ.cpp
	
clean: 
	rm *.o -f main