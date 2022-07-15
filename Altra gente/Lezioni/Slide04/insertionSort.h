#include <iostream>

void insertionSort(int array[], int length) {
    for(int j = 0; j < length; j++){
        int key = array[j];
        int i=j;
        //inserisci numbers[j] in numbers [0,..., j-1]
        while (i > 0 && array[i-1] > key){
            array [i] = array [i-1];
            i--;
        }
        array[i] = key;
    }
}