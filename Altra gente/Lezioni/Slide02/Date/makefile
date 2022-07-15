GCC = g++
CFLAGS = -std=c++11 -Wall -pedantic

date:date.o testDate.o
	${GCC} -o date date.o testDate.o
date.o: date.cpp date.h
	${GCC} -c date.cpp ${CFLAGS}
testDate.o: testDate.cpp date.h
	${GCC} -c testDate.cpp ${CFLAGS} 