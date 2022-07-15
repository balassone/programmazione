//testLinkedQueue.cpp
#include <iostream>
#include <string>
#include "LinkedQueue.h"

int main(){
	LinkedQueue<int> Q;	
	Q.enqueue(1);
	Q.enqueue(2);
	Q.enqueue(3);
	LinkedQueue<int> Q2(Q);
	std::cout << Q.front() << std::endl;
	Q.dequeue();
	std::cout << Q.front() << std::endl;
	Q.dequeue();
	std::cout << Q.front() << std::endl;
	Q.dequeue();
	std::cout << Q.size();
	return 0;
}