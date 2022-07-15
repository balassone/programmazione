Driver: Driver.o Fattura.o
	g++ -o Driver Driver.o Fattura.o
Driver.o: Driver.cpp Fattura.h
	g++ -c Driver.cpp -std=c++11 -pedantic -Wall
Fattura.o: Fattura.cpp Fattura.h
	g++ -c Fattura.cpp -std=c++11 -pedantic -Wall