//InsertionSort
#include<vector>
#include<sstream>
using std::vector;

#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
/*
class InsertionSort {
    public:
        InsertionSort(vector<int>& numbers) : vettore(numbers){
            for (int j=1; j<numbers.size(); j++){
                int key=numbers[j];
                int i=j;
                while (i>0 && key<numbers[i-1]){
                    numbers[i]=numbers[i-1];
                    i--;
                }
                numbers[i]=key;
            }
            vettore=numbers;
        };
        std::string print(){
            std::ostringstream out;
            for(int i=0; i<vettore.size(); i++){
                out<<vettore[i]<<"\t";
            }
            return out.str();
        }
    private:
        vector<int> vettore;
};
*/
void insertionSort (vector<int>& numbers ){

for (int j=1; j<numbers.size(); j++){
    int key=numbers[j];
    int i=j;
    while (i>0 && key<numbers[i-1]){
        numbers[i]=numbers[i-1];
            i--;
        }
        numbers[i]=key;
    }
}
        std::string print(vector<int>& numbers){
            std::ostringstream out;
            for(int i=0; i<numbers.size(); i++){
                out<<numbers[i]<<"\t";
            }
            return out.str();
        }

#endif