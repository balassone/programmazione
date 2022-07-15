CC = g++
CFLAGS = -std=c++11 -Wall -pedantic
DEPS = Account.h
OBJ = Account.o testAccount.o

%.o : %.cpp $(DEPS)
	$(CC) -c $< $(CFLAGS)

testAccount : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)