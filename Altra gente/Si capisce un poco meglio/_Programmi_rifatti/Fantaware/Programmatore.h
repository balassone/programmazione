//Programmatore.h

#ifndef PROGRAMMATORE_H
#define PROGRAMMATORE_H
#include"LinkedList.h"

class Progetto;

class Programmatore{
    
    public: 
        //constructor
        Programmatore(std::string =" ", double = 0.0, LinkedList<Progetto*> = LinkedList<Progetto*>());

        //set functions
        void setIDGeek(const std::string&);
        void setHourSalary(double);
        void setListOfProjects(const LinkedList<Progetto*>&);

        //get functions
        std::string getIDGeek() const;
        double getHourSalary() const;
        LinkedList<Progetto*> getList() const;
    private:
        std::string id_geek;
        double hour_salary;
        LinkedList<Progetto*> list_of_projects;
};

#endif