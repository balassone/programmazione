//Progetto.h
#ifndef PROGETTO_H
#define PROGETTO_H
#include <string>
#include "Programmatore.h"
#include "Date.h"
#include <iostream>

class Programmatore;

class Progetto {
    public:
        //constructor
        Progetto(std::string = " ", std::string = " ", double = 0.0, Date = Date(), LinkedList<Programmatore*> = LinkedList<Programmatore*>());
        
        //set functions
        void setIDProject(const std::string&);
        void setProjectName(const std::string&);
        void setTotalAmount(double);
        void setDate(const Date&);
        void setListOfGeeks(const LinkedList<Programmatore*>&);

        //get functions
        std::string getIDProject() const;
        std::string getProjectName() const;
        double getTotalAmount() const;
        Date getDate() const;
        LinkedList<Programmatore*> getListOfGeeks() const;


    private:
        std::string id_project;
        std::string project_name;
        double total_amount;
        Date delivery_date;
        LinkedList<Programmatore*> list_of_geeks;
        


};

#endif