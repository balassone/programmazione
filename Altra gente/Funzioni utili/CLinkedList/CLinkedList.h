//CLinkedList.h
#ifndef CLINKED_LIST_H
#define CLINKED_LIST_H
#include <iostream>
#include "CNode.h"




template <typename T>
class CircleList { 				//a circularly linked list
friend bool operator==  (CircleList &lhs, CircleList &rhs) ;
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
	CircleList<T> reverseCopy();
	std::string toString() const ;
	int size();					//size of the CLinkedList;
    bool find(const T& e);
	const T& operator[](int i);	//takes the ith element of the list, first element is the cursor
private:
	CNode<T>* cursor;		//the cursor
};

#include "CLinkedList.cpp"

#endif
