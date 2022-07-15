Driver: Driver.o Polinomio.o
	g++ -o Driver Driver.o Polinomio.o
Driver.o: Driver.cpp Polinomio.h
	g++ -c Driver.cpp -std=c++11 -pedantic -Wall
Polinomio.o: Polinomio.cpp Polinomio.h
	g++ -c Polinomio.cpp -std=c++11 -pedantic -Wall