// max.cpp
//Use of templates
#include <iostream>

template <typename T>
const T& max (const T& x, const T& y) {
    return (x > y)? x:y;
}

int main(){
    int i = max(3,7);
    std::cout << i << '\n';

    double d = max(6.34, 18.523); 
    std::cout << d << '\n';

    char ch = max('a' , '6');
    std::cout << ch << '\n';

    return 0; 
}