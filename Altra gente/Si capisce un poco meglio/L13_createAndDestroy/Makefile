testDestructors: testDestructors.o CreateAndDestroy.o
	g++ -o testDestructors testDestructors.o CreateAndDestroy.o
testDestructors.o: testDestructors.cpp CreateAndDestroy.h
	g++ -c testDestructors.cpp -Wall -std=c++11 -pedantic
CreateAndDestroy.o: CreateAndDestroy.h CreateAndDestroy.cpp
	g++ -c CreateAndDestroy.cpp -std=c++11 -Wall -pedantic