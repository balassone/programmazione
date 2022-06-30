#include <iostream>
#include "Motor.h"
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){
    MotorVehicle macchina{"Audi", "Diesel", 2022, "Rosso", 900};
    macchina.displayCarDetails();
    return 0;
}
