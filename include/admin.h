#include <bits/stdc++.h>
#include "cont.h"

class Admin : public Cont{
public:
    Admin(const char* numeUtilizator = "", const char* parola = "", 
    Librarie librarie = Librarie(), Magazin magazin = Magazin());
    ~Admin();

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
    void schimbaDetaliiJoc();
    void adaugaJocMagazin();
    void stergeJocMagazin();
    void blocheazaCont();
};