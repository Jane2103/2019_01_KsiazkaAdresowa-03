#ifndef UZYTKOWNIKMANAGER_H
#define UZYTKOWNIKMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"

using namespace std;

class UzytkownikManager
{
    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;
    PlikZUzytkownikami plikZUzytkownikami;

    Uzytkownik podajDaneNowegoUzytkownika();
    bool sprawdzCzyIstniejeLogin(string login);
    int pobierzIdNowegoUzytkownika();

public:
    UzytkownikManager(string NAZWA_PLIKU_Z_UZYTKOWNIKAMI) : plikZUzytkownikami(NAZWA_PLIKU_Z_UZYTKOWNIKAMI)
    {
        uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
    };
    void zarejestrujUzytkownika();
    void zalogujUzytkownika();
    void wylogujUzytkownika();
    bool sprawdzCzyUzytkownikZalogowany();
    int pobierzIdZalogowanegoUzytkownika();
    void zmienHaslo();
};

#endif
