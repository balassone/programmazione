Driver: Driver.o Impiegato.o Data.o
	g++ -o Driver Driver.o Impiegato.o Data.o
Driver.o: Driver.cpp Impiegato.h
	g++ -c Driver.cpp -std=c++11 -pedantic -Wall
Impiegato.o: Impiegato.cpp Data.h
	g++ -c Impiegato.cpp -std=c++11 -pedantic -Wall
Data.o: Data.cpp Data.h
	g++ -c Data.cpp -std=c++11 -pedantic -Wall