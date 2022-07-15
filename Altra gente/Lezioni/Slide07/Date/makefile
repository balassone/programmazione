#Makefile for testDate
testDate: testDate.o Date.o
		g++ -o testDate testDate.o Date.o
testDate.o: testDate.cpp Date.h
		g++ -c testDate.cpp -std=c++11 -Wall -pedantic
Date.o: Date.h Date.cpp
		g++ -c Date.cpp -std=c++11 -Wall -pedantic
