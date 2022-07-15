Driver: Driver.o Account.o
	g++ -o Driver Driver.o Account.o
Driver.o: Driver.cpp Account.h
	g++ -c Driver.cpp -std=c++11 -pedantic -Wall
Account.o: Account.cpp Account.h
	g++ -c Account.cpp -std=c++11 -pedantic -Wall