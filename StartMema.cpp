//#include <sdl\SDL.h>

// jest to wstep do zrobienia algorytmu ale do bani :P
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

using namespace std;

const int szerokosc = 49;  
const int wysokosc = 49;


/*
void StartMema(char tablica[szerokosc][wysokosc]){ // wybranie startu i mety mozna zmienic

    int wiersz,kolumna;

    cout << "gdzie ma bys start ? ";
            cin >> wiersz;
            while (wiersz < 0 || wiersz >= szerokosc)
            {
                cout << "Wybierz wiersz od 0 do " << (szerokosc - 1) << ".\n";
                cout << "wiersz? ";
                cin >> wiersz;
            }

            cout << "kolumna? ";
            cin >> kolumna;
            while (kolumna < 0 || kolumna >= wysokosc)
            {
                cout << "Wybierz kolumne od 0 do " << (wysokosc - 1) << ".\n";
                cout << "kolumna? ";
                cin >> kolumna;
            }

            tablica[wiersz][kolumna]='S'; //wejscie

            cout << "gdzie ma bys meta ? ";
            cin >> wiersz;
            while (wiersz < 0 || wiersz >= szerokosc)
            {
                cout << "Wybierz wiersz od 0 do " << (szerokosc - 1) << ".\n";
                cout << "wiersz? ";
                cin >> wiersz;
            }

            cout << "kolumna? ";
            cin >> kolumna;
            while (kolumna < 0 || kolumna >= wysokosc)
            {
                cout << "Wybierz kolumne od 0 do " << (wysokosc - 1) << ".\n";
                cout << "kolumna? ";
                cin >> kolumna;
            }

     
    tablica[wiersz][kolumna]='M'; // wyjscie

}
*/

