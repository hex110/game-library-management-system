#include <bits/stdc++.h>
#include "src/admin.cpp"
#include "src/utilizator.cpp"
#include "interfaces/adminInterface.cpp"
#include "interfaces/utilizatorInterface.cpp"

int main() {
    Joc joc1("GTA V", 271590, "14/04/2015", 40);
    Joc joc2("Rocket League", 252950, "07/07/2015", 4000);
    Joc joc3("Apex Legends", 1172470, "05/11/2020", 1000);
    JocMagazin joc4("Cyberpunk 2077", 1091500, "10/12/2020", 59.99);
    JocMagazin joc5("Geometry Dash", 322170, "22/12/2014", 0);
    JocMagazin joc6("Elden Ring", 1245620, "25/02/2022", 59.99);
    JocMagazin joc7("Half-Life", 70, "08/11/1998", 9.99);
    JocMagazin joc8("Dota 2", 570, "09/07/2013", 0);
    //creare librarie
    std::vector<Joc> jocuri = {joc1, joc2, joc3};
    Librarie librarie(jocuri);
    //creare magazin
    std::vector<JocMagazin> jocuriMagazin = {joc4, joc5, joc6, joc7, joc8};
    Magazin magazin(jocuriMagazin);
    //creare cont admin
    //Cont cont("hex", 0.00, librarie, magazin);
    Admin contAdmin("hex", "Parola123", librarie, magazin);
    //creare cont utilizator
    Utilizator contUtilizator("ion", "1234", 30.00, librarie, magazin);

    //dynamic cast the two pointers to Cont*
    Cont* contAdminPtr = dynamic_cast<Cont*>(&contAdmin);
    Cont* contUtilizatorPtr = dynamic_cast<Cont*>(&contUtilizator);

    //vector de conturi
    std::vector<Cont*> conturi = {contAdminPtr, contUtilizatorPtr};

    bool continua = true;
    #ifdef _WIN32
        const bool windows = true;
    #elif __linux__
        const bool windows = false;
    #endif

    std::cout<<"Introduceti numele de utilizator: ";
    std::string numeUtilizator = "";
    std::cin>>numeUtilizator;
    Cont* contCurent = nullptr;
    while (contCurent == nullptr) {
        for (auto cont : conturi) {
            if (cont->getNumeUtilizator() == numeUtilizator) {
                contCurent = cont;
                break;
            }
        }
        if (contCurent == nullptr) {
            windows ? system("cls") : system("clear");
            std::cout << "Nume de utilizator nu a fost gasit. Incercati din nou: ";
            std::cin >> numeUtilizator;
        }
    }
    contCurent->autentificare();

    //if cont is utilizator, begin the main in utilizator.cpp
    //if cont is admin, begin the main in admin.cpp
    if (dynamic_cast<Utilizator*>(contCurent)) {
        startCLIUtilizator(*dynamic_cast<Utilizator*>(contCurent));
    }
    else if (dynamic_cast<Admin*>(contCurent)) {
        startCLIAdmin(*dynamic_cast<Admin*>(contCurent));
    }
    return 0;
}