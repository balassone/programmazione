//CLinkedList.h
#ifndef CLINKED_LIST_H
#define CLINKED_LIST_H
#include <iostream>
#include "CNode.h"


template <typename T>
bool operator ==  (CircleList<T> &lhs, CircleList<T> &rhs);


template <typename T>
class CircleList { 				//a circularly linked list
friend bool operator== <> (CircleList<T> &lhs, CircleList<T> &rhs) ;
public:
	CircleList();				//constructor
	~CircleList();				//destructor
	CircleList(const CircleList&cl ); //copyConstructor
	CircleList&operator = (const CircleList<T>& cl);		//assignment operator
	bool empty() const;			//is list empty?
	const T& front() const;		//element at cursor
	const T& back() const; 		//element following cursor
	void advance();				// advance cursor
	void add(const T& e);		// add after cursor
	void addBack(const T& e );
	void remove();				// remove node after cursor
	void reverse();				//reverse the clinkedlist
	std::string toString();
	int size();					//size of the CLinkedList;
	const T& operator[](int i);	//takes the ith element of the list, first element is the cursor
	bool find(const T&e);
private:
	CNode<T>* cursor;		//the cursor
};

#include "CLinkedList.cpp"

#endif