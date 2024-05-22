#include <bits/stdc++.h>
#include "cont.h"

class Utilizator : public Cont{
private:
    double bani;

public:
    Utilizator(const char* numeUtilizator = "", const char* parola = "",
    double bani = 0.00, Librarie librarie = Librarie(), Magazin magazin = Magazin()) : 
        bani{bani}, Cont(numeUtilizator, parola, librarie, magazin) {};

    ~Utilizator() {
        delete[] numeUtilizator;
        delete[] parola;
    }

    //metode override
    void detaliiCont() override {
        std::cout<<"Nume utilizator: "<<numeUtilizator<<"\n";
        std::cout<<"Fonduri disponibile: "<<bani<<" euro\n";
        std::cout<<"Numar de jocuri detinute: "<<librarie.getNumarJocuri()<<"\n";
    }

    void modificareParola() override; //todo
    void autentificare() override; //todo

    void afiseazaJocuriLibrarie() override {
        librarie.afiseazaJocuriSumar();
    }
    void afiseazaJocuriMagazin() override {
        magazin.afiseazaJocuriSumar();
    }

    //metode specifice
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
    
};