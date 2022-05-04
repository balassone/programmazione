CC=g++
CFLAGS=-g -Wall -pedantic -Wextra -std=c++11
DEPS=Publication.h Book.h quicksort.h Article.h Convegni.h
OBJ=driver.o Publication.o Book.o Article.o Convegni.o

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)
driver: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)	
