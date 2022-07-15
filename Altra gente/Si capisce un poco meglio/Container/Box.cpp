//Box.cpp  - Box class implementation
#include"Box.h"
#include<sstream>
using std::string;
using std::istream;
using std::ofstream;
using std::ostringstream;

Box::Box (string& id, double peso, double valore, short int deteriorabile) {
    setBoxID(id);
    setWeight(peso);
    setValue(valore);
    setPerishable(deteriorabile);
}

void Box::setBoxID(string& id){
    box_id=id;   
}

string Box::getBoxID() const{
    return box_id;
}
    
void Box::setWeight(double peso){ 
    if (peso <=0.0){
        weight=1.0;
    }
    else{ 
        weight=peso;
    }
}

double Box::getWeight() const {
    return weight;
}

void Box::setValue(double valore){
    if (value<=0.0){
            value = 1.0;
    } 
    else value=valore;
}

double Box::getValue() const {
    return value;
}

void Box::setPerishable(short int deteriorabile) {
    if (deteriorabile!=0 || deteriorabile!=1){
        perishable=deteriorabile;
    }
    else deteriorabile=0;
}
    
short int Box::getPerishable() const {
    return perishable;
}   

string Box::toString(){
    ostringstream out;
    out<<"  Box: ";
	out<<"\n  Id box: "<< box_id;
	out<<"\n  Weigh: "<< weight;
	out<<"\n  Value: "<< value;
	out<<"\n  Perishable?(1=yes 0 = no): "<< perishable << "\n";
    return out.str();
}

istream& operator>>(istream& in, Box& b){
    in>>b.box_id>>b.weight>>b.value>>b.perishable;
    return in;
}
