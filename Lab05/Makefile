output: main.o
	g++ main.o -o main -g -std=c++11

main.o: main.cpp HeapQ.cpp HeapQ.h
	g++ -c main.cpp -std=c++11 -g

clean:
	rm *.o -f main
