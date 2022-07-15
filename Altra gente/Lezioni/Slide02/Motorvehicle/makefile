GCC = g++
CFLAGS = -std=c++11 -Wall -pedantic

Motorvehicle: Motorvehicle.o testMotorvehicle.o
	${GCC} -o Motorvehicle Motorvehicle.o testMotorvehicle.o ${CFLAGS}
testMotorvehicle.o: testMotorvehicle.cpp Motorvehicle.h
	${GCC} -c testMotorvehicle.cpp ${CFLAGS}
Motorvehicle.o: Motorvehicle.cpp Motorvehicle.h
	${GCC} -c Motorvehicle.cpp ${CFLAGS}