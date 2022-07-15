//testQuickSort.cpp
#include<iostream>
#include"QuickSort.h"
using std::cout; 
int main(){
    vector<int> B ={5,3,2,6,4,1,3,7};
    cout<<"Vector:"<<endl;
    for (int i=0; i<B.size(); i++){
        cout<<B[i]<<"\t";
    }
    quickSort(B,0, B.size()-1);
    cout<<"\nSorted vector: "<<endl;
    for (int i=0; i<B.size(); i++){
        cout<<B[i]<<"\t";
    }
    cout<<std::endl;
}