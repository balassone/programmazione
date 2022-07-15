//DLinkedList.h
#include "DNode.h"
#include <iostream>
template <typename T>
class DLinkedList {					// doubly linked list
public:
	DLinkedList();					// constructor
	~DLinkedList();					// destructor
	bool empty() const; 				// is list empty?
	const T& front() const;				// get front element
	const T& back() const;				// get back element
	void addFront(const T& e); 			// add to front of the list
	void addBack(const T& e); 			// add to back of the list
	void removeFront();				//remove from front
	void removeBack();				// remove from back
	std::string toString();
private:						// local type definitions
	DNode<T>* header;				// list sentinels
	DNode<T>* trailer;
protected:						// local utilites
	void add(DNode<T>* v, const T& e); 		// insert new node before v
	void remove(DNode<T>* v); 			// remove node v				
};

#include "DLinkedList.cpp"
