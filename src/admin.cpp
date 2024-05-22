#ifndef ADMIN_CPP
#define ADMIN_CPP

#include <bits/stdc++.h>
#include "../src/cont.cpp"

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

    void modificareParola() override {
        std::cout<<"Introduceti parola curenta: ";
        std::string parolaCurenta;
        std::cin>>parolaCurenta;
        if (parolaCurenta != parola) {
            std::cout<<"Parola incorecta\n";
            return;
        }
        std::cout<<"\nIntroduceti noua parola: ";
        char* nouaParola = new char[100];
        std::cin>>nouaParola;
        delete[] parola;
        parola = nouaParola;
        std::cout<<"Parola schimbata cu succes\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return;
    }

    void autentificare() override {
        std::cout<<"Introduceti parola: ";
        std::string parolaIntrodusa;
        std::cin>>parolaIntrodusa;
        while (parolaIntrodusa != parola) {
            std::cout<<"Parola incorecta\n";
            std::cout<<"Introduceti parola: ";
            std::cin>>parolaIntrodusa;
        }
        std::cout<<"Autentificare reusita\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return;
    }

    void afiseazaJocuriLibrarie() override {
        std::cout<<"Ca si admin, aveti acces la toate jocurile disponibile.\n";
        librarie.afiseazaJocuriSumar();
    }
    void afiseazaJocuriMagazin() override {
        std::cout<<"Ca si admin, aveti deja acces la toate jocurile disponibile\n";
    }

    //metode specifice

    void adaugaJocMagazin() {
        std::cout<<"Introduceti numele jocului: ";
        char* numeJoc = new char[100];
        std::cin>>numeJoc;
        std::cout<<"Introduceti id-ul jocului: ";
        int id;
        std::cin>>id;
        std::cout<<"Introduceti data lansarii jocului: ";
        char* dataLansarii = new char[100];
        std::cin>>dataLansarii;
        std::cout<<"Introduceti pretul jocului: ";
        double pret;
        std::cin>>pret;
        JocMagazin joc(numeJoc, id, dataLansarii, pret);
        magazin.adaugaJoc(joc);
        std::cout<<"Joc adaugat cu succes\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return;
    }
    void stergeJocMagazin() {
        std::cout<<"Introduceti numele jocului pe care doriti sa il stergeti: ";
        std::string numeJoc;
        std::cin>>numeJoc;
        magazin.stergeJoc(numeJoc);
        std::cout<<"Joc sters cu succes\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return;
    }
    
};

#endif // ADMIN_CPP