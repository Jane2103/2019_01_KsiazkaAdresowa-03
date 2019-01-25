#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::zarejestrujUzytkownika()
{
    uzytkownikManager.zarejestrujUzytkownika();
}

void KsiazkaAdresowa::zalogujUzytkownika()
{
    uzytkownikManager.zalogujUzytkownika();
    if (uzytkownikManager.sprawdzCzyUzytkownikZalogowany())
    {
        adresatManager = new AdresatManager(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikManager.pobierzIdZalogowanegoUzytkownika());
        while (uzytkownikManager.sprawdzCzyUzytkownikZalogowany())
            wyswietlMenuPoZalogowaniu();
    }
    else
        system("cls");
}

void KsiazkaAdresowa::wylogujUzytkownika()
{
    uzytkownikManager.wylogujUzytkownika();
    cout << "Uzytkownik wylogowany" << endl;
    cout << endl;
    system("pause");
    wyswietlMenuPoStarcieProgramu();
    delete adresatManager;
}

void KsiazkaAdresowa::zmienHaslo()
{
    uzytkownikManager.zmienHaslo();
}

void KsiazkaAdresowa::wyswietlMenuPoStarcieProgramu()
{
    char wybor;

    while (true)
    {
        system("cls");

        cout << "\tMENU GLOWNE" << endl;
        cout << "------------------------------" << endl;
        cout << "(1) Logowanie" << endl;
        cout << "(2) Rejestracja" << endl;
        cout << "(3) Zamknij program" << endl;
        cout << "------------------------------" << endl;

        cout << "Twoj wybor: ";
        cin >> wybor;

        cout << "------------------------------" << endl;

        switch (wybor)
        {
        case '1':
            zalogujUzytkownika();
            break;
        case '2':
            zarejestrujUzytkownika();
            break;
        case '3':
            MetodyPomocnicze::zakonczProgram();
            break;
        }
    }
}

void KsiazkaAdresowa::wyswietlMenuPoZalogowaniu()
{
    char wybor;
    system("cls");

    cout << "\tKSIAZKA ADRESOWA" << endl;
    cout << "Zarejestrowany uzytkownik: ID " << uzytkownikManager.pobierzIdZalogowanegoUzytkownika() << endl;

    cout << "------------------------------" << endl;
    cout << "(1) Dodaj kontakt." << endl;
    cout << "(2) Znajdz kontakt (filtruj wg imion)." << endl;
    cout << "(3) Znajdz kontakt (filtruj wg nazwisk)." << endl;
    cout << "(4) Wyswietl wszystkie kontakty." << endl;
    cout << "(5) Usun adresata." << endl;
    cout << "(6) Edytuj adresata." << endl;
    cout << "(7) Zmien haslo." << endl;
    cout << "(8) Wyloguj sie." << endl;
    cout << "(9) Zakoncz program." << endl;
    cout << "------------------------------" << endl;

    cout << "Twoj wybor: ";
    cin >> wybor;

    cout << "------------------------------" << endl;

    switch(wybor)
    {
    case '1':
        adresatManager -> dodajAdresata();
        break;
    case '2':
        adresatManager -> wyszukajAdresatowPoImieniu();
        break;
    case '3':
        adresatManager -> wyszukajAdresatowPoNazwisku();
        break;
    case '4':
        adresatManager -> wyswietlWszystkichAdresatow();
        break;
    case '5':
        adresatManager -> usunAdresata();
        break;
    case '6':
        adresatManager -> edytujAdresata();
        break;
    case '7':
        uzytkownikManager.zmienHaslo();
        break;
    case '8':
        wylogujUzytkownika();
        break;
    case '9':
        MetodyPomocnicze::zakonczProgram();
        break;
    }
}
