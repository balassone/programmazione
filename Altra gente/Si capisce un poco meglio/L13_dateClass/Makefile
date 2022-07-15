testDate: testDate.o Date.o
	g++ -o testDate testDate.o Date.o
testDate.o: Date.h testDate.cpp
	g++ -c testDate.cpp -std=c++11 -pedantic -Wall
Date.o: Date.cpp Date.h
	g++ -c Date.cpp -std=c++11 -pedantic -Wall