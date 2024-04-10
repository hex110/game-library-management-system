#include <bits/stdc++.h>
using namespace std;

class Joc{
private:
    //am decis sa nu folosesc char cu pointer ca mi se parea mai simplu cu string
    //si am cautat si aflat ca sunt comparabile in termen de performanta
    //deci sper ca nu e problema
    string nume;
    int id;
    string dataLansarii;
    int timpJucat;

    //metoda privata folosita intr-o metoda publica de mai jos
    //schimba dintr-un int care reprezinta timpul jucat
    //intr-un string care afiseaza intr-un mod frumos de citit
    //cate minute sau ore a fost acel joc jucat
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
    Joc(string nume, int id, string dataLansarii, int timpJucat) : nume{nume}, id{id}, dataLansarii{dataLansarii},
    timpJucat{timpJucat} {};

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
        string s = "Jocul " + nume + " a fost lansat pe data de " + dataLansarii;
        string s1 = " si are un gameplay captivant.";
        string s2 = " si este foarte apreciat de critici.";
        string s3 = " si ofera o experienta unica jucatorilor.";
        int randomIndex = rand() % 3;
        switch (randomIndex) {
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

int test1() {
    //am folosit chatgpt sa generez date si teste ca sa ma asigur ca merge totul cum trebuie
    //am rezolvat bugurile si totul ruleaza

    // Test 1: Constructor and Data Initialization
    Joc halfLife("Half-Life", 70, "19/11/1998", 60);
    assert(halfLife.getNume() == "Half-Life");
    assert(halfLife.getId() == 70);
    assert(halfLife.getDataLansarii() == "19/11/1998");
    assert(halfLife.getTimpJucat() == 60);
    cout << "Constructor and data initialization test passed.\n";

    // Test 2: Copy Constructor and Assignment Operator
    Joc rocketLeague = halfLife; // Copy constructor
    assert(rocketLeague.getNume() == "Half-Life");
    Joc geometryDash("Geometry Dash", 322170, "22/12/2014", 90);
    rocketLeague = geometryDash; // Assignment operator
    assert(rocketLeague.getNume() == "Geometry Dash");
    cout << "Copy constructor and assignment operator test passed.\n";

    // Test 3: Setters and Getters
    geometryDash.setNume("Changed Name");
    assert(geometryDash.getNume() == "Changed Name");
    cout << "Setters and getters test passed.\n";

    // Test 4: Time Played Formatting
    halfLife.setTimpJucat(60); // Exactly 1 hour
    assert(halfLife.oreJucate() == "Te-ai jucat Half-Life timp de 1 ore.");
    halfLife.setTimpJucat(125); // 2 hours and 5 minutes
    assert(halfLife.oreJucate() == "Te-ai jucat Half-Life timp de 2 ore si 5 de minute.");
    geometryDash.setTimpJucat(30); // 30 minutes
    assert(geometryDash.oreJucate() == "Te-ai jucat Changed Name timp de 30 de minute.");
    cout << "Time played formatting test passed.\n";

    cout << "All tests passed.\n";

    //las metoda asta comentata ca sa nu deschida jocul, dar daca se scoate commentul
    //se observa ca functioneaza
    //geometryDash.deschideJoc();
    return 0;
}