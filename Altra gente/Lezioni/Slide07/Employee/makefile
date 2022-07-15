#Makefile for testEmployee example
testEmployee: testEmployee.o Date.o Employee.o
		g++ -o testEmployee testEmployee.o Date.o Employee.o
testEmployee.o: testEmployee.cpp Date.h Employee.h
		g++ -c testEmployee.cpp -Wall -pedantic -std=c++11
Employee.o: Date.h Employee.h Employee.cpp
		g++ -c Employee.cpp -Wall -pedantic -std=c++11
Date.o: Date.h Date.cpp
		g++ -c date.cpp -Wall -pedantic -std=c++11