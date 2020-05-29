//
//  main.cpp
//  projekt
//  G++, Xcode
//  Created by Roman Dykyj on 04.12.2017.
//  Copyright © 2017 Roman Dykyj. All rights reserved.
//  POP_2017_12_15_projekt_1_Dykyj_Roman_EiT_1_171584

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;


const int wys_planszy=8;         //do zmienienia z poziomu programu
const int szer_planszy=11;      //do zmienienia z poziomu programu
const int liczba_min=3;         //do zmienienia z poziomu programu
string plansza[wys_planszy][szer_planszy];
int wspol_pionka_X = 0;
int wspol_pionka_Y = wys_planszy-1;
char klawisz;
int pola_odwiedzone_X = 0;
int pola_odwiedzone_Y = wys_planszy-1;
int radar_X = 0;
int radar_Y = wys_planszy-1;
bool stan1 = false;
bool stan2 = false;
bool stan3 = false;
bool stan4 = false;
bool losowanie = false;
struct wspolrzedne_min
{
    int x;
    int y;
};
wspolrzedne_min miny[liczba_min];





void generowanie_wspl_min()
{
    srand((unsigned int)time(NULL));
    while (losowanie!=true) {
        for (int i=0; i<liczba_min; i++) {
            miny[i].x = rand()%szer_planszy;
            miny[i].y = rand()%wys_planszy;
        }
        for (int i=0; i<liczba_min; i++) {
            if ((miny[i].x==0 and miny[i].y==wys_planszy-1) or (miny[i].x==szer_planszy-1 and miny[i].y==0) or (miny[i].x==1 and miny[i].y==wys_planszy-1) or (miny[i].x==1 and miny[i].y==wys_planszy-2) or (miny[i].x==0 and miny[i].y==wys_planszy-2) or (miny[i].x==szer_planszy-1 and miny[i].y==1) or (miny[i].x==szer_planszy-2 and miny[i].y==1) or (miny[i].x==szer_planszy-2 and miny[i].y==0)){
                // losowanie trwa dopóki miny znajduja sie na pozycjach innych niz: 1)pozycja startowa 2)pozycja docelowa 3)najblizszy obszar przy pozycji startowej i docelowej
                losowanie=false;
                break;
            }
            else
                losowanie=true;
        }
    }
}


void generowanie_planszy_pocz()
{
    for (int i=0; i<wys_planszy; i++) {
        for (int j=0; j<szer_planszy; j++) {
            plansza[i][j] = "X";
        }
    }
    plansza[wys_planszy-1][0] = "#";
    
    
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    for (int i=0; i<wys_planszy; i++) {
        for (int j=0; j<szer_planszy; j++) {
            cout << setw(4) <<plansza[i][j];
        }
        cout << endl << endl;
    }
}


void sterowanie()
{
    cout << "Ruch zwiadowca (G - gora, D - dol, L - lewo, P - prawo: ";
    cin >> klawisz;
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    switch (klawisz) {
        case 'g':
            if (wspol_pionka_Y-1 == -1) {
                cout << setw((szer_planszy*4)/2 + 11) << "NIE MOZESZ TAK RUSZYC" << endl << endl << endl;
            }
            else
            {
                pola_odwiedzone_Y=wspol_pionka_Y;
                pola_odwiedzone_X=wspol_pionka_X;
                wspol_pionka_Y--;
            }
            break;
        case 'd':
            if (wspol_pionka_Y+1 == wys_planszy) {
                cout << setw((szer_planszy*4)/2 + 11) << "NIE MOZESZ TAK RUSZYC" << endl << endl << endl;
            }
            else
            {
                pola_odwiedzone_Y=wspol_pionka_Y;
                pola_odwiedzone_X=wspol_pionka_X;
                wspol_pionka_Y++;
            }
            break;
        case 'l':
            if (wspol_pionka_X-1 == -1) {
                cout << setw((szer_planszy*4)/2 + 11) << "NIE MOZESZ TAK RUSZYC" << endl << endl << endl;
            }
            else
            {
                pola_odwiedzone_Y=wspol_pionka_Y;
                pola_odwiedzone_X=wspol_pionka_X;
                wspol_pionka_X--;
            }
            break;
        case 'p':
            if (wspol_pionka_X+1 == szer_planszy) {
                cout << setw((szer_planszy*4)/2 + 11) << "NIE MOZESZ TAK RUSZYC" << endl << endl << endl;
            }
            else
            {
                pola_odwiedzone_Y=wspol_pionka_Y;
                pola_odwiedzone_X=wspol_pionka_X;
                wspol_pionka_X++;
            }
            break;
            
        default:
            cout << setw((szer_planszy*4)/2 + 12) << "BRAK TAKIEJ OPCJI W MENU" << endl << endl << endl;
            break;
    }
}


