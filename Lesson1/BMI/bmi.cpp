#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::fixed;

int main(){
    float h{0},w{0},bmi{0};
    cout << "Inserire altezza e peso: ";
    cin >> h >> w;
    bmi=w/(h*h);
    cout << fixed << setprecision(2);
    cout << "BMI: " << bmi << endl;

    return 0;
}