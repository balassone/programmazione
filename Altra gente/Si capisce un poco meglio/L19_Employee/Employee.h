//Employee.h
//Employee abstract class
#ifndef EMPLOYEE_H //guardie di inclusione
#define EMPLOYEE_H //guardie di inclusione
#include<string>

class Employee {
    public:
        Employee (const std::string&, const std::string&, const std::string&);
        virtual ~Employee()=default; //compiler generates default destructor

        void setFirstName (const std::string&);
        std::string getFirstName() const;

        void setLastName (const std::string&);
        std::string getLastName() const;

        void setSocialSecurityNumber (const std::string&);
        std::string getSocialSecurityNumber() const;

        //pure virtual function makes Employee an abstract class
        virtual double earnings() const=0; //funzione pure virtual, calcolo dello stipendio 
        virtual std::string toString() const; //funzione virtual, visualizzazione dell'impiegato 

    private:
        std::string firstName;
        std::string lastName;
        std::string SocialSecurityNumber;        
};

#endif //guardie di inclusione