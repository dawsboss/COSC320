output: main.o Dictionary.o
	g++ -g -std=c++11 main.o Dictionary.o -o main

main.o: main.cpp
	g++ -c -g -std=c++11 main.cpp

Dictionary.o: Dictionary.cpp Dictionary.h SUList.cpp SUList.h
	g++ -c -g -std=c++11 Dictionary.cpp

clean:
	rm *.o -f main
