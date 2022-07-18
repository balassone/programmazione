#include <string>
#ifndef PROGRAMMATORE_H
#define PROGRAMMATORE_H
class Programmatore{
    public:
        Programmatore();
        Programmatore(const std::string&, const double&);
        Programmatore& setName(const std::string&);
        const std::string& getName() const;
        Programmatore& setCost(const double&);
        const double& getCost() const;
        bool operator<(const Programmatore&);
        bool operator==(const Programmatore&);
        std::string toString() const;
    private:
        std::string name;
        double cost;
};
#endif