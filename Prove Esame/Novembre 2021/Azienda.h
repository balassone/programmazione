#include <string>
#include <vector>
#include "Programmatore.h"
#include "Task.h"
#include "Project.h"
#include "LinkedList.h"
#include <sstream>
#ifndef AZIENDA_H
#define AZIENDA_H
class Azienda{
    public:
        Azienda() : programmatori(), progetti() {}
        Azienda& addProgrammatore(const Programmatore& p){
            if(programmatori.size()==0){
                programmatori.push_back(p);
            } else {
                for(unsigned int i=0; i<programmatori.size(); i++){
                    if(programmatori[i].getCost()<p.getCost()){
                        programmatori.insert(programmatori.begin()+i, p);
                        break;
                    } else if(i==programmatori.size()-1){
                        programmatori.push_back(p);
                        break;
                    }
                }
            
            }
            return *this;
        }
        std::string printProgrammatori(){
            std::ostringstream out;
            for(Programmatore& p : programmatori){
                out << p.toString() << "\n";
            }
            return out.str();
        }
        Azienda& addProject(const Project& p){
            progetti.push_back(p);
            return *this;
        }
        int workLoadDeveloper(const Programmatore& p){
            int sum{0};
            for(unsigned int i=0; i<progetti.size(); ++i){
                for(int j=0; j<progetti[i].getTasks().size(); ++i){
                    if(progetti[i].getTasks()[j].getDeveloper()==p){
                        sum+=progetti[i].getTasks()[j].getWorkHours();
                    }
                }
            }
            return sum;
        }
    private:
        std::vector<Programmatore> programmatori;
        std::vector<Project> progetti;
};
#endif