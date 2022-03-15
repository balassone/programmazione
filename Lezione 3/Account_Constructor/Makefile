GCC=g++

FLAGS=-std=c++11 -Wall -pedantic -Wextra

AccountC: AccountC.o
	${GCC} -o AccountC AccountC.o
AccountC.o: AccountC.cpp AccountC.h
	${GCC} -c AccountC.cpp ${FLAGS}
