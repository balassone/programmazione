#Makefile for testDestructors
testDestructors: testDestructors.o CreateAndDestroy.o
	g++ -o testDestructors testDestructors.o CreateAndDestroy.o
testDestructors.o: testDestructors.cpp CreateAndDestroy.h
	g++ -c testDestructors.cpp -std=c++11 -Wall -pedantic
CreateAndDestroy.o: CreateAndDestroy.h CreateAndDestroy.cpp
	g++ -c CreateAndDestroy.cpp -std=c++11 -Wall -pedantic
	
