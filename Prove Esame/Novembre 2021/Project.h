#include "LinkedList.h"
#include "Task.h"
#include "Programmatore.h"
#include "Date.h"
#include <string>
#ifndef PROJECT_H
#define PROJECT_H

class Project{
    public:
        Project();
        Project(const std::string&, const std::string&, const float&, const Date&, const Date&, const LinkedList&);
        Project& setProjName(const std::string&);
        const std::string& getProjName() const;
        Project& setCommittent(const std::string&);
        const std::string& getCommittent() const;
        Project& setAmount(const float&);
        const float& getAmount() const;
        Project& setBegDate(const Date&);
        const Date& getBegDate() const;
        Project& setEndDate(const Date&);
        const Date& getEndDate() const;
        Project& setTasks(const LinkedList&);
        LinkedList& getTasks();
        std::string toString() const;
        Project& addTask(const Task&);
    private:
        std::string projname;
        std::string committent;
        float amount;
        Date beginning;
        Date ending;
        LinkedList tasks;
};

#endif