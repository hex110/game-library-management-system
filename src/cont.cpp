#ifndef CONT_CPP
#define CONT_CPP

#include <bits/stdc++.h>
#include "../src/librarie.cpp"
#include "../src/magazin.cpp"

class Cont{
protected:
    char* numeUtilizator;
    char* parola;
    Librarie librarie;
    Magazin magazin;

public:
    Cont(const char* numeUtilizator = "", const char* parola = "",
    Librarie librarie = Librarie(), Magazin magazin = Magazin()) : 
        librarie{librarie}, magazin{magazin} {
        this->parola = new char[strlen(parola) + 1];
        strcpy(this->parola, parola);
        this->numeUtilizator = new char[strlen(numeUtilizator) + 1];
        strcpy(this->numeUtilizator, numeUtilizator);
    }

    virtual ~Cont() {
        delete[] numeUtilizator;
        delete[] parola;
    }

    virtual void detaliiCont() = 0;
    virtual void modificareParola() = 0;
    virtual void autentificare() = 0;
    virtual void afiseazaJocuriLibrarie() = 0;
    virtual void afiseazaJocuriMagazin() = 0;

    std::string getNumeUtilizator() {
        return std::string(numeUtilizator);
    }
    
    void schimbaNume() {
        std::string numeNou;
        std::cout<<"Introduceti noul nume de utilizator: \n";
        std::cin.ignore();
        getline(std::cin, numeNou);

        delete[] this->numeUtilizator;
        this->numeUtilizator = new char[strlen(numeNou.c_str()) + 1];
        strcpy(this->numeUtilizator, numeNou.c_str());

        std::cout<<"Numele a fost schimbat cu succes!\n";
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
};

#endif // CONT_CPP