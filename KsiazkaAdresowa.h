#ifndef KSIAZKAADRESOWA_H
#define KSIAZKADRESOWA_H

#include "UzytkownikManager.h"
#include "AdresatManager.h"
#include "MetodyPomocnicze.h"

#include <iostream>
#include <windows.h>

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikManager uzytkownikManager;
    AdresatManager *adresatManager;
    //const string nazwaPlikuZAdresatami;
    const string NAZWA_PLIKU_Z_ADRESATAMI;

public:
    KsiazkaAdresowa(string NAZWA_PLIKU_Z_UZYTKOWNIKAMI, string nazwaPlikuZAdresatami)
     : uzytkownikManager(NAZWA_PLIKU_Z_UZYTKOWNIKAMI), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {};
    ~KsiazkaAdresowa()
    {
        delete adresatManager;
    }
    void zarejestrujUzytkownika();
    void zalogujUzytkownika();
    void wylogujUzytkownika();
    void zmienHaslo();
    void wyswietlMenuPoStarcieProgramu();
    void wyswietlMenuPoZalogowaniu();
};

#endif
