//Box.cpp
#include"Box.h"
using std::string;
using std::istream;
using std::ostream;

//constructor
Box::Box(const string& id, double peso, double valore, int perish) : 
box_id(id), perishable(perish) {
    setBoxWeight(peso);
    setBoxValue(valore);
}

//Set functions
void Box::setBoxID(const string& ID) {
    box_id= ID;
}

void Box::setBoxWeight(double wei) {
    if (wei<0){
        weight = 0.0;
    }
    else weight = wei;
}

void Box::setBoxValue(double val){
    if (val < 0.0) {
        value = 0.0;
    }
    else value = val;
}

void Box::setPerishable(int per){
    if (per == 0 || per == 1 ){
        perishable = per;
    }
    else throw std::invalid_argument("Perishable must be 0 or 1");
}

//Get functions
const string& Box::getBoxID() const {
    return box_id;
}

double Box::getBoxWeight() const {
    return weight;
}

double Box::getBoxValue() const {
    return value;
}

int Box::getPerishable() const {
    return perishable;
}

//overload >> for Box class
istream& operator>>(istream& in, Box& b){
    in>>b.box_id>>b.weight>>b.value>>b.perishable;
    return in;
}

//overloading << for Box class
ostream& operator<<(ostream& out, const Box& b){
    out<<"Box ID: "<<b.box_id
    <<"\nWeight of box: "<<b.weight
    <<"\nValue: "<<b.value
    <<"\nPerishable: "<<((b.getPerishable() == 1) ? "YES" : "NO");
    return out;
}


bool Box::operator==(const Box& b) const {
    return (b.box_id == box_id);
}

