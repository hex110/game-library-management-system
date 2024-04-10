#ifndef JOC_H
#define JOC_H

#include <bits/stdc++.h>
using namespace std;

class Joc{
private:
    int timpJucat;
protected:
    string nume;
    int id;
    string dataLansarii;

    //metoda ce afiseaza timpul jucat sub forma de string formatat frumos
    string timpJucatCaString() const {
        string timp;
        if (timpJucat < 60) { //sub 60 minute
            timp = to_string(timpJucat) + " de minute";
        }
        else { //peste 60 minute
            int ore = timpJucat / 60;
            int minute = timpJucat % 60;
            timp = to_string(ore) + " ore";
            if (minute > 0) {
                timp += " si " + to_string(minute) + " de minute";
            }
        }
        return timp;
    }
public:
    //constructor
    Joc(string nume, int id, string dataLansarii, int timpJucat) : nume{nume}, id{id},
    dataLansarii{dataLansarii}, timpJucat{timpJucat} {};

    //nu avem nevoie sa dam overwrite la destructor pentru ca nu folosim char cu pointer
    //~Joc() {}

    //copy constructor
    Joc(const Joc& other) {
        nume = other.nume;
        id = other.id;
        dataLansarii = other.dataLansarii;
        timpJucat = other.timpJucat;
    }

    //operator =
    Joc& operator=(const Joc& other) {
        if (this != &other) {
            nume = other.nume;
            id = other.id;
            timpJucat = other.timpJucat;
            dataLansarii = other.dataLansarii;
        }
        return *this;
    }

    //getters
    string getNume() const {
        return nume;
    }

    int getId() const {
        return id;
    }

    string getDataLansarii() const {
        return dataLansarii;
    }

    int getTimpJucat() const {
        return timpJucat;
    }

    //setters
    void setNume(const string numeNou) {
        this->nume = numeNou;
    }

    void setId(const int idNou) {
        this->id = idNou;
    }

    void setDataLansarii(const string dataLansariiNou) {
        this->dataLansarii = dataLansariiNou;
    }

    void setTimpJucat(const int timpJucatNou) {
        this->timpJucat = timpJucatNou;
    }

    //metode specifice clasei joc

    //metoda asta deschide jocul respectiv pe steam
    //daca cine ruleaza nu are jocul pe steam, deschide store page-ul
    void deschideJoc() const {
        string command = "start steam://run/" + to_string(id);
        system(command.c_str());
    }

    //metoda care afiseaza cate minute sau ore ai jucat un joc
    string oreJucate() const {
        return timpJucatCaString();
    }

    string detaliiJoc() const {
        string s = "Jocul " + nume;
        string s1 = " are un gameplay captivant si este apreciat de oricine.";
        string s2 = " este apreciat de critici, dar jucatorii nu sunt de acord.";
        string s3 = " nu este apreciat de nimeni.";
        //int randomIndex = rand() % 3;
        int sumaCifre = 0;
        for(int i=0; i<nume.size(); i++) {
            sumaCifre += nume[i] - '0';
        }
        int indexNume = sumaCifre % 3;
        switch (indexNume) {
            case 0:
                s += s1;
                break;
            case 1:
                s += s2;
                break;
            case 2:
                s += s3;
                break;
        }
        return s;
    }

};

//clasa mostenita de la clasa Joc care include si pret, pentru a fi folosita in clasa Magazin
class JocMagazin : public Joc {
private:
    double pret;

public:
    //cosntructor
    JocMagazin(string nume, int id, string dataLansarii, double pret) :
    Joc(nume, id, dataLansarii, 0), pret{pret} {};

    //copy constructor
    JocMagazin(const JocMagazin& other) : Joc(other) {
        pret = other.pret;
    }

    //operator =
    JocMagazin& operator=(const JocMagazin& other) {
        if (this != &other) {
            nume = other.nume;
            id = other.id;
            dataLansarii = other.dataLansarii;
            pret = other.pret;
        }
        return *this;
    }

    double getPret() const {
        return pret;
    }

    void setPret(const double pretNou) {
        this->pret = pretNou;
    }
};

int test1() {
    Joc geometryDash("Geometry Dash", 322170, "22 decembrie 2014", 100);
    cout << geometryDash.getNume() << endl;
    cout << geometryDash.getId() << endl;
    cout << geometryDash.getDataLansarii() << endl;
    cout << geometryDash.getTimpJucat() << endl;
    cout << geometryDash.oreJucate() << endl;
    cout << geometryDash.detaliiJoc() << endl;

    //las metoda asta comentata ca sa nu deschida jocul, dar daca se scoate commentul
    //se observa ca functioneaza si chiar se deschide jocul
    //geometryDash.deschideJoc();
    return 0;
}

#endif // JOC_H