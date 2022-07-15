transactionProcessing: transactionProcessing.o ClientData.o
	g++ -o transactionProcessing transactionProcessing.o ClientData.o 
transactionProcessing.o: transactionProcessing.cpp ClientData.h
	g++ -c transactionProcessing.cpp -std=c++11 -Wall -pedantic
ClientData.o:ClientData.cpp ClientData.h
	g++ -c ClientData.cpp -std=c++11 -Wall -pedantic