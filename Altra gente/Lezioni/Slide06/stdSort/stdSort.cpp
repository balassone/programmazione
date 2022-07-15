//stdSort.cpp
//sorting with the standard algorithm library

#include <algorithm>
#include <array>
#include <iostream>

int main(){
    std::array<int, 10> s = {5,7,4,2, 8, 6, 1, 9, 0, 3};

    std::sort(s.begin(), s.end());
    for(auto a:s) {
        std::cout <<a << ' ';
    }
    std::cout << "\n";
    std::cout << "sorted with the default operator <\n";

    std::sort(s.begin(), s.end(), std::greater<int>());
    for( auto a : s) {
        std::cout << a <<' ';
    }
    std::cout << "\n";
    std::cout << "sorted with the standard library compare function object \n";
}