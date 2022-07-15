//NodeList.h
template <typename T>
class NodeList {						// node-based list
private:
	// Node declaration
	class Node { 						// a node of the list
		friend class NodeList<T>;
	private:
		T elem;							// element value
		Node* prev;						// previous in list
		Node* next;						// next in list
		};
public:
	class Iterator{					// an iterator for the list
	public:
		T& operator*();				// reference to the element
		bool operator==(const Iterator& p) const; // compare positions
		bool operator!=(const Iterator& p) const;
		Iterator& operator++();		// move to next position
		Iterator& operator--();		// move to previous position
		friend class NodeList<T>;
	private:
		Node* v;					// pointer to teh nde
		Iterator(Node* u); 			// create from node
	};
public:
	NodeList();							// default constructor
	int size() const;					// list size
	bool empty() const;					// is the list empty?
	Iterator begin() const;				// beginning position
	Iterator end() const;			// (just beyond) last position
	void insertFront(const T& e);		// insert at front
	void insertBack(const T& e);		// indert at rear
	void insert(const Iterator& p, const T& e);	// insert e before p
	void eraseFront();					// remove first
	void eraseBack();					// remove last
	void erase(const Iterator& p);		// remove p
	// housekeeping funcions omitted...
private:								// data menbers		
	int n;								// number of items
	Node* header;						// head-of-list sentinel
	Node* trailer;						// tail-of-list sentinel
};

#include "NodeList.cpp"
