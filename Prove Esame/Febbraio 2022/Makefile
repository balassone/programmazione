C=g++
FLAGS=-std=c++11 -Wall -pedantic -Wextra
DEPS=Piano.h Node.h LinkedList.h LinkedList.cpp 
OBJ=Piano.cpp driver.cpp
%.o: %.cpp ${DEPS}
	${C} -c -o $@ $< ${FLAGS}
driver: ${OBJ}
	${C} -o $@ $^ ${FLAGS}