int main(int argc, char **arfv){


    int wybor=0;
    srand((int)time(0));

    char ludek[szerokosc][wysokosc];
    char tablica[szerokosc][wysokosc];
//    char tmpludek;






//************************************************************************************
// tworzy labirynt
//    int wybor;
    for(int i=0;i<wysokosc;i++)
        for(int j=0;j<szerokosc;j++) // zape³nia ca³a tablice sciana
        {
            ludek[j][i]='X';
            tablica[j][i]='X';
        }

    for(int i=1;i<wysokosc-1;i+=2)
        for(int j=1;j<szerokosc-1;j+=2) // Co 2 pole wstawia w tablicy wstawia puste miejsce
        {tablica[j][i]=' ';ludek[j][i]=' ';}

    for(int i=2;i<wysokosc-1;i+=2)
        for(int j=1;j<szerokosc-1;j+=2) //Jedzie od gory i od prawej strony co 2 kratke i losuje czy ma zostac sciana czy puste miejsce
        {
            wybor=rand()%2;
            if(wybor)tablica[j][i]=' ';
            if(wybor)ludek[j][i]=' ';
        }

    for(int i=1;i<wysokosc-1;i+=2)
        for(int j=2;j<szerokosc;j+=2)
        {
            wybor=rand()%2;
            if(wybor)tablica[j][i]=' ';
            if(wybor)ludek[j][i]=' ';
        }

    for(int i=1;i<wysokosc-1;i+=2)
        for(int j=2;j<szerokosc;j+=2)
        {
            wybor=rand()%2;
            if(wybor)tablica[j][i]=' ';
            if(wybor)ludek[j][i]=' ';
        }

//*************************************************************************

        //wyswietla labirynt


// ***************************************************************************
    //    szuka drogi

    int idz1=1,idz2=1;
    tablica[idz1][idz2] = 'L';
    ludek[idz1][idz2] = 'L';

    tablica[46][46] = 'M';
    tablica[46][46] = 'M';
//system("cls");
//*************************************************************************

        //wyswietla labirynt
    for(int i=0;i<wysokosc;i++)
    {
        for(int j=0;j<szerokosc;j++)cout << tablica[i][j] ;
        cout << endl;
    }
    system("Pause");

// ***************************************************************************

 //int lewaSciana,prawaSciana,gornaSciana,dolnaSciana;
    bool meta,boolLewaSciana,boolPrawaSciana,boolGornaSciana,boolDolnaSciana;
    int losuj;




    meta=false;


    wybor=rand()%4+1;
while(meta== false)
{
    system("cls");
    boolLewaSciana=true;
    boolPrawaSciana=true;
    boolGornaSciana=true;
    boolDolnaSciana=true;

    if (idz1==48 && idz2==48) {meta=true; }

    int iloscscian=0;
        if (ludek[idz1-1][idz2]==' ' || ludek[idz1-1][idz2]=='/' ) boolLewaSciana=false; else iloscscian++;
        if (ludek[idz1][idz2-1]==' ' || ludek[idz1][idz2-1]=='/' ) boolGornaSciana=false; else iloscscian++;
        if (ludek[idz1+1][idz2]==' ' || ludek[idz1+1][idz2]=='/') boolPrawaSciana=false; else iloscscian++;
        if (ludek[idz1][idz2+1]==' ' || ludek[idz1][idz2+1]=='/') boolDolnaSciana=false; else iloscscian++;

    if ( iloscscian == 4 ) {cout << "nie ma ruchu zly labirynt";  break; }
        else if (iloscscian == 3)
            {
                if (ludek[idz1-1][idz2]==' ' || ludek[idz1-1][idz2]=='/') {tablica[idz1][idz2]='/'; tablica[idz1-1][idz2]='L'; ludek[idz1][idz2]='*'; idz1-=1;}
                if (ludek[idz1][idz2-1]==' ' || ludek[idz1][idz2-1]=='/') {tablica[idz1][idz2]='/'; tablica[idz1][idz2-1]='L'; ludek[idz1][idz2]='*'; idz2-=1;}
                if (ludek[idz1+1][idz2]==' ' || ludek[idz1+1][idz2]=='/') {tablica[idz1][idz2]='/'; tablica[idz1+1][idz2]='L'; ludek[idz1][idz2]='*'; idz1+=1;}
                if (ludek[idz1][idz2+1]==' ' || ludek[idz1][idz2+1]=='/') {tablica[idz1][idz2]='/'; tablica[idz1][idz2+1]='L'; ludek[idz1][idz2]='*'; idz2+=1;}
                wybor=rand()%4+1;
            }
            else {
                losuj=0;
                while(losuj==0)
                {
                    //wybor=rand()%4+1;
                        switch(wybor)
                    {
                        case 1://lewo
                        if(boolLewaSciana==false){
                        tablica[idz1][idz2]='/';
                        tablica[idz1-1][idz2]='L';
                        idz1-=1;
                        losuj++;
                        }else wybor=rand()%4+1;
                        break;
                        case 2://gora
                        if(boolGornaSciana==false){
                        tablica[idz1][idz2]='/';
                        tablica[idz1][idz2-1]='L';
                        idz2-=1;
                        losuj++;
                        }else wybor=rand()%4+1;
                        break;
                        case 3:
                        if(boolPrawaSciana==false){
                        tablica[idz1][idz2]='/';
                        tablica[idz1+1][idz2]='L';
                        idz1+=1;
                        losuj++;
                        }else wybor=rand()%4+1;
                        break;
                        case 4:
                        if(boolDolnaSciana==false){
                        tablica[idz1][idz2]='/';
                        tablica[idz1][idz2+1]='L';
                        idz2+=1;
                        losuj++;
                        }else wybor=rand()%4+1;
                        break;

                    }


                }
            }


//*************************************************************************

        //wyswietla labirynt
    for(int i=0;i<wysokosc;i++)
    {
        for(int j=0;j<szerokosc;j++)cout << tablica[i][j] ;
        cout << endl;
    }

// ***************************************************************************

    Sleep(1000);
//system("Pause");
}





system("Pause");











}
