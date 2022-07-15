GCC = g++
CFLAGS = -std=c++11 -pedantic -Wall

testRicevuta: testRicevuta.o Ricevuta.o
	${GCC} -o testRicevuta testRicevuta.o Ricevuta.o
testRicevuta.o: testRicevuta.cpp Ricevuta.h
	${GCC} -c testRicevuta.cpp ${CFLAGS}
Ricevuta.o: Ricevuta.cpp Ricevuta.h
	${GCC} -c Ricevuta.cpp ${CFLAGS}	