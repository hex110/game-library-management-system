#include <bits/stdc++.h>
#include "cont.h"

class Admin : public Cont{
public:
    Admin(const char* numeUtilizator = "", const char* parola = "",
               Librarie librarie = Librarie(), Magazin magazin = Magazin()) : 
        Cont(numeUtilizator, parola, librarie, magazin) {};

    ~Admin() {
        delete[] numeUtilizator;
        delete[] parola;
    }

    //metode override
    void detaliiCont() override {
        std::cout<<"Cont cu status de ADMINISTRATOR\n";
        std::cout<<"Nume utilizator: "<<numeUtilizator<<"\n";
    }

    void modificareParola() override; //todo
    void autentificare() override; //todo

    void afiseazaJocuriLibrarie() override {
        std::cout<<"Ca si admin, aveti acces la toate jocurile disponibile.\n";
        librarie.afiseazaJocuriSumar();
    }
    void afiseazaJocuriMagazin() override {
        std::cout<<"Ca si admin, aveti deja acces la toate jocurile disponibile\n";
    }

    //metode specifice

    void schimbaDetaliiJoc(); //todo
    void adaugaJocMagazin(); //todo
    void stergeJocMagazin(); //todo
    void blocheazaCont(); //todo
    
};