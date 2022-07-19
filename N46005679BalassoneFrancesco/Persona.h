#include <string>
#include <sstream>
//Include guard
#ifndef PERSONA_H
#define PERSONA_H
class Persona {
    friend std::ostream& operator<<(std::ostream&, const Persona&); //Overloading operatore <<
    public:
        //Set&Get basiche, non ci sono manipolazioni di strutture dinamiche, non ci preoccupiamo di deep/shallow copy
        //Persona& tipo di ritorno per effettuare operazioni a cascata.
        Persona();
        Persona(const int&, const std::string&, const std::string&, const std::string&, const int&);
        Persona& setID(const int&);
        const int& getID() const;
        Persona& setName(const std::string&);
        const std::string& getName() const;
        Persona& setSurname(const std::string&);
        const std::string& getSurname() const;
        Persona& setAddress(const std::string& address);
        const std::string& getAddress() const;
        Persona& setAge(const int&);
        const int& getAge() const;
    private:
        int id;
        std::string name;
        std::string surname;
        std::string address;
        int age;
};
#endif