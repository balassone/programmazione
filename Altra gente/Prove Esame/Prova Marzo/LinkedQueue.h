// linkedQueue.h
#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H
#include <stdexcept>
#include <iostream>
#include "CLinkedList.h"
class Dottore;

template <typename E>
class LinkedQueue { 						// queue as doubly linked list
friend bool operator==(LinkedQueue<E> &lhs, LinkedQueue<E> & rhs);
public:
	LinkedQueue();							// constructotr
	~LinkedQueue(){}							// destructor
	LinkedQueue(const LinkedQueue<E> &q);			// copyConstructor
	LinkedQueue<E>& operator=(const LinkedQueue<E> &q);	//assign operator
	
	int size() const;						// number of items in the queue
	bool empty() const;						// is the queue empty?
	const E& front();						// the front element;
	void enqueue(const E& e);				// enqueue element at rear
	void dequeue(); 						// dequeue element at front
	std::string toString() const;		
private:									// member data
	CircleList<E> C;						// circular list of elements
	int n;									// number of elements
};


#include "LinkedQueue.cpp"
#endif

	