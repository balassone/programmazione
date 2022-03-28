E3: E3.o
	g++ -o E3 E3.o -g
E3.o: E3.cpp
	g++ -c E3.cpp -Wall -pedantic -Wextra
