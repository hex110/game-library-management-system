#include <bits/stdc++.h>
#include "librarie.h"
#include "magazin.h"
using namespace std;

class Cont{
private:
    string numeUtilizator;
    double bani;
    Librarie librarie;
    Magazin magazin;

public:
    //constructor
    Cont(string numeUtilizator, double bani, Librarie librarie, Magazin magazin) : 
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
    string getNumeUtilizator() const {
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
    void setNumeUtilizator(string numeUtilizatorNou) {
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
    void adaugaSuma() {
        double suma;
        cout<<"Cati bani doriti sa adaugati in cont? ";
        cin>>suma;
        bani += suma;
        cout<<"Se incarca...\n";
        //timer for 1 second
        this_thread::sleep_for(chrono::seconds(1));
        cout<<"Suma a fost adaugata cu succes!\n";
    }

    void schimbaNume() {
        string numeNou;
        cout<<"Introduceti noul nume de utilizator: \n";
        cin.ignore();
        getline(cin, numeNou);
        setNumeUtilizator(numeNou);
        cout<<"Numele a fost schimbat cu succes!\n";
    }

    void cumparaJoc() {
        string numeJoc, raspuns;
        magazin.afiseazaJocuriSumar();
        cout<<"\nCe joc doriti sa cumparati? (introduceti numele jocului)\n";
        cin.ignore();
        getline(cin, numeJoc);
        if (!magazin.existaJoc(numeJoc) and !librarie.existaJoc(numeJoc)) {
            cout<<"Jocul nu exista!\n";
            return;
        }
        else if (!magazin.existaJoc(numeJoc)) {
            cout<<"Deja ati cumparat acest joc.\n";
            return;
        }
        JocMagazin joc = magazin.getJocByName(numeJoc);

        if (bani >= joc.getPret()) {
            cout<<"Aveti fonduri suficiente pentru a cumpara acest joc!\n";
            cout<<"Doriti sa procedati? (da/nu)\n";
            cin>>raspuns;

            if (raspuns == "nu" or raspuns == "NU") {
                cout<<"Nu ati cumparat jocul. Multumim pentru timpul acordat\n";
                return;
            }
            else if (raspuns == "da" or raspuns == "DA") {
                cout<<"Se incarca...\n";
                //timer for 1 second
                this_thread::sleep_for(chrono::seconds(1));
                bani -= joc.getPret();
                librarie.adaugaJoc(joc);
                magazin.stergeJoc(numeJoc);
                cout<<"Jocul a fost cumparat cu succes! Il gasiti in libraria voastra.\n";
                return;
            }
            else cout<<"Raspuns invalid. Va rugam reincercati.\n";
        } 
        else cout<<"Nu aveti suficiente fonduri pentru a cumpara acest joc!\n";
    }

    void joacaJoc() {
        string numeJoc;
        librarie.afiseazaJocuriSumar();
        cout<<"\nCe joc doriti sa jucati? (introduceti numele jocului)\n";
        cin.ignore();
        getline(cin, numeJoc);
        if (!librarie.existaJoc(numeJoc) and !magazin.existaJoc(numeJoc)) {
            cout<<"Jocul nu exista!\n";
            return;
        }
        else if (!librarie.existaJoc(numeJoc)) {
            cout<<"Nu aveti acest joc in librarie.\n";
            return;
        }
        Joc joc = librarie.getJocByName(numeJoc);
        joc.deschideJoc();
        cout<<"Jocul se deschide acum!\n";
    }

    void afiseazaJocuriLibrarie() {
        librarie.afiseazaJocuriSumar();
    }

    void afiseazaJocuriMagazin() {
        magazin.afiseazaJocuriSumar();
    }

    void detaliiCont() {
        cout<<"Nume utilizator: "<<numeUtilizator<<"\n";
        cout<<"Fonduri disponibile: "<<bani<<" euro\n";
        cout<<"Numar de jocuri detinute: "<<librarie.getNumarJocuri()<<"\n";
    }
    
    void detaliiJoc() {
        string numeJoc;
        cout<<"Introduceti numele jocului pentru care doriti detalii: ";
        cin.ignore();
        getline(cin, numeJoc);
        cout<<'\n';
        if (librarie.existaJoc(numeJoc)) {
            Joc joc = librarie.getJocByName(numeJoc);
            cout<<joc.detaliiJoc();
        }
        else if (magazin.existaJoc(numeJoc)) {
            JocMagazin joc = magazin.getJocByName(numeJoc);
            cout<<joc.detaliiJoc();
        }
        else cout<<"Jocul nu exista!\n";
    }
};