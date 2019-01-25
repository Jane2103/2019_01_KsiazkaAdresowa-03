#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

#include <iostream>

using namespace std;

class Uzytkownik
{
    int idUzytkownika;
    string login, haslo;

public:
    void ustawIdUzytkownika(int noweId);
    void ustawLogin(string nowyLogin);
    void ustawHaslo(string noweHaslo);

    int pobierzIdUzytkownika();
    string pobierzLogin();
    string pobierzHaslo();
};

#endif
