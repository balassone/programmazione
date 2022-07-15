Driver: Driver.o matrice.o
	g++ -o Driver Driver.o matrice.o
Driver.o: Driver.cpp matrice.h
	g++ -c Driver.cpp -std=c++11 -pedantic -Wall
matrice.o: matrice.cpp matrice.h
	g++ -c matrice.cpp -std=c++11 -pedantic -Wall