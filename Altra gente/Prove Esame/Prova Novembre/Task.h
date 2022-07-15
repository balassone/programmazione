#ifndef TSK_H
#define TSK_H

#include<string>
#include"Date.h"
#include"Programmatore.h"
#include<sstream>

using std::string;
using std::ostringstream;



class Task{
    public:
    Task() : nomeT{""}, datascadenza(), ore{0} {p = nullptr;}
    Task(Programmatore& pr, const string& s, const Date& ds, int wo)
     : nomeT{s}, datascadenza(ds), ore{wo}{this->p = &pr;}
    ~Task(){
    }
    Task& operator = (const Task&rhs){
        nomeT = rhs.nomeT;
        datascadenza = rhs.datascadenza;
        ore = rhs.ore;
        p = rhs.p;
        return *this;
    }
    void setNomeT(string& t){nomeT=t;}
    void setDataSca(Date& dd){datascadenza=dd;}
    void setOre(int o){ore=o;}

    void setProgrammatore(Programmatore& pr){p=&pr;}

    bool operator>(const Task& t){
        if(this->getDataSca()>t.getDataSca()){
            return true;
        } else {
            return false;
        }   
    }

    bool operator>=(const Task& t){
        if(this->getDataSca()>=t.getDataSca()){
            return true;
        } else {
            return false;
        }   
    }

    bool operator<(const Task& t){
        if(this->getDataSca()<t.getDataSca()){
            return true;
        } else {
            return false;
        }   
    }

    string getNomeT()const{return nomeT;}
    Date getDataSca()const{return datascadenza;}
    int getOre()const{return ore;}
    Programmatore& getProgrammatore()const{
        return *p;
    }
    
    private:
    string nomeT;
    Date datascadenza;
    int ore;
    Programmatore* p;


};

#endif