output: main.o Dictionary.o Logger.o
	g++ -g -std=c++11 main.o Dictionary.o Logger.o -o main

main.o: main.cpp
	g++ -c -g -std=c++11 main.cpp

Dictionary.o: Dictionary.cpp Dictionary.h SUList.cpp SUList.h
	g++ -c -g -std=c++11 Dictionary.cpp

Logger.o: Logger.h Logger.cpp
	g++ -c -g -std=c++11 Logger.cpp
clean:
	rm *.o -f main
