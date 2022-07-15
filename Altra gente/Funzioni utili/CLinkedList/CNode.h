//CNode.h

template <typename T> class CircleList; 	//forward declaration
template <typename T> 						//element type
class CNode {								//Circulaly linked list node
private:
	T elem;									// linked list element value
	CNode* next;							// next item in the list
	friend class CircleList<T>;				//provide CircleList access
};
