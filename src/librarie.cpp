#ifndef LIBRARIE_CPP
#define LIBRARIE_CPP

#include <bits/stdc++.h>
#include "../src/joc.cpp"

class Librarie{ 
private:
    std::vector<Joc> jocuri;
    int numarJocuri;

    //sorteaza jocuri dupa id, metoda care isi ia call mereu cand se schimba jocurile din librarie
    void sortareJocuri() {
        int i, j, n = numarJocuri;
        bool t;
        for (i=0; i < n-1; i++) {
            t=0;
            for (j=0; j < n-i-1; j++) {
                if (jocuri[j].getId() > jocuri[j+1].getId()) {
                    std::swap(jocuri[j], jocuri[j+1]);
                    t=1;
                }
            }
            if (t == 0)
                break;
        }
    }

public:
    //constructor
    Librarie(const std::vector<Joc>& jocuri = {}) : jocuri{jocuri}, numarJocuri{jocuri.size()} {}

    //copy constructor
    Librarie(const Librarie& other) : numarJocuri(other.numarJocuri), jocuri(other.jocuri) {}

    //= operator
    Librarie& operator=(const Librarie& other) {
        if (this != &other) {
            numarJocuri = other.numarJocuri;
            jocuri = other.jocuri;
        }
        return *this;
    }

    //getters
    int getNumarJocuri() const {
        return numarJocuri;
    }

    std::vector<Joc> getJocuri() const {
        return jocuri;
    }

    //setter
    //nu avem pentru numar de jocuri pentru ca acela se schimba dinamic in setterul de jocuri
    void setJocuri(const std::vector<Joc>& jocuriNou) {
        jocuri = jocuriNou;
        numarJocuri = jocuri.size();
        sortareJocuri();
    }

    //metode specifice clasei librarie

    //adauga un joc nou in librarie
    void adaugaJoc(const Joc& joc) {
        jocuri.push_back(joc);
        numarJocuri++;
        sortareJocuri();
    }

    //sterge un joc din librarie doar dupa nume
    void stergeJoc(const std::string numeJoc) {
        for (int i=0; i<numarJocuri; i++) {
            if (jocuri[i].getNume() == numeJoc) {
                for (int j=i; j<numarJocuri-1; j++) {
                    jocuri[j] = jocuri[j+1];
                }
                numarJocuri--;
                break;
            }
        }
        sortareJocuri();
    }

    //afiseaza toate jocurile in ordinea id-ului
    void afiseazaJocuriSumar() {
        if (numarJocuri == 0) {
            std::cout<<"Nu ai nici un joc in librarie\n";
            return;
        }
        std::cout<<"Libraria ta de jocuri:\n";
        for (int i=0; i<numarJocuri; i++) {
            std::cout<<jocuri[i].getNume()<<" | Data lansarii: "<<jocuri[i].getDataLansarii()<<
            " | Timp jucat: "<<jocuri[i].oreJucate()<<" | ID: "<<
            jocuri[i].getId()<<'\n';
        }
    }

    //schimba detaliile unui joc
    //se putea face si dupa id, dar m-am gandit ca dupa nume e mai usor de folosit
    void actualizeazaDetaliiJoc(const std::string numeJoc, const int idNou,
    const std::string dataLansariiNou, const int timpJucatNou) {
        for (int i=0; i<numarJocuri; i++) {
            if (jocuri[i].getNume() == numeJoc) {
                jocuri[i].setDataLansarii(dataLansariiNou);
                jocuri[i].setTimpJucat(timpJucatNou);
                jocuri[i].setId(idNou);
                break;
            }
        }
        sortareJocuri();
    }

    Joc getJocByName(std::string numeJoc) {
        //transform numeJoc into all lowercase and remove spaces or special characters
        for (int i=0; i<numarJocuri; i++) {
            if (jocuri[i].getNume() == numeJoc) {
                return jocuri[i];
            }
        }
    }

    bool existaJoc(std::string numeJoc) {
        for (int i=0; i<numarJocuri; i++) {
            if (jocuri[i].getNume() == numeJoc) {
                return true;
            }
        }
        return false;
    }

};

int test2() {
    Librarie librarie({Joc("GTA V", 4, "17 septembrie 2013", 120),
    Joc("CS:GO", 3, "21 august 2012", 300)});
    std::cout<<librarie.getNumarJocuri()<<'\n';
    librarie.adaugaJoc(Joc("Valorant", 2, "2 iunie 2020", 50));
    librarie.stergeJoc("GTA V");
    librarie.afiseazaJocuriSumar();
    librarie.actualizeazaDetaliiJoc("CS:GO", 1, "21 august 2012", 400);
    librarie.afiseazaJocuriSumar();
    return 0;
}

#endif // LIBRARIE_CPP