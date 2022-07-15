// linkedQueue.h
#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H
#include <stdexcept>
#include <iostream>
#include "CLinkedList.h"
template <typename E>
class LinkedQueue { 						// queue as doubly linked list
public:
	LinkedQueue();							// constructor
	~LinkedQueue(){}
	LinkedQueue(const LinkedQueue<E> &lq);		//copy constructor
	LinkedQueue& operator=(const LinkedQueue<E> &lq);

	int size() const;						// number of items in the queue
	bool empty() const;						// is the queue empty?
	const E& front();						// the front element;
	void enqueue(const E& e);				// enqueue element at rear
	void dequeue(); 						// dequeue element at front
private:									// member data
	CircleList<E> C;						// circular list of elements
	int n;									// number of elements
};

#endif
#include "LinkedQueue.cpp"

	