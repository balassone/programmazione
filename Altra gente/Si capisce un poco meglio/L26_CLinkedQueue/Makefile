CC = g++
CFLAGS = -std=c++11
DEPS = CNode.h CircleLinkedList.h CircleLinkedList.cpp LinkedQueue.h LinkedQueue.cpp
OBJ= testLinkedQueue.o 

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
testLinkedQueue : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
