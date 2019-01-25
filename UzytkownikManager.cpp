#include "UzytkownikManager.h"

void UzytkownikManager::zarejestrujUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.zapiszUzytkownikaDoPliku(uzytkownik);
    cout << endl << "Uzytkownik zostal zarejestrowany!" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikManager::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;
    string login, haslo;
    uzytkownik.ustawIdUzytkownika(pobierzIdNowegoUzytkownika());
    do
    {
        cout << "Podaj login: ";
        cin >> login;
        uzytkownik.ustawLogin(login);
    }
    while (sprawdzCzyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    cout << "Podaj haslo: ";
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

bool UzytkownikManager::sprawdzCzyIstniejeLogin(string login)
{
    int rozmiarWektoraUzytkownicy = uzytkownicy.size();
    for (int i = 0; i < rozmiarWektoraUzytkownicy; i++)
    {
        if (uzytkownicy[i].pobierzLogin() == login)
        {
            cout << "Podany login jest juz zajety." << endl;
            return true;
        }
    }
    return false;
}

int UzytkownikManager::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzIdUzytkownika() + 1;
}

void UzytkownikManager::zmienHaslo()
{
    vector <Uzytkownik> :: iterator it;
    string noweHaslo;
    for (it = uzytkownicy.begin(); it != uzytkownicy.end(); it++)
    {
        if (idZalogowanegoUzytkownika == it -> pobierzIdUzytkownika())
        {
            cout << "Podaj nowe haslo: ";
            cin >> noweHaslo;
            it -> ustawHaslo(noweHaslo);
        }
    }
    plikZUzytkownikami.zmienHaslo(uzytkownicy);
    system("pause");
}

void UzytkownikManager::zalogujUzytkownika()
{
    if (uzytkownicy.empty() == false)
    {
        vector <Uzytkownik> :: iterator it;
        string login, haslo;

        cout << "Login: ";
        cin >> login;
        cout << "Haslo: ";
        cin >> haslo;

        for (it = uzytkownicy.begin(); it != uzytkownicy.end(); it++)
        {
            if (login == it -> pobierzLogin())
            {
                if (haslo == it -> pobierzHaslo())
                {
                    idZalogowanegoUzytkownika = it -> pobierzIdUzytkownika();
                    break;
                }
                else
                    idZalogowanegoUzytkownika = 0;
            }
            else
                idZalogowanegoUzytkownika = 0;
        }

        if (idZalogowanegoUzytkownika > 0)
            cout << endl << "Uzytkownik zalogowany!" << endl;
        else
            cout << endl << "Nieprawidlowy login lub haslo!" << endl;

        cout << endl;
        system("pause");
    }
    else
    {
        cout << "Brak zarejestrowanych uzytkownikow." << endl;
        Sleep(1000);
        idZalogowanegoUzytkownika = 0;
    }
}

void UzytkownikManager::wylogujUzytkownika()
{
    idZalogowanegoUzytkownika = 0;

}

bool UzytkownikManager::sprawdzCzyUzytkownikZalogowany()
{
    if (idZalogowanegoUzytkownika > 0)
        return true;
    else
        return false;
}

int UzytkownikManager::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}

