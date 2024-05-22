#include <bits/stdc++.h>
#include "joc.h"

class Librarie{ 
private:
    int numarJocuri;
    std::vector<Joc> jocuri;

    void sortareJocuri();

public:
    Librarie(const std::vector<Joc>& jocuri = {});
    Librarie(const Librarie& other);
    Librarie& operator=(const Librarie& other);
    int getNumarJocuri();
    std::vector<Joc> getJocuri();
    void setJocuri(const std::vector<Joc>& jocuriNou);

    //metode specifice clasei librarie
    void adaugaJoc(const Joc& joc);
    void stergeJoc(const std::string numeJoc);
    void afiseazaJocuriSumar();
    void actualizeazaDetaliiJoc(const std::string numeJoc, const int idNou,
    const std::string dataLansariiNou, const int timpJucatNou);
    Joc getJocByName(std::string numeJoc);
    bool existaJoc(std::string numeJoc);

};