//min&max.cpp
#include<iostream>
#include<vector>
using std::cin; using std::cout; using std::endl;
using std::vector;

void insertionSort(vector<int>&);

int main(){
    vector<int> A;
    cout<<"Insert a series of numbers >0: i'll calculate maximum and minimum (0 to exit)"<<endl;
    unsigned int a=0;
    int i=0;
    do {
        cin>>a;
        A.push_back(a);
    } while (a!=0);

    int min =A[0];
    int max=A[0];
    for (int j=0; j<A.size()-1; j++){
        if (A[j]<min){
            min=A[j];
        }
        if (A[j]>max){
            max=A[j];
        }
    }
    cout<<"Max is "<<max<<"\nMin is "<<min<<endl;
}

