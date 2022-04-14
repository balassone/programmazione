#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int binSearch(const vector<int>&, int, int, int);

int main(){
	vector<int> V{};
	int elem;
	
	while(cin>>elem){
		if(V.size()==0){
			V.push_back(elem);
			continue;
		}
		if(binSearch(V,elem,0,V.size()-1)==-1){
			unsigned int i = V.size();
			while(i>0 && V[i-1]>elem){
				i--;
			}
			V.insert(V.begin()+i,elem);
		}

	}
	
	cout << "La dimensione e': " << V.size() << endl;
	
	for(int element : V){
		cout << element << " ";
	}

	return 0;
}

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



