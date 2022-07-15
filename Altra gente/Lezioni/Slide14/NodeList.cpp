//NodeList.cpp

template <typename T>
NodeList<T>::Iterator::Iterator(Node* u) //constructor from Node*
	{ v = u; }
template <typename T>
T& NodeList<T>::Iterator::operator*() // reference to the element
	{return v->elem;}


// compare positions

template <typename T>
bool NodeList<T>::Iterator::operator==(const Iterator& p) const
	{ return v==p.v; }

template <typename T>
bool NodeList<T>::Iterator::operator!=(const Iterator& p) const 
	{ return  v!= p.v; }

//move to next position
template <typename T>
typename NodeList<T>::Iterator& NodeList<T>::Iterator::operator++()
	{ v = v->next; return *this; }

// move to previous position
template <typename T>
typename NodeList<T>::Iterator& NodeList<T>::Iterator::operator--()
	{ v = v->prev; return *this; }

// NodeList member functions
template <typename T>
NodeList<T>::NodeList() {						// constructor
	n = 0;
	header = new Node;
	trailer = new Node;
	header->next = trailer;
	trailer->prev = header;
}

template <typename T>
int NodeList<T>::size() const 					// list size
	{return n;}

template <typename T>
bool NodeList<T>::empty() const					// is the list empty?	
	{ return(n == 0); }
	
	
// begin position is first item
template <typename T>
typename NodeList<T>::Iterator NodeList<T>::begin() const 
	{ return Iterator(header->next); }

// end position is just beyond last
template <typename T>
typename NodeList<T>::Iterator NodeList<T>::end() const 
	{return Iterator(trailer) ; }

//insert
template <typename T>
void NodeList<T>::insert(const NodeList::Iterator& p, const T& e) {
//insert e before p
	Node* w = p.v;							// p's node
	Node* u = w->prev;						// p's predecessor
	Node* v = new Node;						// new node to insert
	v->elem = e;
	v->next = w;	w->prev = v;			// link in v before w
	v->prev = u; 	u->next = v;			// link in v after u
	n++;	
}

template <typename T>
void NodeList<T>::insertFront(const T& e)		//insert at front
	{insert(begin(), e); }

template <typename T>
void NodeList>T>::insertBack(const T& e)		//insert at rear
	{insert(end(), e); }

//erase
template <typename T>
void NodeList<T>::erase(const Iterator& p) {	// remove p
	Node* v = p.v;								// node to remove
	Node* w = v->next;							//successor
	Node* u = v->prev;							// predecessor
	u->next = w; 	w->prev = u;				// unlink p
	delete v;									// delete this node
	n--;										// one fewer element
}

template <typename T>
void NodeList<T>::eraseFront()					// remove first
	{erase(begin());}

template <typename T>
void NodeList<T>::eraseBack()					// remove last
	{erase(--end());}