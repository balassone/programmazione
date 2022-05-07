C = g++
FLAGS = -g -std=c++11 -Wall -pedantic -Wextra
DEPS = Account.h SavingsAccount.h CheckingAccount.h
OBJ = Account.o SavingsAccount.o CheckingAccount.o driver.o

%.o: %.cpp ${DEPS}
	${C} -c -o $@ $< ${FLAGS}
driver: ${OBJ}
	${C} -o $@ $^ ${FLAGS}
