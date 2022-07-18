#ifndef NODE_H
#define NODE_H
class LinkedList;

class Node{
private:
	Node* next;
	int elem;
	friend class LinkedList;
};
#endif