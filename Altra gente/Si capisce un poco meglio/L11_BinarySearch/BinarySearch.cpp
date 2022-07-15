//BinarySearch.cpp
//ricerca binaria, si usa quando gli elementi sono ordinati
#include<vector>
#include<iostream>
using std::vector;
using std::cout; using std::cin; using std::endl;

template<typename T>
int binarySearch(vector<T>&, int);

int main(){
    vector<int> c={1,2,3,4,7,8, 12, 12, 56, 87};
    int numero{0};
    cout<<"Insert element to search in vector c:"<<endl;
    cin>>numero;
    int index = binarySearch(c,numero);
    if (index>=0){
        cout<<"Element found in position "<<index<<endl;
    }
    else {
        cout<<"Number not found"<<endl;
    }
}

template<typename T>
int binarySearch(vector<T>& A, int num){
    int n=A.size();
    int left=0;
    int right=n-1;
    int mid;
    while (left<=right){
        mid=(left+right)/2;
        if (num == A[mid]){
            return mid;
        }
        if (A[mid]<num){
            left=mid+1;
        }
        else right=mid-1;
    }
    return -1;
}