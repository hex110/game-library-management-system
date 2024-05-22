#ifndef UTILIZATOR_CPP
#define UTILIZATOR_CPP

#include <bits/stdc++.h>
#include "../src/cont.cpp"

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
        librarie.afiseazaJocuriSumar();
    }
    void afiseazaJocuriMagazin() override {
        magazin.afiseazaJocuriSumar();
    }

    //metode specifice
    void adaugaSuma() {
        static int contor = 0;
        contor++;
        double suma;
        std::cout<<"Cati bani doriti sa adaugati in cont? ";
        std::cin>>suma;
        suma = static_cast<double>(suma);
        std::cout<<"Se incarca...\n";
        //timer for 1 second
        std::this_thread::sleep_for(std::chrono::seconds(1));
        if (contor < 5) {
            bani += suma;
            std::cout<<"Suma a fost adaugata cu succes!\n";
        }
        else {
            std::cout<<"Suma a fost adaugata cu succes! Multumim pentru sustinere! "<<
            "Ati primit un bonus de 10% in fonduri pentru suportul de-a lungul timpului!\n";
            bani += (suma + suma/10);
        }
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

#endif // UTILIZATOR_CPP