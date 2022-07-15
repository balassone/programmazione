Driver: Driver.o Orario.o 
	g++ -o Driver Driver.o Orario.o 
Driver.o: Driver.cpp Orario.o 
	g++ -c Driver.cpp -std=c++11 -pedantic -Wall
Orario.o: Orario.cpp Orario.h
	g++ -c Orario.cpp -std=c++11 -pedantic -Wall