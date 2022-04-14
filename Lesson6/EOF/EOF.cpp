#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int binSearch(const vector<int>&, int, int, int, bool&);

int main(){
	vector<int> V{};
	int elem;
	
	while(cin>>elem){
		if(V.size()==0){
			V.push_back(elem);
			continue;
		}
		bool found{false};
		int k = binSearch(V,elem, 0, V.size()-1, found);
		if(!found){
			V.insert(V.begin()+k,elem);
		}

	}
	
	cout << "La dimensione e': " << V.size() << endl;
	
	for(int element : V){
		cout << element << " ";
	}

	return 0;
}

int binSearch(const vector<int>& myVec,int elem, int inf, int sup, bool& found){
	int p,q=-1;
	if(inf<sup){
		p=(inf+sup)/2;
		if (myVec[p]>elem){
			q=binSearch(myVec, elem, inf, p-1, found);
		}
		if (myVec[p]<elem){
			q=binSearch(myVec, elem, p+1,sup, found);
		}
		if (myVec[p]==elem){
			return p;
			found=true;
		}
	}
	if(sup<=inf && myVec[inf]<elem)
		return inf+1;
	else if (sup<=inf && myVec[inf]>elem){
		return inf;
	}	
	return q;	
}



