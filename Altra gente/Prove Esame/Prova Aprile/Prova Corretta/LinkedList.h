//LinkedList.h
//A generic LinkedList class template
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <iostream>



template<typename NODETYPE>
class LinkedList { 							// a singly linked list
	friend bool operator==(const LinkedList<NODETYPE> &lhs, const LinkedList<NODETYPE> &rhs);
	public:
		LinkedList();						//empty list constructor
		~LinkedList();						//destructor
		LinkedList(const LinkedList<NODETYPE> & lhs); 	// copy constructor;
	 	LinkedList<NODETYPE>& operator=(const LinkedList<NODETYPE> &lhs);
		bool empty() const;					//is list empty?
		const NODETYPE& front() const;			//return front element
		void addFront(const NODETYPE& e); 		//add to front of list
		void removeFront();						// remove front item list
		void reversal();						// reverse the LinkedList
		void print() const;							// print the element in the list
		void addBack(const NODETYPE& e); 		// add to back of the list
		int size() const; 							//gives the size of the LinkedList
		void add(const NODETYPE& e);
        bool find(const NODETYPE& e);
		const NODETYPE&	operator [](int i);		// returns the ith element of the list
		std::string toString() const;
	private:	
		Node<NODETYPE>* head; 				 //head of the list 
};

#include "LinkedList.cpp"

#endif

