#include "Task.h"
#include <string>
#include <sstream>
Task::Task() : taskname{""}, expiry(), whours(0), prog() {}
Task::Task(const std::string& t, const Date& e, const int& h, const Programmatore& p) : taskname{t}, expiry{e}, whours{h}, prog{p} {}
Task& Task::setName(const std::string& n){
    taskname=n;
    return *this;
}
const std::string& Task::getName() const{
    return taskname;
}
Task& Task::setDate(const Date& d){
    expiry=d;
    return *this;
}
const Date& Task::getDate() const{
    return expiry;
}
Task& Task::setWorkHours(const int& w){
    whours=w;
    return *this;
}
const int& Task::getWorkHours() const{
    return whours;
}
Task& Task::setDeveloper(const Programmatore& p){
    prog=p;
    return *this;
}
Programmatore Task::getDeveloper() const{
    return prog;
}
bool Task::operator<(const Task& t){
    return expiry<t.expiry;
}
std::string Task::toString() const{
    std::ostringstream out;
    out << "Task Name: " << taskname;
    out << "\nExpiry: " << expiry;
    out << "\nWorking hours: " << whours;
    out << "\n" <<prog.toString() << "\n";
    return out.str();
}