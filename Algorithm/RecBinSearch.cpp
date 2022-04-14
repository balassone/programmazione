#include <iostream>
#include <vector>
using std::vector;
int binSearch(const vector<int>& myVec,int elem, int inf, int sup){
	int p,q=-1;
	if(inf<=sup){
		p=(inf+sup)/2;
		if (myVec[p]>elem){
			q=binSearch(myVec, elem, inf, p-1);
		}
		if (myVec[p]<elem){
			q=binSearch(myVec, elem, p+1,sup);
		}
		if (myVec[p]==elem){
			return p;
		}
	}
	return q;
}
