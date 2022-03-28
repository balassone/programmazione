C=g++

F=-std=c++11 -Wall -pedantic -Wextra

E2: E2.o
	${C} -o E2 E2.o E22.o -g #-g per il debugger
E2.o: E2.cpp E2.h
	${C} -c E2.cpp ${F}
E22.o: E22.cpp E2.h
	${C} -c E22.cpp ${F}
