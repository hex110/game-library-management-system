#include <bits/stdc++.h>
#include "cont.h"

int main() {
    //creare jocuri
    Joc joc1("GTA V", 1, "17/09/2013", 100);
    Joc joc2("Minecraft", 2, "18/09/2011", 200);
    JocMagazin joc3("Cyberpunk 2077", 2, "10/12/2020", 49.99);
    JocMagazin joc4("Geometry Dash", 322170, "02/06/2020", 20.00);
    //creare librarie
    std::vector<Joc> jocuri = {joc1, joc2};
    Librarie librarie(jocuri);
    //creare magazin
    std::vector<JocMagazin> jocuriMagazin = {joc3, joc4};
    Magazin magazin(jocuriMagazin);
    //creare cont
    Cont cont("hex", 0.00, librarie, magazin);

    std::cout<<"1: Detalii cont\n";
    std::cout<<"2: Schimbati nume utilizator\n";
    std::cout<<"3: Adaugati fonduri\n";
    std::cout<<"4: Jocuri magazin\n";
    std::cout<<"5: Jocuri librarie\n";
    std::cout<<"6: Detalii joc\n";
    std::cout<<"7: Cumpara joc\n";
    std::cout<<"8: Jucati joc\n";
    std::cout<<"9: Iesire\n";

    std::string input;
    bool continua = true;
    while(continua) {
        std::cout<<"Alegeti o optiune: ";
        std::cin>>input;
        system("cls");
        std::cout<<"1: Detalii cont\n";
        std::cout<<"2: Schimbati nume utilizator\n";
        std::cout<<"3: Adaugati fonduri\n";
        std::cout<<"4: Jocuri magazin\n";
        std::cout<<"5: Jocuri librarie\n";
        std::cout<<"6: Detalii joc\n";
        std::cout<<"7: Cumpara joc\n";
        std::cout<<"8: Jucati joc\n";
        std::cout<<"9: Iesire\n";
        std::cout<<'\n';
        int optiune = stoi(input);
        if (optiune<1 or optiune>9) {
            std::cout<<"Optiune invalida\n";
            continue;
        }
        switch (optiune) {
            case 1:
                cont.detaliiCont();
                std::cout<<"\n\n";
                continue;
            case 2:
                cont.schimbaNume();
                std::cout<<"\n\n";
                continue;
            case 3:
                cont.adaugaSuma();
                std::cout<<"\n\n";
                continue;
            case 4:
                cont.afiseazaJocuriMagazin();
                std::cout<<"\n\n";
                continue;
            case 5:
                cont.afiseazaJocuriLibrarie();
                std::cout<<"\n\n";
                continue;
            case 6:
                cont.detaliiJoc();
                std::cout<<"\n\n";
                continue;
            case 7:
                cont.cumparaJoc();
                std::cout<<"\n\n";
                continue;
            case 8:
                cont.joacaJoc();
                std::cout<<"\n\n";
                continue;
            case 9:
                std::cout<<"Va multumesc pentru timpul acordat\n";
                //timer de 2 secunde
                std::this_thread::sleep_for(std::chrono::seconds(2));
                continua = false;
                break;
        }
    }
    return 0;
}