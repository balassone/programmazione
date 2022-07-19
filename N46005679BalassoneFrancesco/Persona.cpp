#include <string>
#include <sstream>
#include "Persona.h"

Persona::Persona(): id(0), name(""), surname(""), age(0) {}
Persona::Persona(const int& ID, const std::string& name, const std::string& surname, const std::string& ad, const int& age): id(ID), name(name), surname(surname) ,address(ad), age(age) {}
Persona& Persona::setID(const int& ID) {
    this->id = ID;
    return *this;
}
const int& Persona::getID() const {
    return id;
}
Persona& Persona::setName(const std::string& name) {
    this->name = name;
    return *this;
}
const std::string& Persona::getName() const {
    return name;
}
Persona& Persona::setSurname(const std::string& surname) {
    this->surname = surname;
    return *this;
}
const std::string& Persona::getSurname() const {
    return surname;
}
Persona& Persona::setAge(const int& age) {
    this->age = age;
    return *this;
}
Persona& Persona::setAddress(const std::string& address) {
    this->address = address;
    return *this;
}
const std::string& Persona::getAddress() const {
    return address;
}
const int& Persona::getAge() const {
    return age;
}

//overloading

std::ostream& operator<<(std::ostream& out, const Persona& p){
    out << "ID: " << p.id << "\nName: " << p.name << "\nSurname: " << p.surname << "\nAddress: " << p.address <<"\nAge: " << p.age;
    return out;
}