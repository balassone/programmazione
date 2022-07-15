testInstrument: testInstrument.o
	g++ -o testInstrument testInstrument.o
testInstrument.o: testInstrument.cpp Instrument.h
	g++ -c testInstrument.cpp -std=c++11 -Wall -pedantic