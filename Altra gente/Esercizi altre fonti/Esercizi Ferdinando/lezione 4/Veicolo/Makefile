Driver: Driver.o Veicolo.o
	g++ -o Driver Driver.o Veicolo.o
Driver.o: Driver.cpp Veicolo.h
	g++ -c Driver.cpp -std=c++11 -pedantic -Wall
Veicolo.o: Veicolo.cpp Veicolo.h
	g++ -c Veicolo.cpp -std=c++11 -pedantic -Wall