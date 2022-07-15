#ifndef PRG_H
#define PRG_H

#include<string>
#include"Date.h"
#include"LinkedList.h"
#include "Programmatore.h"
using std::string;


class Progetto{
    public:
    Progetto() : nome{""}, committente{""}, importo{0.0}, datainizio(), datafinale(), task() {}
    Progetto(const string&n, const string&c, float i, const Date& di, const Date& df, const LinkedList& tsk) : nome{n} , committente{c}, importo{i}, datainizio{di}, datafinale{df}, task{tsk} {}
    ~Progetto(){}
    void setNome(const string& n){nome=n;}
    void setComm(const string& c){committente=c;};
    void setImporti(float i){importo=i;}
    void setDatainizio(const Date& di){datainizio=di;}
    void setDatafinale(const Date& df){datafinale=df;}

    string getNome()const{return nome;}
    string getComm()const{return committente;}
    float getImporti()const{return importo;}
    Date getDatainizio()const{return datainizio;}
    Date getDatafinale()const{return datafinale;}
    int size() {return task.size();}

    int workLoadDeveloper(const Programmatore& p){
        int workLoad{0};
        Node* i = task.head;
        while(i != nullptr){
            if(i->elemento.getProgrammatore() == p){
                workLoad += i->elemento.getOre();
            }
            i= i->next;
        }
        return workLoad;
    }
    void print(){std::cout << "print lista task \n";
    task.print();
    }



    private:
    string nome;
    string committente;
    float importo;
    Date datainizio;
    Date datafinale;
    LinkedList task;
};


#endif