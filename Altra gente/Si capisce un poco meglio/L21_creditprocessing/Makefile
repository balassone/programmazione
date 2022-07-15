creditProcessing: creditProcessing.o ClientData.o
	g++ -o creditProcessing creditProcessing.o ClientData.o
creditProcessing.o: creditProcessing.cpp ClientData.h
	g++ -c creditProcessing.cpp -std=c++11 -Wall -pedantic
ClientData.o: ClientData.cpp ClientData.h
	g++ -c ClientData.cpp -std=c++11 -Wall -pedantic