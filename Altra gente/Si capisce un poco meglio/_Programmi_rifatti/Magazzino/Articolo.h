//Articolo.h
 #include<string>
 #ifndef ARTICOLO_H
 #define ARTICOLO_H

class Articolo {
    public:
        Articolo(int=0, std::string="-", int=0, double=0.0);       //constructor

        //Set functions
        void setCodice(int);
        void setNome(std::string);
        void setQuantita(int);
        void setPrezzo(double);

        //Get functions
        int getCodice() const;
        std::string getNome() const;
        int getQuantita() const;
        double getPrezzo() const;



    private:
        int codice;
        char nome [20];
        int quantita;
        double prezzo;
};

 #endif