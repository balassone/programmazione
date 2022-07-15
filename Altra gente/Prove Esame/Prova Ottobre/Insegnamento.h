#ifndef STD_H
#define STD_H

#include <string>




class Insegnamento{
friend bool operator ==(const Insegnamento&lhs, const Insegnamento& rhs);
friend std::ostream& operator <<(std::ostream& out, const Insegnamento& ins);
    public:
    Insegnamento() : nome{""}, crediti{0}, docente{""} {}
    Insegnamento(const std::string& n, int cr, const std::string& doc);



    void setNome(const std::string& n);
    void setCrediti(const int cr);
    void setDocente(const std::string&);
    std::string getNome() const ;
    int getCrediti() const;
    std::string getDocente() const ; 
    std::string toString() const;

    private:
    std::string nome;
    int crediti;
    std::string docente;
};


#endif
