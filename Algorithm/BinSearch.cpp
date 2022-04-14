#include <vector>

using std::vector;

int binSearch(const vector<int> myVec, int elem){
	int inf=0;
	int sup=myVec.size()-1;
	while(inf<=sup){
		int k=(inf+sup)/2;
		if(myVec[k]==elem)
			return k;
		else if(myVec[k]>elem)
			sup=k-1;
		else if(myVec[k]<elem)
			inf=k+1;
	}
	return -1;
}
