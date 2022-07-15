GCC = g++
CFLAGS = -std=c++11 -Wall -pedantic

THR: testTHR.o TargetHeartRateCalculator.o
	${GCC} -o testTHR testTHR.o TargetHeartRateCalculator.o
testTHR: testTHR.cpp TargetHeartRateCalculator.h
	${GCC} -c testTHR.cpp ${CFLAGS}
TargetHeartRateCalculator.o: TargetHeartRateCalculator.cpp TargetHeartRateCalculator.h
	${GCC} -c TargetHeartRateCalculator.cpp ${CFLAGS} 