#ifndef JOC_H
#define JOC_H

#include <bits/stdc++.h>

class Joc{
private:
    int timpJucat;
protected:
    std::string nume;
    int id;
    std::string dataLansarii;

    //metoda ce afiseaza timpul jucat sub forma de std::string formatat frumos
    std::string timpJucatCaString() const {
        std::string timp;
        if (timpJucat < 60) { //sub 60 minute
            timp = std::to_string(timpJucat) + " de minute";
        }
        else { //peste 60 minute
            int ore = timpJucat / 60;
            int minute = timpJucat % 60;
            timp = std::to_string(ore) + " ore";
            if (minute > 0) {
                timp += " si " + std::to_string(minute) + " de minute";
            }
        }
        return timp;
    }
public:
    //constructor
    Joc(std::string nume = "", int id = -1, std::string dataLansarii = "00/00/0000",
    int timpJucat = 0) : nume{nume}, id{id},
    dataLansarii{dataLansarii}, timpJucat{timpJucat} {};

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

    //operator <<
    friend std::ostream& operator<<(std::ostream& out, const Joc& joc) {
        out<<"Nume:"<<joc.nume<<'\n';
        out<<"ID: "<<joc.id<<'\n';
        out<<"Data lansarii: "<<joc.dataLansarii<<'\n';
        out<<"Timp jucat: "<<joc.timpJucat<<'\n';
        out<<"Detalii:"<<joc.detaliiJoc()<<'\n';
        return out;
    }

    //operator >>
    friend std::istream& operator>>(std::istream& in, Joc& joc) {
        std::cout<<"Nume joc: ";
        in >> joc.nume;
        std::cout<<"ID joc: ";
        in >> joc.id;
        std::cout<<"Data lansarii: ";
        in >> joc.dataLansarii;
        std::cout<<"Timp jucat: ";
        in >> joc.timpJucat;
        return in;
    }

    //getters
    std::string getNume() const {
        return nume;
    }

    int getId() const {
        return id;
    }

    std::string getDataLansarii() const {
        return dataLansarii;
    }

    int getTimpJucat() const {
        return timpJucat;
    }

    //setters
    void setNume(const std::string numeNou) {
        this->nume = numeNou;
    }

    void setId(const int idNou) {
        this->id = idNou;
    }

    void setDataLansarii(const std::string dataLansariiNou) {
        this->dataLansarii = dataLansariiNou;
    }

    void setTimpJucat(const int timpJucatNou) {
        this->timpJucat = timpJucatNou;
    }

    //metode specifice clasei joc

    //metoda asta deschide jocul respectiv pe steam
    //daca cine ruleaza nu are jocul pe steam, deschide store page-ul
    void deschideJoc() const {
        std::string command = "start steam://run/" + std::to_string(id);
        system(command.c_str());
    }

    //metoda care afiseaza cate minute sau ore ai jucat un joc
    std::string oreJucate() const {
        return timpJucatCaString();
    }

    std::string detaliiJoc() const {
        std::string s = "Jocul " + nume;
        std::string s1 = " are un gameplay captivant si este apreciat de oricine.";
        std::string s2 = " este apreciat de critici, dar jucatorii nu sunt de acord.";
        std::string s3 = " nu este apreciat de nimeni.";
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
    JocMagazin(std::string nume, int id, std::string dataLansarii, double pret) :
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
    std::cout<<geometryDash.getNume()<<'\n';
    std::cout<<geometryDash.getId()<<'\n';
    std::cout<<geometryDash.getDataLansarii()<<'\n';
    std::cout<<geometryDash.getTimpJucat()<<'\n';
    std::cout<<geometryDash.oreJucate()<<'\n';
    std::cout<<geometryDash.detaliiJoc()<<'\n';
    std::cout<<geometryDash<<'\n';

    //las metoda asta comentata ca sa nu deschida jocul, dar daca se scoate commentul
    //se observa ca functioneaza si chiar se deschide jocul
    //geometryDash.deschideJoc();
    return 0;
}

#endif // JOC_H