#include <iostream>
#include <vector>


template<typename T>
void insertionSort(vector<T>&array) {
    for(int j = 0; j < array.size(); j++){
        T key = array[j];
        int i=j;
        //inserisci numbers[j] in numbers [0,..., j-1]
        while (i > 0 && array[i-1] > key){
            array [i] = array [i-1];
            i--;
        }
        array[i] = key;
    }
}