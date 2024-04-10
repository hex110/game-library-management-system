#include <bits/stdc++.h>
#include "clase/cont.cpp"

enum OptiuniMeniu {
    OPT_DetaliiCont = 1,
    OPT_SchimbaNume,
    OPT_AdaugaSuma,
    OPT_AfiseazaJocuriMagazin,
    OPT_AfiseazaJocuriLibrarie,
    OPT_DetaliiJoc,
    OPT_CumparaJoc,
    OPT_JoacaJoc,
    OPT_Iesire
};

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
            case OPT_DetaliiCont:
                cont.detaliiCont();
                std::cout<<"\n\n";
                continue;
            case OPT_SchimbaNume:
                cont.schimbaNume();
                std::cout<<"\n\n";
                continue;
            case OPT_AdaugaSuma:
                cont.adaugaSuma();
                std::cout<<"\n\n";
                continue;
            case OPT_AfiseazaJocuriMagazin:
                cont.afiseazaJocuriMagazin();
                std::cout<<"\n\n";
                continue;
            case OPT_AfiseazaJocuriLibrarie:
                cont.afiseazaJocuriLibrarie();
                std::cout<<"\n\n";
                continue;
            case OPT_DetaliiJoc:
                cont.detaliiJoc();
                std::cout<<"\n\n";
                continue;
            case OPT_CumparaJoc:
                cont.cumparaJoc();
                std::cout<<"\n\n";
                continue;
            case OPT_JoacaJoc:
                cont.joacaJoc();
                std::cout<<"\n\n";
                continue;
            case OPT_Iesire:
                std::cout<<"Va multumesc pentru timpul acordat\n";
                //timer de 2 secunde
                std::this_thread::sleep_for(std::chrono::seconds(2));
                continua = false;
                break;
        }
    }
    return 0;
}