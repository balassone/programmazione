#include <vector>
#include <string>
#include <sstream>
#ifndef BISCOTTO_H
#define BISCOTTO_H
class Biscotto{
    public:
        Biscotto() : ID{0}, nome{""}, produttore{""}, caratt{} {}
        Biscotto(const int& i, const std::string& n, const std::string& p, const std::vector<float>& c) : ID{i}, nome{n}, produttore{p}, caratt{c} {}
        Biscotto& setID(const int& i){ID=i; return *this;}
        const int& getID() const{return ID;}
        Biscotto& setNome(const std::string& n){nome=n; return *this;}
        const std::string& getNome() const{return nome;}
        Biscotto& setProd(const std::string& p){produttore=p; return *this;}
        const std::string& getProd() const{return produttore;}
        Biscotto& setCaratt(const std::vector<float>& c){
            caratt=c;
            return *this;
        }
        const std::vector<float> getCaratt() const{
            return caratt;
        }
        std::string toString(){
            std::ostringstream out;
            out << "ID: " << ID;
            out << "\nNome: " << nome;
            out << "\nProduttore: " << produttore;
            out << "\nColore: " << caratt[0];
            out << "\nPeso: " << caratt[1];
            out << "\nGrassi %: " << caratt[2];
            out << "\nProteine: " << caratt[3];
            out << "\nAltro: ";
            for(int i=4; i<10; ++i){
                out << caratt[i];
                if(i!=9){
                    out << " - ";
                }
            }
            out << "\n"<<"\n";
            return out.str();
        }

    private:
        int ID;
        std::string nome;
        std::string produttore;
        std::vector<float> caratt;
};
#endif