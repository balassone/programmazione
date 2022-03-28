GCC=g++

FLAGS= -std=c++11 -Wall -pedantic -Wextra

Account: Account.o
	${GCC} -o Account Account.o
Account.o: Account.cpp Account.h
	${GCC} -c Account.cpp ${FLAGS}
