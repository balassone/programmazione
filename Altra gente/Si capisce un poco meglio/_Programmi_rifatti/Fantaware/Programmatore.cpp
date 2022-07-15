#include"Programmatore.h"

//constructor
Programmatore::Programmatore(std::string id, double salary, LinkedList<Progetto*> list)
: id_geek(id), list_of_projects(list)
{
    setHourSalary(salary);
}

//set functions
void Programmatore::setIDGeek(const std::string& id){
    id_geek=id;
}
void Programmatore::setHourSalary(double salary){
    if (salary>0.0){
        hour_salary=salary;
    }
    else (hour_salary=7.0);
}
void Programmatore::setListOfProjects(const LinkedList<Progetto*>& list) {
    list_of_projects=list;
}

//get functions
std::string Programmatore::getIDGeek() const {
    return  id_geek;
}

double Programmatore::getHourSalary() const {
    return hour_salary;
}

LinkedList<Progetto*> Programmatore::getList() const {
    return list_of_projects;
}