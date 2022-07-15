Driver: Driver.o Rettangolo.o Punto.o

	g++ -o Driver Driver.o Rettangolo.o Punto.o

Driver.o: Driver.cpp Rettangolo.h

	g++ -c Driver.cpp -std=c++11 -pedantic -Wall

Rettangolo.o: Rettangolo.cpp Rettangolo.h Punto.h

	g++ -c Rettangolo.cpp -std=c++11 -pedantic -Wall

Punto.o: Punto.cpp Punto.h

	g++ -c Punto.cpp -std=c++11 -pedantic -Wall
