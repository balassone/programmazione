// arrayCompare.cpp
// demonstrates the array comparations

#include <iostream>
#include <array>
using std::cout;
using std::cin;
using std::array;

int main(){
    array<int,10> a1{1,2,3,4,5,6,7,8,9,10};
    array<int,10> a2{1,2,3,4,5,6,7,8,9,10};
    if(a1==a2)
        cout <<"a1 is equal to a2 \n";
    else 
        cout <<"Different \n";
    if(a1 <= a2)
        cout << "a1 is less then or equal to a2 \n";
    else
        cout <<"Different \n";

    a2[9] = 100;

    if(a1 < a2 )
        cout <<"a1 is less then a2 \n";
    else
        cout <<"Different \n";
    cout << a1[10] << "\n";
    cout    << a1.at(10) <<"\n";
}