#include <bits/stdc++.h>
#include "../include/utilizator.h"

enum OptiuniMeniuUtilizator {
    OPTu_DetaliiCont = 1,
    OPTu_SchimbaNume,
    OPTu_SchimbaParola,
    OPTu_AdaugaSuma,
    OPTu_AfiseazaJocuriMagazin,
    OPTu_AfiseazaJocuriLibrarie,
    OPTu_DetaliiJoc,
    OPTu_CumparaJoc,
    OPTu_JoacaJoc,
    OPTu_Iesire = 0
};

void startCLIUtilizator(Utilizator cont) {
    std::cout<<"1: Detalii cont\n";
    std::cout<<"2: Schimbati nume utilizator\n";
    std::cout<<"3: Schimbati parola\n";
    std::cout<<"4: Adaugati fonduri\n";
    std::cout<<"5: Jocuri magazin\n";
    std::cout<<"6: Jocuri librarie\n";
    std::cout<<"7: Detalii joc\n";
    std::cout<<"8: Cumpara joc\n";
    std::cout<<"9: Jucati joc\n";
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
        std::cout<<"4: Adaugati fonduri\n";
        std::cout<<"5: Jocuri magazin\n";
        std::cout<<"6: Jocuri librarie\n";
        std::cout<<"7: Detalii joc\n";
        std::cout<<"8: Cumpara joc\n";
        std::cout<<"9: Jucati joc\n";
        std::cout<<"0: Iesire\n";
        std::cout<<'\n';
        int optiune = stoi(input);
        if (optiune<0 or optiune>9) {
            std::cout<<"Optiune invalida\n";
            continue;
        }
        switch (optiune) {
            case OPTu_DetaliiCont:
                cont.detaliiCont();
                std::cout<<"\n\n";
                continue;
            case OPTu_SchimbaNume:
                cont.schimbaNume();
                std::cout<<"\n\n";
                continue;
            case OPTu_SchimbaParola:
                cont.modificareParola();
                std::cout<<"\n\n";
                continue;
            case OPTu_AdaugaSuma:
                cont.adaugaSuma();
                std::cout<<"\n\n";
                continue;
            case OPTu_AfiseazaJocuriMagazin:
                cont.afiseazaJocuriMagazin();
                std::cout<<"\n\n";
                continue;
            case OPTu_AfiseazaJocuriLibrarie:
                cont.afiseazaJocuriLibrarie();
                std::cout<<"\n\n";
                continue;
            case OPTu_DetaliiJoc:
                cont.detaliiJoc();
                std::cout<<"\n\n";
                continue;
            case OPTu_CumparaJoc:
                cont.cumparaJoc();
                std::cout<<"\n\n";
                continue;
            case OPTu_JoacaJoc:
                cont.joacaJoc();
                std::cout<<"\n\n";
                continue;
            case OPTu_Iesire:
                std::cout<<"Va multumesc pentru timpul acordat\n";
                //timer de 2 secunde
                std::this_thread::sleep_for(std::chrono::seconds(2));
                continua = false;
                break;
        }
    }
}