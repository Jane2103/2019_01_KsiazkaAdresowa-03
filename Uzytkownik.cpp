#include "Uzytkownik.h"

void Uzytkownik::ustawIdUzytkownika(int noweId)
{
    if (noweId >= 0)
        idUzytkownika = noweId;
}

void Uzytkownik::ustawLogin(string nowyLogin)
{
    login = nowyLogin;
}

void Uzytkownik::ustawHaslo(string noweHaslo)
{
    haslo = noweHaslo;
}

int Uzytkownik::pobierzIdUzytkownika()
{
    return idUzytkownika;
}

string Uzytkownik::pobierzLogin()
{
    return login;
}

string Uzytkownik::pobierzHaslo()
{
    return haslo;
}
