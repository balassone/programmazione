testEmployee: testEmployee.o Date.o Employee.o
	g++ -o testEmployee testEmployee.o Date.o Employee.o
testEmployee.o: Date.h Employee.h testEmployee.cpp
	g++ -c testEmployee.cpp -std=c++11 -Wall -pedantic
Employee.o: Date.h Employee.h Employee.cpp
	g++ -c Employee.cpp -std=c++11 -Wall -pedantic
Date.o: Date.cpp Date.h 
	g++ -c Date.cpp -std=c++11 -Wall -pedantic