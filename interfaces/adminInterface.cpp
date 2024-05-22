#include <bits/stdc++.h>
#include "../include/admin.h"

enum OptiuniMeniuAdmin {
    OPTa_DetaliiCont = 1,
    OPTa_SchimbaNume,
    OPTa_SchimbaParola,
    OPTa_AfiseazaJocuriMagazin,
    OPTa_AfiseazaJocuriLibrarie,
    OPTa_DetaliiJoc,
    OPTa_JoacaJoc,
    OPTa_AdaugaJocMagazin,
    OPTa_StergeJocMagazin,
    OPTa_Iesire = 0
};

void startCLIAdmin(Admin cont) {
    std::cout<<"1: Detalii cont\n";
    std::cout<<"2: Schimbati nume utilizator\n";
    std::cout<<"3: Schimbati parola\n";
    std::cout<<"4: Jocuri magazin\n";
    std::cout<<"5: Jocuri librarie\n";
    std::cout<<"6: Detalii joc\n";
    std::cout<<"7: Jucati joc\n";
    std::cout<<"8: Adauga joc in magazin\n";
    std::cout<<"9: Sterge joc din magazin\n";
    std::cout<<"0: Iesire\n";
    std::cout<<'\n';

    std::string input;
    bool continua = true;
    #ifdef _WIN32
        const bool windows = true;
    #elif __linux__
        const bool windows = false;
    #endif

    while(continua) {
        std::cout<<"Alegeti o optiune: ";
        std::cin>>input;
        windows ? system("cls") : system("clear");
        std::cout<<"1: Detalii cont\n";
        std::cout<<"2: Schimbati nume utilizator\n";
        std::cout<<"3: Schimbati parola\n";
        std::cout<<"4: Jocuri magazin\n";
        std::cout<<"5: Jocuri librarie\n";
        std::cout<<"6: Detalii joc\n";
        std::cout<<"7: Jucati joc\n";
        std::cout<<"8: Adauga joc in magazin\n";
        std::cout<<"9: Sterge joc din magazin\n";
        std::cout<<"0: Iesire\n";
        std::cout<<'\n';
        std::cout<<'\n';
        int optiune = stoi(input);
        if (optiune<0 or optiune>9) {
            std::cout<<"Optiune invalida\n";
            continue;
        }
        switch (optiune) {
            case OPTa_DetaliiCont:
                cont.detaliiCont();
                std::cout<<"\n\n";
                continue;
            case OPTa_SchimbaNume:
                cont.schimbaNume();
                std::cout<<"\n\n";
                continue;
            case OPTa_SchimbaParola:
                cont.modificareParola();
                std::cout<<"\n\n";
                continue;
            case OPTa_AfiseazaJocuriMagazin:
                cont.afiseazaJocuriMagazin();
                std::cout<<"\n\n";
                continue;
            case OPTa_AfiseazaJocuriLibrarie:
                cont.afiseazaJocuriLibrarie();
                std::cout<<"\n\n";
                continue;
            case OPTa_DetaliiJoc:
                cont.detaliiJoc();
                std::cout<<"\n\n";
                continue;
            case OPTa_JoacaJoc:
                cont.joacaJoc();
                std::cout<<"\n\n";
                continue;
            case OPTa_AdaugaJocMagazin:
                cont.adaugaJocMagazin();
                std::cout<<"\n\n";
                continue;
            case OPTa_StergeJocMagazin:
                cont.stergeJocMagazin();
                std::cout<<"\n\n";
                continue;
            case OPTa_Iesire:
                std::cout<<"Va multumesc pentru timpul acordat\n";
                //timer de 2 secunde
                std::this_thread::sleep_for(std::chrono::seconds(2));
                continua = false;
                break;
        }
    }
}