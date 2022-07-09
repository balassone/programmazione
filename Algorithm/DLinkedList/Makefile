C=g++
F=-std=c++11 -Wall -pedantic -Wextra -g
DEPS=DNode.h DLinkedList.h DLinkedList.cpp
OBJ=driver.o

%.o: %.cpp $(DEPS)
	$(C) -c -o $@ $< $(FLAGS)
driver: $(OBJ)
	$(C) -o $@ $^ $(FLAGS)
