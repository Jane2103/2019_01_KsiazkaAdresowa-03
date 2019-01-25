#ifndef PLIKZUZYTKOWNIKAI_H
#define PLIKZUZYTKOWNIKAI_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZUzytkownikami
{
    const string nazwaPlikuZUzytkownikami;

    string przypiszDaneUzytkownikaDoLinii(Uzytkownik uzytkownik);

public:
    PlikZUzytkownikami(string NAZWA_PLIKU_Z_UZYTKOWNIKAMI) : nazwaPlikuZUzytkownikami(NAZWA_PLIKU_Z_UZYTKOWNIKAMI) {};
    void zapiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    vector <Uzytkownik> wczytajUzytkownikowZPliku();
    Uzytkownik przypiszDanePobraneZLinii(string liniaTekstu);
    void zmienHaslo(vector <Uzytkownik> uzytkownicy);
};

#endif
