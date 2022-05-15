C=g++
F=-std=c++11 -Wall -pedantic -Wextra -g
DEPS=Node.h LinkedList.h LinkedList.cpp
OBJ=driver.cpp

%.o: %.cpp $(DEPS)
	$(C) -c -o $@ $< $(FLAGS)
driver: $(OBJ)
	$(C) -o $@ $^ $(FLAGS)
