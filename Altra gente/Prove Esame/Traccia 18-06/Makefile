Driver: Driver.o Prestito.o Libro.o Data.o
	g++ -o Driver Driver.o
Driver.o: Driver.cpp Prestito.h Libro.h Data.h
	g++ -c Driver.cpp -std=c++11 -pedantic -Wall
Prestito.o: Prestito.cpp Prestito.h Libro.h Data.h
	g++ -c Prestito.cpp -std=c++11 -pedantic -Wall
Libro.o: Libro.cpp Libro.h 
	g++ -c Libro.cpp -std=c++11 -pedantic -Wall
Data.o: Data.cpp Data.h
	g++ -c Libro.cpp -std=c++11 -pedantic -Wall