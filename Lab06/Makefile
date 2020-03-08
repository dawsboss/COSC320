GCC=g++
FLAGS=-std=c++11 -Wall -g

output: main.o
	$(GCC) $(FLAGS) -o main main.o
main.o: main.cpp
	$(GCC) $(FLAGS) -c main.cpp

submit:
	make clean; zip Lab05.zip *
clean:
	rm *.o -f main
