ciao: ciao.o
	g++ -o ciao ciao.o
ciao.o: ciao.cpp
	g++ -c -std=c++11 ciao.cpp