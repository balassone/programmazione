//LinkedDeque.cpp
template <typename T>
void LinkedDeque<T>::insertFront(const T& e) {	//insert new first element
	D.addFront(e);
	n++;
}

template <typename T>
void LinkedDeque<T>::insertBack(const T& e) { 	// insert new last element
	D.addBack(e);
	n++;
}

void LinkedDeque::removeFront() { 				// remove first element
	if(empty())
		throw std::runtime_error("deque empty");
	D.removeFront();
	n--;
}

void LinkedDeque::removeBack() {				// remove last element
	if(empty())
		throw std::runtime_error("deque empty");
	D.removeBack();
	n--;
}

