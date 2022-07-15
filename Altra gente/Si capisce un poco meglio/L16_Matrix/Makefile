#Makefile

testMatrix:testMatrix.o Matrix.o
	g++ -o testMatrix testMatrix.o Matrix.o
testMatrix.o: testMatrix.cpp Matrix.h
	g++ -c testMatrix.cpp -std=c++11 -Wall -pedantic
Matrix.o: Matrix.cpp Matrix.h
	g++ -c Matrix.cpp -std=c++11 -Wall -pedantic