#ifndef DIZIONARIO_H
#define DIZIONARIO_H

#include <string>

class Dizionario{

public:
    Dizionario(const std::string& = "",const std::string& = "");
    //funzioni get e set
    void setParolaItaliana(const std::string&);
    void setParolaInglese(const std::string&);
    std::string getParolaItaliana() const;
    std::string getParolaInglese() const;

private:
    std::string parolaInglese;
    std::string parolaItaliana;
};

#endif