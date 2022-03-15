#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main(){

    float temp{0},newtemp{0};
    char scale{0};

    cout << "Temperatura: ";
    cin >> temp;

    cout << "Che scala e'?(C/F): ";
    cin>>scale;

    switch (scale)
    {
    case 'C':
        newtemp=temp*9/5+32;
        break;
    case 'F':
        newtemp=(temp-32)*5/9;
        break;
    default:
        cout << "Scala non valida!"<<endl;
        break;
    }
    char otherscale{scale=='C' ? 'F':'C'};

    cout << "La temperatura convertita e': "<<newtemp<<" "<<otherscale<<endl;

    return 0;
}