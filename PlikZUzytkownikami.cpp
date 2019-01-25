#include "PlikZUzytkownikami.h"

string PlikZUzytkownikami::przypiszDaneUzytkownikaDoLinii(Uzytkownik uzytkownik)
{
    string liniaZDanymiUzytkownika = "";
    liniaZDanymiUzytkownika += MetodyPomocnicze::konwertujIntNaStr(uzytkownik.pobierzIdUzytkownika()) + '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzLogin() + '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzHaslo() + '|';

    return liniaZDanymiUzytkownika;
}

void PlikZUzytkownikami::zapiszUzytkownikaDoPliku(Uzytkownik uzytkownik)
{
    string liniaZDanymiUzytkownika;
    fstream plik;
    plik.open(nazwaPlikuZUzytkownikami.c_str(), ios :: out | ios :: app);

    if (plik.good() == true)
    {
        liniaZDanymiUzytkownika = przypiszDaneUzytkownikaDoLinii(uzytkownik);
        if (MetodyPomocnicze::sprawdzCzyPlikJestPusty() == true)
            plik << liniaZDanymiUzytkownika;
        else
            plik << liniaZDanymiUzytkownika << endl;
        plik.close();
    }
    else
        cout << "Nie udalo sie otworzyc pliku " << nazwaPlikuZUzytkownikami << " i zapisac do niego danych." << endl;
}

vector <Uzytkownik> PlikZUzytkownikami::wczytajUzytkownikowZPliku()
{
    Uzytkownik uzytkownik;
    vector <Uzytkownik> uzytkownicy;
    string liniaTekstu;
    fstream plik;

    plik.open(nazwaPlikuZUzytkownikami.c_str(), ios :: in);
    if (plik.good() == true)
    {
        while (getline(plik, liniaTekstu))
        {
            uzytkownik = przypiszDanePobraneZLinii(liniaTekstu);
            uzytkownicy.push_back(uzytkownik);
        }
        plik.close();
    }

    return uzytkownicy;
}

Uzytkownik PlikZUzytkownikami::przypiszDanePobraneZLinii(string liniaTekstu)
{
    Uzytkownik uzytkownikOdczytanyZPliku;

    int tab[3]; // tablica do przechowywania indeksow znaku oddzielenia
    int j = 0; // indeks tablicy tab
    int rozmiarStringu;
    char znakOddzielenia = '|';
    string tekstPomocniczy;

    rozmiarStringu = liniaTekstu.length();

    for (int i = 0; i < rozmiarStringu; i++)
        if (liniaTekstu[i] == znakOddzielenia)
            tab[j++] = i;

    tekstPomocniczy = liniaTekstu;
    uzytkownikOdczytanyZPliku.ustawIdUzytkownika(atoi(tekstPomocniczy.substr(0, tab[0]).c_str())); //ID

    tekstPomocniczy = liniaTekstu;
    uzytkownikOdczytanyZPliku.ustawLogin(tekstPomocniczy.substr(tab[0] + 1, tab[1] - 2)); // LOGIN

    tekstPomocniczy = liniaTekstu;
    uzytkownikOdczytanyZPliku.ustawHaslo(tekstPomocniczy.substr(tab[1] + 1, tab[2] - tab[1] - 1)); // HASLO

    return uzytkownikOdczytanyZPliku;
}

void PlikZUzytkownikami::zmienHaslo(vector <Uzytkownik> uzytkownicy)
{
    vector <Uzytkownik> :: iterator it;
    fstream plik;
    string liniaZDanymiUzytkownika;
    plik.open(nazwaPlikuZUzytkownikami.c_str(), ios :: out);

    if (plik.good() == true)
    {
        for (it = uzytkownicy.begin(); it != uzytkownicy.end(); it++)
        {
            liniaZDanymiUzytkownika = przypiszDaneUzytkownikaDoLinii(*it);
            if (MetodyPomocnicze::sprawdzCzyPlikJestPusty() == true)
                plik << liniaZDanymiUzytkownika;
            else
                plik << liniaZDanymiUzytkownika << endl;
        }
        plik.close();
        cout << endl << "Haslo zostalo zmienione!" << endl;
    }
    else
        cout << "Nie udalo sie otworzyc pliku " << nazwaPlikuZUzytkownikami << " i zapisac do niego danych." << endl;
}
