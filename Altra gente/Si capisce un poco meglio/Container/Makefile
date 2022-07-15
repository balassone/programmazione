CC=g++
CFLAGS=-std=c++11 -Wall -pedantic
DEPS=Box.h Container.h
OBJ=Box.o Container.o main.o

%.o:%.cpp %$(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

