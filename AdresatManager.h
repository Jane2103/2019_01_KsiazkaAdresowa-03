#ifndef ADRESATMANAGER_H
#define ADRESATMANAGER_H

#include <iostream>
#include <vector>

#include "Adresat.h"
#include "PlikZAdresatami.h"

using namespace std;

class AdresatManager
{
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
    const int idZalogowanegoUzytkownika;
    int idUsunietegoAdresata;

    Adresat podajDaneAdresata();
    void wyswietlDaneNaEkranie(Adresat adresat);
    bool sprawdzCzyAdresatOPodanymIdIstnieje(int nrIdAdresata);

public:
    AdresatManager(string NAZWA_PLIKU_Z_ADRESATAMI, int ID_ZALOGOWANEGO_UZYTKOWNIKA) :
        plikZAdresatami(NAZWA_PLIKU_Z_ADRESATAMI), idZalogowanegoUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA)
    {
        adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownika(idZalogowanegoUzytkownika);
    };
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();

    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();
    void usunAdresata();
    void edytujAdresata();

    int wyswietlMenuEdycjiKontaktu();
    void edytujWybranyKontakt(Adresat &edytowanyAdresat, int wyborUzytkownika);
};

#endif
