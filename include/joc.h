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

    std::string timpJucatCaString();
public:
    Joc(std::string nume = "", int id = -1, std::string dataLansarii = "00/00/0000",
    int timpJucat = 0);
    Joc(const Joc& other);
    Joc& operator=(const Joc& other);
    friend std::ostream& operator<<(std::ostream& out, const Joc& joc);
    friend std::istream& operator>>(std::istream& in, Joc& joc);
    std::string getNume();
    int getId();
    std::string getDataLansarii();
    int getTimpJucat();
    void setNume(const std::string numeNou);
    void setId(const int idNou);
    void setDataLansarii(const std::string dataLansariiNou);
    void setTimpJucat(const int timpJucatNou);

    //metode specifice clasei joc
    void deschideJoc();
    std::string oreJucate();
    std::string detaliiJoc();
};

class JocMagazin : public Joc {
private:
    double pret;
public:
    JocMagazin(std::string nume, int id, std::string dataLansarii, double pret);
    JocMagazin(const JocMagazin& other);
    JocMagazin& operator=(const JocMagazin& other);
    double getPret();
    void setPret(const double pretNou);
};

#endif // JOC_H