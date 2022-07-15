//CLinkedList.h
#ifndef CLINKED_LIST_H
#define CLINKED_LIST_H

#include <iostream>
#include "CNode.h"
template <typename T>
class CircleList { 			//a circularly linked list
public:
	CircleList();			//constructor
	~CircleList();			//destructor
	bool empty() const;		//is list empty?
	const T& front() const;	//element at cursor
	const T& back() const; 	//element following cursor
	void advance();			// advance cursor
	void add(const T& e);	// add after cursor
	void remove();			// remove node after cursor
	std::string toString();
private:
	CNode<T>* cursor;		//the cursor
};

#include "CLinkedList.cpp"

#endif