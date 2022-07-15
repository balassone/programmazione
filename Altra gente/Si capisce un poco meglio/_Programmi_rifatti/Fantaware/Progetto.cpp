//Progetto.cpp
#include"Progetto.h"
Progetto::Progetto(std::string id, std::string name, double amount, Date delivery, LinkedList<Programmatore*> list)
: id_project(id), project_name(name), delivery_date(delivery), list_of_geeks{list}
{
    setTotalAmount(amount);
}

//set functions

void Progetto::setIDProject(const std::string& id){
    id_project=id;
}

void Progetto::setProjectName(const std::string& name){
    project_name=name;
}

void Progetto::setTotalAmount(double am){
    if (am >= 0) {
        total_amount=am;
    }
    else total_amount = 0.0;
}

void Progetto::setDate(const Date& d){
    delivery_date=d;
}

void Progetto::setListOfGeeks(const LinkedList<Programmatore*>& list){
    list_of_geeks = list;
}

//get functions
std::string Progetto::getIDProject() const{
    return id_project;
}
std::string Progetto::getProjectName() const{
    return project_name;
}
double Progetto::getTotalAmount() const{
    return total_amount;
}
Date Progetto::getDate() const{
    return delivery_date;
}
LinkedList<Programmatore*> Progetto::getListOfGeeks() const{
    return list_of_geeks;
}