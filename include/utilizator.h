#include <bits/stdc++.h>
#include "cont.h"

class Utilizator : public Cont{
private:
    double bani;

public:
    Utilizator(const char* numeUtilizator = "", const char* parola = "",
    double bani = 0.00, Librarie librarie = Librarie(), Magazin magazin = Magazin());
    ~Utilizator();

    //deja incluse in clasa de baza
    void schimbaNume();
    void detaliiJoc();
    void joacaJoc();

    //metode override
    void detaliiCont() override;
    void modificareParola() override;
    void autentificare() override;
    void afiseazaJocuriLibrarie() override;
    void afiseazaJocuriMagazin() override;

    //metode specifice
    void adaugaSuma();
    void cumparaJoc();
};