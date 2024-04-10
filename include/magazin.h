#include <bits/stdc++.h>
#include "joc.h"

//clasa la fel ca librarie, dar ce foloseste un std::vector de tip JocMagazin in loc de Joc
class Magazin{
private:
    int numarJocuri;
    std::vector<JocMagazin> jocuriMagazin;

    void sortareJocuri();

public:
    Magazin(const std::vector<JocMagazin>& jocuri = {});
    Magazin(const Magazin& other);
    Magazin& operator=(const Magazin& other);
    int getNumarJocuri();
    std::vector<JocMagazin> getJocuriMagazin();
    void setJocuriMagazin(const std::vector<JocMagazin>& jocuriNou);

    //metode specifice clasei magazin
    void adaugaJoc(const JocMagazin& joc);
    void stergeJoc(const std::string numeJoc);
    void afiseazaJocuriSumar();
    void actualizeazaDetaliiJoc(const std::string numeJoc, const int idNou, 
    const std::string dataLansariiNou, const double pretNou);
    JocMagazin getJocByName(std::string numeJoc);
    bool existaJoc(std::string numeJoc);

};