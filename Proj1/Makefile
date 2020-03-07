output: main.o
	g++ -g -std=c++11 main.o -o main
main.o: main.cpp
	g++ -c -g -std=c++11 main.cpp
submit:
	make clean; zip Proj1.zip *
clean:
	rm *.o -f main
