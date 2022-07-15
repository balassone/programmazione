Driver: Driver.o Frequenza.o Data.o
	g++ -o Driver Driver.o Frequenza.o Data.o
Driver.o: Driver.cpp Frequenza.h
	g++ -c Driver.cpp -std=c++11 -pedantic -Wall
Frequenza.o: Frequenza.cpp Frequenza.h Data.h
	g++ -c Frequenza.cpp -std=c++11 -pedantic -Wall
Data.o: Data.cpp
	g++ -c Data.cpp -std=c++11 -pedantic -Wall