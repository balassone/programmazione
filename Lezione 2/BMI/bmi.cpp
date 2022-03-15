#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    float peso{0}, altezza{0};
    
    cout << "Altezza in m: " << endl;
    cin >> altezza;
    cout << "Peso in kg: " << endl;
    cin >> peso;

    float bmi{peso/(altezza*altezza)};

    cout << "BMI: "<<bmi<<endl;

    return 0;
}