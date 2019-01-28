#include "AdresatManager.h"

void AdresatManager::dodajAdresata()
{
    Adresat adresat = podajDaneAdresata();
    adresaci.push_back(adresat);
    plikZAdresatami.zapiszAdresataDoPliku(adresat);

    cout << endl << "Nowy kontakt zostal zapisany!" << endl << endl;
    system("pause");
}

Adresat AdresatManager::podajDaneAdresata()
{
    Adresat adresat;
    string noweImie;
    string noweNazwisko;
    string nowyNrTelefonu;
    string nowyEmail;
    string nowyAdres;

    adresat.ustawIdAdresata(plikZAdresatami.pobierzIdOstatniegoAdresata() + 1);
    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);

    cout << "Imie: ";
    cin >> noweImie;
    adresat.ustawImie(noweImie);

    cout << "Nazwisko: ";
    cin >> noweNazwisko;
    adresat.ustawNazwisko(noweNazwisko);

    cout << "Nr telefonu: ";
    cin.sync();
    getline(cin, nowyNrTelefonu);
    adresat.ustawNumerTelefonu(nowyNrTelefonu);

    cout << "Email: ";
    cin >> nowyEmail;
    adresat.ustawEmail(nowyEmail);

    cout << "Adres: ";
    cin.sync();
    getline(cin, nowyAdres);
    adresat.ustawAdres(nowyAdres);

    return adresat;
}

void AdresatManager::wyswietlWszystkichAdresatow()
{
    vector <Adresat> :: iterator it;
    if (adresaci.empty() == true)
        cout << "Zalogowany uzytkownik nie posiada zapisanych kontaktow" << endl;
    else
    {
        cout << "Lista kontaktow uzytkownika o numerze ID: " << idZalogowanegoUzytkownika << endl;

        for (it = adresaci.begin(); it != adresaci.end(); it++)
            wyswietlDaneNaEkranie(*it);
    }
    cout << endl;
    system("pause");
}

void AdresatManager::wyszukajAdresatowPoImieniu()
{
    if (adresaci.empty() == false)
    {
        vector <Adresat> :: iterator it;
        int licznikWystapieniaImienia = 0;
        string imieDoWyszukania;
        cout << "Podaj imie: ";
        cin >> imieDoWyszukania;

        for (it = adresaci.begin(); it != adresaci.end(); it++)
        {
            if (it -> pobierzImie() == imieDoWyszukania)
            {
                wyswietlDaneNaEkranie(*it);
                licznikWystapieniaImienia++;
            }
        }
        if (licznikWystapieniaImienia == 0)
            cout << "\nBrak kontaktow o tym imieniu.\n" << endl;
    }
    else
        cout << "Zalogowany uzytkownik nie posiada zapisanych kontaktow." << endl;
    cout << endl;
    system("pause");
}

void AdresatManager::wyszukajAdresatowPoNazwisku()
{
    if (adresaci.empty() == false)
    {
        vector <Adresat> :: iterator it;
        int licznikWystapieniaNazwiska = 0;
        string nazwiskoDoWyszukania;
        cout << "Podaj nazwisko: ";
        cin >> nazwiskoDoWyszukania;

        for (it = adresaci.begin(); it != adresaci.end(); it++)
        {
            if (it -> pobierzNazwisko() == nazwiskoDoWyszukania)
            {
                wyswietlDaneNaEkranie(*it);
                licznikWystapieniaNazwiska++;
            }
        }
        if (licznikWystapieniaNazwiska == 0)
            cout << "\nBrak kontaktow o tym imieniu.\n" << endl;
    }
    else
        cout << "Zalogowany uzytkownik nie posiada zapisanych kontaktow." << endl;
    cout << endl;
    system("pause");
}

void AdresatManager::wyswietlDaneNaEkranie(Adresat adresat)
{
    cout << endl;
    cout << "ID: \t\t" << adresat.pobierzId() << endl;
    cout << "IMIE: \t\t" << adresat.pobierzImie() << endl;
    cout << "NAZWISKO: \t" << adresat.pobierzNazwisko() << endl;
    cout << "TELEFON: \t" << adresat.pobierzNumerTelefonu() << endl;
    cout << "EMAIL: \t\t" << adresat.pobierzEmail() << endl;
    cout << "ADRES: \t\t" << adresat.pobierzAdres() << endl;
    cout << endl;
}

bool AdresatManager::sprawdzCzyAdresatOPodanymIdIstnieje(int nrIdAdresata)
{
    vector <Adresat> :: iterator it;
    bool adresatOPodanymIdIstnieje = false;
    for (it = adresaci.begin(); it != adresaci.end(); it++)
    {
        if (nrIdAdresata == it -> pobierzId())
        {
            adresatOPodanymIdIstnieje = true;
            break;
        }
    }
    return adresatOPodanymIdIstnieje;
}

