CC=g++
CFLAGS=-std=c++11 -Wall -pedantic
DEPS=Account.h SavingsAccount.h CheckingAccount.h
OBJ=Account.o SavingsAccount.o CheckingAccount.o testAccount.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

testAccount: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)	

