C=g++
O=bmi.o
FLAGS=-std=c++11 -Wall -pedantic -Wextra -g

%.o: %.cpp
	${C} -c -o $@ $< ${FLAGS}

bmi: ${O}
	${C} -o $@ $^ ${FLAGS}	
