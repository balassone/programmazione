testDate: testDate.o Date.o
	g++ -o testDate testDate.o Date.o -std=c++11 -Wall -pedantic
testDate.o: testDate.cpp Date.h
	g++ -c testDate.cpp -std=c++11 -Wall -pedantic
Date.o: Date.cpp Date.h
	g++ -c Date.cpp -std=c++11 -Wall -pedantic