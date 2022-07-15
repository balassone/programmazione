Driver: Driver.o Convegno.o Rivista.o Libro.o Pubblicazione.o Data.o
	g++ -o Driver Driver.o Convegno.o Rivista.o Libro.o Pubblicazione.o Data.o
Driver.o: Driver.cpp Convegno.h Rivista.h Libro.h Pubblicazione.h
	g++ -c Driver.cpp -std=c++11 -pedantic -Wall
Convegno.o: Convegno.cpp Convegno.h Pubblicazione.h
	g++ -c Convegno.cpp -std=c++11 -pedantic -Wall
Rivista.o: Rivista.cpp Rivista.h Pubblicazione.h
	g++ -c Rivista.cpp -std=c++11 -pedantic -Wall
Libro.o: Libro.cpp Libro.h Pubblicazione.h
	g++ -c Libro.cpp -std=c++11 -pedantic -Wall
Pubblicazione.o: Pubblicazione.cpp Pubblicazione.h Data.h
	g++ -c Pubblicazione.cpp -std=c++11 -pedantic -Wall
Data.o: Data.cpp Data.h
	g++ -c Data.cpp -std=c++11 -pedantic -Wall

