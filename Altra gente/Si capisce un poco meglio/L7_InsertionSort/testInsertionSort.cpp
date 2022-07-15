//testInsertionSort.cpp
#include"InsertionSort.h"
#include<iostream>
using std::cout;

int main(){
    vector<int> vettore{1,3,5,4,3,7,6};
    insertionSort(vettore);
    cout<<print(vettore);
}