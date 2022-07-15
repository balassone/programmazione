//InsertionSort.h
#include<iostream>
#include<vector>
using std::vector;
using std::cout;
void insertionSort(vector<int>&);

int main() {
    vector<int> vettore={1,2,4,5,3,6,4,8,9,7};
    insertionSort(vettore);
    for (int i=0; i<vettore.size(); i++){
        cout<<vettore[i]<<" ";
    }
    cout<<std::endl;
    
}

void insertionSort(vector<int>& A){
    int key{0};
    int i{0};
    for (int j=1; j<A.size(); j++){
        key = A[j];
        i=j;
        while (i>0 && key<A[i-1]){
            A[i]=A[i-1];
            i--;
        }
        A[i]=key;
    }
}