void AdresatManager::usunAdresata()
{
    int nrIdAdresataDoUsuniecia;
    char znakOdpowiedzi;
    int indeksAdresataDoUsunieciaZWektora;
    int rozmiarWektoraAdresaci = adresaci.size();
    vector <Adresat> :: iterator it;

    cout << "Podaj ID adresata do usuniecia: ";
    cin >> nrIdAdresataDoUsuniecia;

    if (sprawdzCzyAdresatOPodanymIdIstnieje(nrIdAdresataDoUsuniecia))
    {
        cout << "Na pewno chcesz usunac kontakt o numerze ID: " << nrIdAdresataDoUsuniecia << "? (t/n) ";
        cin >> znakOdpowiedzi;
        if (znakOdpowiedzi == 't' || znakOdpowiedzi == 'T')
        {
            for (int i = 0; i < rozmiarWektoraAdresaci; i++)
            {
                if (nrIdAdresataDoUsuniecia == adresaci[i].pobierzId())
                    indeksAdresataDoUsunieciaZWektora = i;
            }
            adresaci.erase(adresaci.begin() + indeksAdresataDoUsunieciaZWektora);
            plikZAdresatami.usunAdresata(nrIdAdresataDoUsuniecia);
        }
        else
            system("cls");
    }
    else
    {
        cout << "Brak kontaktu o podanym ID dla zalogowanego uzytkownika." << endl;
        Sleep(1000);
    }
}

int AdresatManager::wyswietlMenuEdycjiKontaktu()
{
    int wyborUzytkownika;
    cout << "\n\tMENU EDYCJI KONTAKTU" << endl;
    cout << "------------------------------" << endl;
    cout << "(1) imie" << endl;
    cout << "(2) nazwisko" << endl;
    cout << "(3) numer telefonu" << endl;
    cout << "(4) email" << endl;
    cout << "(5) adres" << endl;
    cout << "(6) powrot do menu glownego" << endl;
    cout << "------------------------------" << endl;
    cout << "Twoj wybor: ";
    cin >> wyborUzytkownika;
    cout << "------------------------------" << endl;
    if (wyborUzytkownika < 1 || wyborUzytkownika > 5)
    {
        wyborUzytkownika = 0;
        system("cls");
    }
    return wyborUzytkownika;
}

void AdresatManager::edytujWybranyKontakt(Adresat &edytowanyAdresat, int wyborUzytkownika)
{
    switch (wyborUzytkownika)
    {
    case 1:
    {
        string imie;
        cout << "Zmien imie: ";
        cin >> imie;
        edytowanyAdresat.ustawImie(imie);
        cout << endl;
        break;
    }
    case 2:
    {
        string nazwisko;
        cout << "Zmien nazwisko: ";
        cin >> nazwisko;
        edytowanyAdresat.ustawNazwisko(nazwisko);
        cout << endl;
        break;
    }
    case 3:
    {
        string numerTelefonu;
        cout << "Zmien numer telefonu: ";
        cin.sync();
        getline(cin, numerTelefonu);
        edytowanyAdresat.ustawNumerTelefonu(numerTelefonu);
        cout << endl;
        break;
    }
    case 4:
    {
        string email;
        cout << "Zmien email: ";
        cin.sync();
        getline(cin, email);
        edytowanyAdresat.ustawEmail(email);
        cout << endl;
        break;
    }
    case 5:
    {
        string adres;
        cout << "Zmien adres: ";
        cin.sync();
        getline(cin, adres);
        edytowanyAdresat.ustawAdres(adres);
        cout << endl;
        break;
    }
    }
}

void AdresatManager::edytujAdresata()
{
    cout << "--------------------" << endl;
    cout << "TRYB EDYCJI ADRESATA" << endl;
    cout << "--------------------" << endl;
    wyswietlWszystkichAdresatow();
    cout << endl;

    int nrIdAdresataDoEdycji;
    vector <Adresat> :: iterator it;
    char znakOdpowiedzi;
    cout << "Wybierz nr ID do edycji: ";
    cin >> nrIdAdresataDoEdycji;
    cout << endl;

    if (sprawdzCzyAdresatOPodanymIdIstnieje(nrIdAdresataDoEdycji))
    {
        cout << "--------------------" << endl;
        cout << "DANE ADRESATA DO EDYCJI" << endl;
        cout << "--------------------" << endl;

        for (it = adresaci.begin(); it != adresaci.end(); it++)
        {
            if (nrIdAdresataDoEdycji == it -> pobierzId())
            {
                wyswietlDaneNaEkranie(*it);
                int wyborUzytkownika = wyswietlMenuEdycjiKontaktu();
                if (wyborUzytkownika)
                {
                    edytujWybranyKontakt(*it, wyborUzytkownika);

                    cout << endl;
                    cout << "Czy chcesz zapisac zmiany dla adresata?: (t/n) ";
                    cin >> znakOdpowiedzi;
                    if (znakOdpowiedzi == 't' || znakOdpowiedzi == 'T')
                    {
                        plikZAdresatami.edytujAdresata(*it);
                        break;
                    }
                    else
                        system("cls");
                }
                break;
            }
        }
    }
    else
    {
        cout << "Brak kontaktu o podanym ID dla zalogowanego uzytkownika." << endl;
        Sleep(1000);
    }
}
