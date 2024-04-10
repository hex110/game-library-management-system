#include <bits/stdc++.h>
#include "librarie.h"
#include "magazin.h"
using namespace std;

class Cont{
private:
    int numeUtilizator;
    double bani;
    Librarie librarie;
    Magazin magazin;

protected:
    //constructor
    Cont(int numeUtilizator, double bani, Librarie librarie, Magazin magazin) : 
    numeUtilizator{numeUtilizator}, bani{bani}, librarie{librarie}, magazin{magazin} {}

    //copy constructor
    Cont(const Cont& other) :
    numeUtilizator(other.numeUtilizator), bani{bani}, librarie(other.librarie), magazin(other.magazin) {}

    //= operator
    Cont& operator=(const Cont& other) {
        if (this != &other) {
            numeUtilizator = other.numeUtilizator;
            bani = other.bani;
            librarie = other.librarie;
            magazin = other.magazin;
        }
        return *this;
    }

    //getters
    int getNumeUtilizator() const {
        return numeUtilizator;
    }

    double getBani() const {
        return bani;
    }

    Librarie getLibrarie() const {
        return librarie;
    }

    Magazin getMagazin() const {
        return magazin;
    }

    //setter
    void setNumeUtilizator(int numeUtilizatorNou) {
        numeUtilizator = numeUtilizatorNou;
    }

    void setBani(double baniNou) {
        bani = baniNou;
    }

    void setLibrarie(const Librarie& librarieNou) {
        librarie = librarieNou;
    }

    void setMagazin(const Magazin& magazinNou) {
        magazin = magazinNou;
    }

public:
    //metode specifice clasei cont
    void adaugaSuma(double suma) {
        cout<<"Cati bani doriti sa adaugati in cont? ";
        cin>>suma;
        bani += suma;
        cout<<"Se incarca...";
        //timer for 1 second
        //this_thread::sleep_for(chrono::seconds(1));
        cout<<"Suma a fost adaugata cu succes!\n";
    }

    void cumparaJoc(string numeJoc) {
        JocMagazin joc = magazin.getJocByName(numeJoc);

        if (bani >= joc.getPret()) {
            bani -= joc.getPret();
            librarie.adaugaJoc(joc);
            magazin.stergeJoc(joc.getNume());
            cout<<"Jocul a fost cumparat cu succes!\n";
        } else {
            cout<<"Nu aveti suficienti bani pentru a cumpara acest joc!\n";
        }
    }
    
};