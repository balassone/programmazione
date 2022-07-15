Driver: Driver.o Anziano.o Venditore.o Salariato.o Impiegato.o Data.o
	g++ -o Driver Driver.o Anziano.o Venditore.o Salariato.o Impiegato.o Data.o
Driver.o: Driver.cpp Anziano.h Venditore.h Salariato.h
	g++ -c Driver.cpp -std=c++11 -pedantic -Wall
Anziano.o: Anziano.cpp Anziano.h Venditore.h
	g++ -c Anziano.cpp -std=c++11 -pedantic -Wall
Venditore.o: Venditore.cpp Venditore.h Impiegato.h
	g++ -c Venditore.cpp -std=c++11 -pedantic -Wall
Salariato.o: Salariato.cpp Salariato.h Impiegato.h
	g++ -c Salariato.cpp -std=c++11 -pedantic -Wall
Impiegato.o: Impiegato.cpp Impiegato.h Data.h
	g++ -c Impiegato.cpp -std=c++11 -pedantic -Wall
Data.o: Data.cpp Data.h
	g++ -c Data.cpp -std=c++11 -pedantic -Wall