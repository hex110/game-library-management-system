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
    //constructor
    Cont(const char* numeUtilizator = "", double bani = 0.00, 
    Librarie librarie = Librarie(), Magazin magazin = Magazin()) : 
    bani{bani}, librarie{librarie}, magazin{magazin} {
        this->numeUtilizator = new char[strlen(numeUtilizator) + 1];
        strcpy(this->numeUtilizator, numeUtilizator);
    }

    //destructor
    ~Cont() {
        delete[] numeUtilizator;
    }

    //copy constructor
    Cont(const Cont& other) :
    bani{bani}, librarie(other.librarie), magazin(other.magazin) {
        this->numeUtilizator = new char[strlen(other.numeUtilizator) + 1];
        strcpy(this->numeUtilizator, other.numeUtilizator);
    }

    //= operator
    Cont& operator=(const Cont& other) {
        if (this != &other) {
            delete[] this->numeUtilizator;
            this->numeUtilizator = new char[strlen(other.numeUtilizator) + 1];
            strcpy(this->numeUtilizator, other.numeUtilizator);
            bani = other.bani;
            librarie = other.librarie;
            magazin = other.magazin;
        }
        return *this;
    }

    //getters
    char* getNumeUtilizator() const {
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
    void setNumeUtilizator(const char* numeUtilizatorNou) {
        delete[] this->numeUtilizator;
        this->numeUtilizator = new char[strlen(numeUtilizatorNou) + 1];
        strcpy(this->numeUtilizator, numeUtilizatorNou);
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
        std::cout<<"Cati bani doriti sa adaugati in cont? ";
        std::cin>>suma;
        bani += suma;
        std::cout<<"Se incarca...\n";
        //timer for 1 second
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout<<"Suma a fost adaugata cu succes!\n";
    }

    void schimbaNume() {
        std::string numeNou;
        std::cout<<"Introduceti noul nume de utilizator: \n";
        std::cin.ignore();
        getline(std::cin, numeNou);
        setNumeUtilizator(numeNou.c_str());
        std::cout<<"Numele a fost schimbat cu succes!\n";
    }

    void cumparaJoc() {
        std::string numeJoc, raspuns;
        magazin.afiseazaJocuriSumar();
        std::cout<<"\nCe joc doriti sa cumparati? (introduceti numele jocului)\n";
        std::cin.ignore();
        getline(std::cin, numeJoc);
        if (!magazin.existaJoc(numeJoc) and !librarie.existaJoc(numeJoc)) {
            std::cout<<"Jocul nu exista!\n";
            return;
        }
        else if (!magazin.existaJoc(numeJoc)) {
            std::cout<<"Deja ati cumparat acest joc.\n";
            return;
        }
        JocMagazin joc = magazin.getJocByName(numeJoc);

        if (bani >= joc.getPret()) {
            std::cout<<"Aveti fonduri suficiente pentru a cumpara acest joc!\n";
            std::cout<<"Doriti sa procedati? (da/nu)\n";
            std::cin>>raspuns;

            if (raspuns == "nu" or raspuns == "NU") {
                std::cout<<"Nu ati cumparat jocul. Multumim pentru timpul acordat\n";
                return;
            }
            else if (raspuns == "da" or raspuns == "DA") {
                std::cout<<"Se incarca...\n";
                //timer for 1 second
                std::this_thread::sleep_for(std::chrono::seconds(1));
                bani -= joc.getPret();
                librarie.adaugaJoc(joc);
                magazin.stergeJoc(numeJoc);
                std::cout<<"Jocul a fost cumparat cu succes! Il gasiti in libraria voastra.\n";
                return;
            }
            else std::cout<<"Raspuns invalid. Va rugam reincercati.\n";
        } 
        else std::cout<<"Nu aveti suficiente fonduri pentru a cumpara acest joc!\n";
    }

    void joacaJoc() {
        std::string numeJoc;
        librarie.afiseazaJocuriSumar();
        std::cout<<"\nCe joc doriti sa jucati? (introduceti numele jocului)\n";
        std::cin.ignore();
        getline(std::cin, numeJoc);
        if (!librarie.existaJoc(numeJoc) and !magazin.existaJoc(numeJoc)) {
            std::cout<<"Jocul nu exista!\n";
            return;
        }
        else if (!librarie.existaJoc(numeJoc)) {
            std::cout<<"Nu aveti acest joc in librarie.\n";
            return;
        }
        Joc joc = librarie.getJocByName(numeJoc);
        joc.deschideJoc();
        std::cout<<"Jocul se deschide acum!\n";
    }

    void afiseazaJocuriLibrarie() {
        librarie.afiseazaJocuriSumar();
    }

    void afiseazaJocuriMagazin() {
        magazin.afiseazaJocuriSumar();
    }

    void detaliiCont() {
        std::cout<<"Nume utilizator: "<<numeUtilizator<<"\n";
        std::cout<<"Fonduri disponibile: "<<bani<<" euro\n";
        std::cout<<"Numar de jocuri detinute: "<<librarie.getNumarJocuri()<<"\n";
    }
    
    void detaliiJoc() {
        std::string numeJoc;
        std::cout<<"Introduceti numele jocului pentru care doriti detalii: ";
        std::cin.ignore();
        getline(std::cin, numeJoc);
        std::cout<<'\n';
        if (librarie.existaJoc(numeJoc)) {
            Joc joc = librarie.getJocByName(numeJoc);
            std::cout<<joc.detaliiJoc();
        }
        else if (magazin.existaJoc(numeJoc)) {
            JocMagazin joc = magazin.getJocByName(numeJoc);
            std::cout<<joc.detaliiJoc();
        }
        else std::cout<<"Jocul nu exista!\n";
    }
};