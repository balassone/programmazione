//DlinkedList.cpp
#include <iostream>
#include <sstream>
template <typename T>
DLinkedList<T>::DLinkedList() { 				//constructor
	header = new DNode<T>;					//create sentinels
	trailer = new DNode<T>;
	header->next = trailer;					//have them pointed to each other
	header->prev = nullptr;
	trailer->prev = header;
	trailer->next = nullptr;
}

template <typename T>
DLinkedList<T>::~DLinkedList() { 				//destrtuctor
	while(!empty()) removeFront();				//remove all but sentinels
	delete header;						//remove sentinels
	delete trailer;
}

template <typename T>
bool DLinkedList<T>::empty() const { 				//is list empty
	return( header->next == trailer);
}

template <typename T> 
const T& DLinkedList<T>::front () const { 			//get front element
	return header->next->elem;
}

template <typename T>
const T& DLinkedList<T>::back() const {				//get back element
return trailer->prev->elem;
}

// deleting a node

template <typename T>
void DLinkedList<T>::remove (DNode<T> *v){ 			// remove node v
	if(empty()){
		throw std::runtime_error("the list is empty");
	}
	DNode<T>* u = v->prev;					//predecessor
	DNode<T>* w = v->next;					//successor
	u->next = w; 						// unlink v from list
	w->prev = u;
	delete v;
}

template <typename T>
void DLinkedList<T>::removeFront() {				//remove from front
	remove(header->next);
}

template <typename T>						//remove from back
void DLinkedList<T>::removeBack() {
	remove(trailer->prev);
}

//add in a DLinkedList

template <typename T>
void DLinkedList<T>::add(DNode<T>*v, const T& e) {
	DNode <T>* u = new DNode<T>; 
	u->elem = e; 						// create a new node for e
	u->next = v; 						// link u in between v
	u->prev = v->prev;					// ... and v-> prev
	v->prev->next = u;
	v->prev = u;
} 

template <typename T>
void DLinkedList<T>::addFront(const T& e) {			// add to front of list
	add(header->next, e);
}

template <typename T>
void DLinkedList<T>::addBack(const T& e) { 			// add to back of list
	add(trailer, e);
}


//print the list
template <typename T>
std::string DLinkedList<T>::toString() {
	std::ostringstream out;
	DNode<T>* u= header->next;
	out << "Header <--> ";
	while (u!=trailer) {
		out << u->elem << " <--> ";
		u=u->next;
	}
	out << "Trailer";
	return out.str();
}
template<typename T>
int DLinkedList<T>::size()const{
	DNode<T> *i = header->next;
	int count = 0;
	while(i != trailer){
		count++;
		i = i->next;
	}
	return count;	
}
template<typename T>
T& DLinkedList<T>::operator[](int i)const{
	DNode<T> *l = header->next;
	int j = 0;
	while(l != trailer && j<i){
		j++;
		l = l->next;
	}
	return l->elem;	
}
template<typename T>
DLinkedList<T>::DLinkedList(const DLinkedList<T> & dl){
	header = new DNode<T>;					
	trailer = new DNode<T>;
	header->next = trailer;					
	header->prev = nullptr;
	trailer->prev = header;
	trailer->next = nullptr;
	DNode<T>* t = dl.trailer->prev;
	while(t != dl.header){
		addFront(t->elem);
		t = t->prev;
	}

}

template<typename T>
bool operator ==(const DLinkedList<T> & lhs, const DLinkedList<T> & rhs){
	if (lhs.size() == rhs.size())
	{
		for(int i = 0; i<lhs.size(); i++){
			if(lhs[i] != rhs[i]) return false;
		}
		return true;
	}
	else return false;
}

template<typename T>
DLinkedList<T>& DLinkedList<T>::operator=(const DLinkedList<T> &dl){
	if(!(&dl==this)){
		header = new DNode<T>;					
		trailer = new DNode<T>;
		header->next = trailer;					
		header->prev = nullptr;
		trailer->prev = header;
		trailer->next = nullptr;
		DNode<T>* t = dl.trailer->prev;
		while(t != dl.header){
			addFront(t->elem);
			t = t->prev;
		}
	}
}
template<typename T>
void DLinkedList<T>::reversal()
{	if(header != nullptr)
	{
		DLinkedList<T> temp = *this;
		while(!(empty()))removeFront();
		for (int i = 0; i < temp.size(); i++)
		{
			addFront(temp[i]);
		}
	}
}

template<typename T>
bool DLinkedList<T>::find(const T&e){
    DNode<T>* v = header->next;
    while(v != trailer){
        if(v->elem == e){
            return true;
        }
        v=v->next;
    }
    return false;
}

template <typename T>
void DLinkedList<T>::addOrder(const T& e){
	DNode<T>* u = header->next;
	while(u!= trailer){
		if(e < u->elem) break;
		u = u->next;
	}
	add(u,e);
}
