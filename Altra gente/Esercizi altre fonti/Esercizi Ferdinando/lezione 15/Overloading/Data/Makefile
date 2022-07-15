Driver: Driver.o Data.o
	g++ -o Driver Driver.o Data.o
Driver.o: Driver.cpp Data.h
	g++ -c Driver.cpp -std=c++11 -pedantic -Wall
Data.o: Data.cpp Data.h
	g++ -c Data.cpp -std=c++11 -pedantic -Wall