Driver: Driver.o Dizionario.o
	g++ -o Driver Driver.o Dizionario.o
Driver.o: Driver.cpp Dizionario.h
	g++ -c Driver.cpp -std=c++11 -pedantic -Wall
Dizionario.o: Dizionario.cpp Dizionario.h
	g++ -c Dizionario.cpp -std=c++11 -pedantic -Wall