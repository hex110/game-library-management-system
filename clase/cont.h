#include <bits/stdc++.h>
#include "librarie.h"
#include "magazin.h"

class Cont{
private:
    char* numeUtilizator;
    double bani;
    Librarie librarie;
    Magazin magazin;

public:
    Cont(const char* numeUtilizator = "", double bani = 0.00, 
    Librarie librarie = Librarie(), Magazin magazin = Magazin());
    ~Cont();
    Cont(const Cont& other);
    Cont& operator=(const Cont& other);
    char* getNumeUtilizator();
    double getBani();
    Librarie getLibrarie();
    Magazin getMagazin();
    void setNumeUtilizator(const char* numeUtilizatorNou);
    void setBani(double baniNou);
    void setLibrarie(const Librarie& librarieNou);
    void setMagazin(const Magazin& magazinNou);

    //metode specifice clasei cont
    void adaugaSuma();
    void schimbaNume();
    void cumparaJoc();
    void joacaJoc();
    void afiseazaJocuriLibrarie();
    void afiseazaJocuriMagazin();
    void detaliiCont();
    void detaliiJoc();
};