void przypadki_wyniku()
{
    for (int i=0; i<liczba_min; i++) {
        if ((wspol_pionka_X==miny[i].x and wspol_pionka_Y==miny[i].y) or (wspol_pionka_X==szer_planszy-1 and wspol_pionka_Y==0)) { // sprawdza czy peta glowna ma sie zakonczyc
            stan4 = true;
            if (wspol_pionka_X==miny[i].x and wspol_pionka_Y==miny[i].y) { // sprawdza czy nie trafilismy na mine
                stan2 = true;
                break;
            }
            else
            {
                stan2 = false;
            }
            if (wspol_pionka_X==szer_planszy-1 and wspol_pionka_Y==0) { // sprawdza czy wygralismy
                stan3 = true;
                break;
            }
            else
            {
                stan3 = false;
            }
            break;
        }
        else
        {
            stan4 = false;
        }
        
    }
    
}


void przypadki_planszy()
{
    for (int i=0; i<liczba_min; i++) {
        if ((wspol_pionka_X==miny[i].x and wspol_pionka_Y+1==miny[i].y) or (wspol_pionka_X+1==miny[i].x and wspol_pionka_Y==miny[i].y) or (wspol_pionka_X-1==miny[i].x and wspol_pionka_Y==miny[i].y) or (wspol_pionka_X==miny[i].x and wspol_pionka_Y-1==miny[i].y)) //sprawdza czy w poblizu nie ma min
        {
            stan1 = true;
            break;
        }
        else
        {
            stan1 = false;
        }
    }
}


void generowanie_planszy_ruch()
{
    if (stan1==true) //plansza gdy w poblizu miny
    {
        plansza[pola_odwiedzone_Y][pola_odwiedzone_X] = ".";
        plansza[radar_Y][radar_X] = "!";
        plansza[wys_planszy-1][0] = ".";
        plansza[wspol_pionka_Y][wspol_pionka_X] = "#!";
        radar_X=wspol_pionka_X;
        radar_Y=wspol_pionka_Y;
        for (int i=0; i<wys_planszy; i++) {
            for (int j=0; j<szer_planszy; j++) {
                cout << setw(4) <<plansza[i][j];
            }
            cout << endl << endl;
        }
    }
    else //plansza standardowa ( w poblizu nie ma min )
    {
        plansza[pola_odwiedzone_Y][pola_odwiedzone_X] = ".";
        plansza[radar_Y][radar_X] = "!";
        plansza[wys_planszy-1][0] = ".";
        plansza[wspol_pionka_Y][wspol_pionka_X] = "#";
        for (int i=0; i<wys_planszy; i++) {
            for (int j=0; j<szer_planszy; j++) {
                cout << setw(4) <<plansza[i][j];
            }
            cout << endl << endl;
        }
    }
}





int main() {
    generowanie_wspl_min();
    generowanie_planszy_pocz();
    
    while (stan4!=true) { // glowna petla programu
        sterowanie();
        przypadki_wyniku();
        przypadki_planszy();
        generowanie_planszy_ruch();
    }
    
    if (stan2==true) { // uderzenie w mine; rysowanie planszy z minami itd.
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << setw((szer_planszy*4)/2 + 21) << "Zwiadowca uderzyl w mine. PRZEGRALES!!" << endl << endl;
        for (int i=0; i<liczba_min; i++) {
            plansza[miny[i].y][miny[i].x] = "*";
        }
        plansza[wspol_pionka_Y][wspol_pionka_X]="&";
        for (int i=0; i<wys_planszy; i++) {
            for (int j=0; j<szer_planszy; j++) {
                cout << setw(4) <<plansza[i][j];
            }
            cout << endl << endl;
        }
    }
    else if(stan3==true) // dotarcie do punktu docelowego
    {
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << setw((szer_planszy*4)/2 + 4)<< "WYGRALES!" << endl << endl;
    }
    
    return 0;
}

