#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(){

    int age{0}, MHR{0}, MHR_2{0}, MHR_3{0}, MHR_4{0};
    cout << "How old are you? ";
    cin >> age;

    MHR=220-age;
    MHR_2=208-(0.7*age);
    MHR_3=207-(0.7*age);
    MHR_4=211-(0.64*age);

    int max{MHR}, min{MHR};
    max=max<MHR_2 ? MHR_2:max;
    max=max<MHR_3 ? MHR_3:max;
    max=max<MHR_4 ? MHR_4:max;

    min=min>MHR_2 ? MHR_2:min;
    min=min>MHR_3 ? MHR_3:min;
    min=min>MHR_4 ? MHR_4:min;

    cout << "Hrate Range is between "<<min<<" and "<<max<<endl;

    return 0;
}