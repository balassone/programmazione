#include <string>
#include "Programmatore.h"
#include <sstream>
Programmatore::Programmatore() : name{""}, cost{0} {}
Programmatore::Programmatore(const std::string& n, const double& c) : name{n}, cost{c} {}
Programmatore& Programmatore::setName(const std::string& n){
    name=n;
    return *this;
}
const std::string& Programmatore::getName() const{
    return name;
}
Programmatore& Programmatore::setCost(const double& c){
    cost=c;
    return *this;
}
const double& Programmatore::getCost() const{
    return cost;
}
bool Programmatore::operator<(const Programmatore& p){
    return cost<p.cost;
}

bool Programmatore::operator==(const Programmatore& p){
    return name==p.name && cost==p.cost;
}
std::string Programmatore::toString() const{
    std::ostringstream out;
    out << "Developer: " << name;
    out << "\nDev's Hourly Pricing: " << cost << "$";
    return out.str();
}