#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "Adresat.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZAdresatami
{
    const string nazwaPlikuZAdresatami;
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;

    string przypiszDaneAdresataDoLinii(Adresat adresat);
    int sprawdzIdZalogowanegoUzytkownika(string liniaTekstu);
    int sprawdzOstatniNrIdAdresata(string liniaTekstu);
    int sprawdzIdAdresata(string liniaTekstu);
    bool zamienPlikiZKontaktami(string nazwaPlikuTymczasowego);
    void dodajLinieDoPliku(fstream &plikTymczasowy, string liniaTekstu);
    Adresat przypiszDaneAdresataPobraneZLinii(string liniaTekstu, int idZalogowanegoUzytkownika);

public:
    PlikZAdresatami(string NAZWA_PLIKU_Z_ADRESATAMI) : nazwaPlikuZAdresatami(NAZWA_PLIKU_Z_ADRESATAMI) {};
    void zapiszAdresataDoPliku(Adresat adresat);
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownika(int idZalogowanegoUzytkownika);

    int pobierzIdOstatniegoAdresata();
    void usunAdresata(vector <Adresat> adresaci, int nrIdAdresataDoUsuniecia, int idZalogowanegoUzytkownika);
    void edytujAdresata(Adresat edytowanyAdresat);

};

#endif
