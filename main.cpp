#include <bits/stdc++.h>
#include "cont.h"
using namespace std;

int main() {
    //creare jocuri
    Joc joc1("GTA V", 1, "17/09/2013", 100);
    Joc joc2("Minecraft", 2, "18/09/2011", 200);
    JocMagazin joc3("Cyberpunk 2077", 2, "10/12/2020", 49.99);
    JocMagazin joc4("Geometry Dash", 322170, "02/06/2020", 20.00);
    //creare librarie
    vector<Joc> jocuri = {joc1, joc2};
    Librarie librarie(jocuri);
    //creare magazin
    vector<JocMagazin> jocuriMagazin = {joc3, joc4};
    Magazin magazin(jocuriMagazin);
    //creare cont
    Cont cont("hex", 0.00, librarie, magazin);

    cout<<"1: Detalii cont\n";
    cout<<"2: Schimbati nume utilizator\n";
    cout<<"3: Adaugati fonduri\n";
    cout<<"4: Jocuri magazin\n";
    cout<<"5: Jocuri librarie\n";
    cout<<"6: Detalii joc\n";
    cout<<"7: Cumpara joc\n";
    cout<<"8: Jucati joc\n";
    cout<<"9: Iesire\n";

    string input;
    bool continua = true;
    while(continua) {
        cout<<"Alegeti o optiune: ";
        cin>>input;
        system("cls");
        cout<<"1: Detalii cont\n";
        cout<<"2: Schimbati nume utilizator\n";
        cout<<"3: Adaugati fonduri\n";
        cout<<"4: Jocuri magazin\n";
        cout<<"5: Jocuri librarie\n";
        cout<<"6: Detalii joc\n";
        cout<<"7: Cumpara joc\n";
        cout<<"8: Jucati joc\n";
        cout<<"9: Iesire\n";
        cout<<'\n';
        int optiune = stoi(input);
        if (optiune<1 or optiune>9) {
            cout<<"Optiune invalida\n";
            continue;
        }
        switch (optiune) {
            case 1:
                cont.detaliiCont();
                cout<<"\n\n";
                continue;
            case 2:
                cont.schimbaNume();
                cout<<"\n\n";
                continue;
            case 3:
                cont.adaugaSuma();
                cout<<"\n\n";
                continue;
            case 4:
                cont.afiseazaJocuriMagazin();
                cout<<"\n\n";
                continue;
            case 5:
                cont.afiseazaJocuriLibrarie();
                cout<<"\n\n";
                continue;
            case 6:
                cont.detaliiJoc();
                cout<<"\n\n";
                continue;
            case 7:
                cont.cumparaJoc();
                cout<<"\n\n";
                continue;
            case 8:
                cont.joacaJoc();
                cout<<"\n\n";
                continue;
            case 9:
                cout<<"Va multumesc pentru timpul acordat\n";
                //timer de 2 secunde
                this_thread::sleep_for(chrono::seconds(2));
                continua = false;
                break;
        }
    }
    return 0;
}