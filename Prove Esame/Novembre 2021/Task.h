#include "Date.h"
#include "Programmatore.h"
#include <string>
#ifndef TASK_H
#define TASK_H
class Task{
    public:
        Task();
        Task(const std::string&, const Date&, const int&, const Programmatore&);
        Task& setName(const std::string&);
        const std::string& getName() const;
        Task& setDate(const Date&);
        const Date& getDate() const;
        Task& setWorkHours(const int&);
        const int& getWorkHours() const;
        Task& setDeveloper(const Programmatore&);
        Programmatore getDeveloper() const;
        bool operator<(const Task&);
        std::string toString() const;
    private:
        std::string taskname;
        Date expiry;
        int whours;
        Programmatore prog;
};
#endif