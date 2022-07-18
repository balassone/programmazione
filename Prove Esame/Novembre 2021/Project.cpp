#include "Project.h"
#include <sstream>
Project::Project() : projname{""}, committent{""}, amount{0}, beginning(), ending(), tasks() {}
Project::Project(const std::string& n, const std::string& c, const float& a, const Date& b, const Date& e, const LinkedList& t) : projname{n}, committent{c}, amount{a}, beginning{b}, ending{e}, tasks{t} {}
Project& Project::setProjName(const std::string& n){
    projname=n;
    return *this;
}
const std::string& Project::getProjName() const{
    return projname;
}
Project& Project::setCommittent(const std::string& c){
    committent=c;
    return *this;
}
const std::string& Project::getCommittent() const{
    return committent;
}
Project& Project::setAmount(const float& a){
    amount=a;
    return *this;
}
const float& Project::getAmount() const{
    return amount;
}
Project& Project::setBegDate(const Date& b){
    beginning=b;
    return *this;
}
const Date& Project::getBegDate() const{
    return beginning;
}
Project& Project::setEndDate(const Date& e){
    ending=e;
    return *this;
}
const Date& Project::getEndDate() const{
    return ending;
}
Project& Project::setTasks(const LinkedList& l){
    tasks=l;
    return *this;
}
LinkedList& Project::getTasks(){
    return tasks;
}
std::string Project::toString() const{
    std::ostringstream out;
    out << "Progetto: " << projname;
    out << "\nCommittente: " << committent;
    out << "\nPrezzo: " << amount;
    out << "\nInizio: " << beginning;
    out << "\nFine: " << ending;
    out << "\nTasks da effettuare: " << tasks.toString() << "\n";
    return out.str();
}
Project& Project::addTask(const Task& t){
    tasks.addOrder(t);
    return *this;
}