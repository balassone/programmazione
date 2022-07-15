//testBST

#include "bst.h"

#include <iostream>


int main() {
	BST<int> T;
	T.insert(37);
	T.insert(24);
	T.insert(7);
	T.insert(3);
	T.insert(32);
	T.insert(42);
	T.insert(40);
	T.insert(45);
	T.insert(120);

	T.preOrderTreeWalk();
	BST<int> T2(T);
	T2.postOrderTreeWalk();
/*
	T.inOrderTreeWalk();
	T.deleteNode(10);
	T.inOrderTreeWalk();
	
	if(T.search(12)){
		cout << "\n value found into the tree";
	}
	else{cout << "\n the value is not in the tree";}

	if(T.searchRecursive(9)){
		cout << "\n value found into the tree";
	}
	else{cout << "\n the value is not in the tree";}

	if(T.searchRecursive(12)){
		cout << "\n value found into the tree";
	}
	else{cout << "\n the value is not in the tree \n";}
	T.insertRecursive(18);
	T.inOrderTreeWalk();
	*/
}