#include "Node.h"
#include <iostream>
#include <string>
template <typename NODETYPE>
class LinkedList {
	public:
		LinkedList();
		~LinkedList();
		LinkedList(const LinkedList<NODETYPE>&);
		LinkedList<NODETYPE>& operator=(const LinkedList<NODETYPE>&);
		bool empty() const;
		const NODETYPE& front() const;
		void addFront(const NODETYPE& e);
		void removeFront();
		int size() const;
		const NODETYPE& operator[](const int&);
		int search(const NODETYPE&) const;
		void deleteNode(const NODETYPE&);
		std::string toString() const;
		LinkedList& reverse();
	private:
		Node<NODETYPE>* head;
};

#include "LinkedList.cpp"
