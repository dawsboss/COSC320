output: main.o
	g++ -g -std=c++11 main.o -o main
main.o: main.cpp
	g++ -c -g -std=c++11 main.cpp

driver: driver.o
	g++ -g -std=c++11 driver.o -o driver
driver.o:
	g++ -c -g -std=c++11 driver.cpp


submit:
	make clean; zip Proj1GrantDawson.zip *
clean:
	rm *.o -f main driver
