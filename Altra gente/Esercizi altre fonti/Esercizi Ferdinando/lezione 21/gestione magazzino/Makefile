Driver: Driver.o Magazzino.o
	g++ -o Driver Driver.o Magazzino.o
Driver.o: Driver.cpp Magazzino.h
	g++ -c Driver.cpp -std=c++11 -pedantic -Wall
Magazzino.o: Magazzino.cpp Magazzino.h
	g++ -c Magazzino.cpp -std=c++11 -pedantic -Wall