#include "Piano.h"
#include <string>
#include <sstream>
Piano::Piano() : color{0}, woodtype{""}, supplier {""}, pricingsqm{0} {}
Piano::Piano(const int& c, const std::string& w, const std::string& s, const float& p) : color{c}, woodtype{w}, supplier{s}, pricingsqm{p} {}
void Piano::setColor(const int& c){
    color=c;
}
const int& Piano::getColor() const{
    return color;
}
void Piano::setWood(const std::string& w){
    woodtype=w;
}
const std::string& Piano::getWood() const{
    return woodtype;
}
void Piano::setSupplier(const std::string& s){
    supplier=s;
}
const std::string& Piano::getSupplier() const{
    return supplier;
}
void Piano::setPricing(const float& p){
    pricingsqm=p;
}
const float& Piano::getPricing() const{
    return pricingsqm;
}
bool Piano::operator<(const Piano& p){
    return (getArea()<p.getArea());
}
std::string Piano::toString() const{
    std::ostringstream out;
    out << "Colore: " << color;
    out << "\nLegno: " << woodtype;
    out << "\nFornitore: " << supplier;
    out << "\nPrezzo al metro quadro: " << pricingsqm << "\n";
    return out.str();
}
Rotondo::Rotondo() : Piano(), radius{0} {}
Rotondo::Rotondo(const int& c, const std::string& w, const std::string& s, const float& p, const float& r): Piano(c,w,s,p), radius{r} {}
void Rotondo::setRadius(const float& r){
    radius=r;
}
const float& Rotondo::getRadius() const{
    return radius;
}
float Rotondo::getArea() const {
    return (radius*radius*3.14);
}

std::string Rotondo::toString() const{
    std::ostringstream out;
    out << "Tipo: Rotondo\n" <<Piano::toString() << "Raggio: " << radius << "\n";
    return out.str();
}

Rettangolare::Rettangolare() : Piano(), base{0}, height{0} {}
Rettangolare::Rettangolare(const int& c, const std::string& w, const std::string& s, const float& p, const float& b, const float& h) : Piano(c,w,s,p), base{b}, height{h} {}
void Rettangolare::setBase(const float& b){
    base=b;
}
const float& Rettangolare::getBase() const{
    return base;
}
void Rettangolare::setHeight(const float& h){
    height=h;
}
const float& Rettangolare::getHeight() const{
    return height;
}
float Rettangolare::getArea() const{
    return base*height;
}
std::string Rettangolare::toString() const{
    std::ostringstream out;
    out << "Tipo: Rettangolare\n" <<Piano::toString() << "Base: " << base << "\nAltezza: " << height << "\n";
    return out.str();
}
Triangolare::Triangolare() : Piano(), base{0}, height{0} {}
Triangolare::Triangolare(const int& c, const std::string& w, const std::string& s, const float& p, const float& b, const float& h) : Piano(c,w,s,p), base{b}, height{h} {}
void Triangolare::setBase(const float& b){
    base=b;
}
const float& Triangolare::getBase() const{
    return base;
}
void Triangolare::setHeight(const float& h){
    height=h;
}
const float& Triangolare::getHeight() const{
    return height;
}
float Triangolare::getArea() const{
    return (base*height)/2;
}

std::string Triangolare::toString() const{
    std::ostringstream out;
    out << "Tipo: Triangolare\n" <<Piano::toString() << "Base: " << base << "\nAltezza: " << height << "\n";
    return out.str();
}