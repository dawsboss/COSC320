output: Matrix.o main.o
	g++ -g -std=c++11 Matrix.o main.o -o main
main.o: main.cpp
	g++ -c -g -std=c++11 main.cpp
Matrix.o: Matrix.cpp Matrix.h
	g++ -c -g -std=c++11 Matrix.cpp -Wall
submit:
	make clean; zip Proj1.zip *
clean:
	rm *.o -f main
