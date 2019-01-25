#include "PlikZAdresatami.h"

vector <Adresat> PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownika(int idZalogowanegoUzytkownika)
{
    Adresat adresat;
    vector <Adresat> adresaci;
    string liniaTekstu;
    fstream plik;

    plik.open(nazwaPlikuZAdresatami.c_str(), ios :: in);
    if (plik.good() == true)
    {
        while (getline(plik, liniaTekstu))
        {
            adresat = przypiszDaneAdresataPobraneZLinii(liniaTekstu, idZalogowanegoUzytkownika);
            idOstatniegoAdresata = sprawdzOstatniNrIdAdresata(liniaTekstu);
            if (sprawdzIdZalogowanegoUzytkownika(liniaTekstu) == idZalogowanegoUzytkownika)
                adresaci.push_back(adresat);
        }
        plik.close();
    }
    else
        idOstatniegoAdresata = 0;

    return adresaci;
}

string PlikZAdresatami::przypiszDaneAdresataDoLinii(Adresat adresat)
{
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwertujIntNaStr(adresat.pobierzId()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwertujIntNaStr(adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}

Adresat PlikZAdresatami::przypiszDaneAdresataPobraneZLinii(string liniaTekstu, int idZalogowanegoUzytkownika)
{
    Adresat adresat;

    int tab[7]; // tablica do przechowywania indeksow znaku oddzielenia
    int j = 0; // indeks tablicy tab
    int rozmiarStringu; //zmienna pomocnicza
    char znakOddzielenia = '|';
    int przesuniecieIndeksuZnakuOddzielenia; //zmienna pomocnicza
    string tekstPomocniczy; //zmienna pomocnicza

    rozmiarStringu = liniaTekstu.length();

    for (int i = 0; i < rozmiarStringu; i++)
        if (liniaTekstu[i] == znakOddzielenia)
            tab[j++] = i;

    tekstPomocniczy = liniaTekstu;
    adresat.ustawIdAdresata(atoi(tekstPomocniczy.substr(0, tab[0]).c_str())); // ID

    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);

    if (atoi(tekstPomocniczy.substr(0, tab[0]).c_str()) < 10)
        przesuniecieIndeksuZnakuOddzielenia = 4;
    else if (atoi(tekstPomocniczy.substr(0, tab[0]).c_str()) > 9)
        przesuniecieIndeksuZnakuOddzielenia = 5;

    tekstPomocniczy = liniaTekstu;
    adresat.ustawImie(tekstPomocniczy.substr(tab[1] + 1, tab[2] - przesuniecieIndeksuZnakuOddzielenia)); //IMIE

    tekstPomocniczy = liniaTekstu;
    adresat.ustawNazwisko(tekstPomocniczy.substr(tab[2] + 1, tab[3] - tab[2] - 1)); //NAZWISKO

    tekstPomocniczy = liniaTekstu;
    adresat.ustawNumerTelefonu(tekstPomocniczy.substr(tab[3] + 1, tab[4] - tab[3] - 1)); //NUMER TELEFONU

    tekstPomocniczy = liniaTekstu;
    adresat.ustawEmail(tekstPomocniczy.substr(tab[4] + 1, tab[5] - tab[4] - 1)); //EMAIL

    tekstPomocniczy = liniaTekstu;
    adresat.ustawAdres(tekstPomocniczy.substr(tab[5] + 1, tab[6] - tab[5] - 1)); //ADRES

    return adresat;
}

int PlikZAdresatami::sprawdzOstatniNrIdAdresata(string liniaTekstu)
{
    string liczbaDoKonwersji;
    int liczbaPoKonwersji;
    char znakOddzielenia = '|';
    int indeksZnakuOddzielenia;

    indeksZnakuOddzielenia = liniaTekstu.find(znakOddzielenia);
    liczbaDoKonwersji = liniaTekstu.erase(indeksZnakuOddzielenia);
    liczbaPoKonwersji = atoi(liczbaDoKonwersji.erase(indeksZnakuOddzielenia).c_str());
    return liczbaPoKonwersji;
}

int PlikZAdresatami::sprawdzIdZalogowanegoUzytkownika(string liniaTekstu)
{
    string liczbaDoKonwersji;
    int liczbaPoKonwersji;
    char znakOddzielenia = '|';
    int indeksZnakuOddzielenia;

    indeksZnakuOddzielenia = liniaTekstu.find(znakOddzielenia);
    liczbaDoKonwersji = liniaTekstu.substr(indeksZnakuOddzielenia + 1);

    indeksZnakuOddzielenia = liczbaDoKonwersji.find(znakOddzielenia);
    liczbaDoKonwersji.erase(indeksZnakuOddzielenia);
    liczbaPoKonwersji = atoi(liczbaDoKonwersji.erase(indeksZnakuOddzielenia).c_str());

    return liczbaPoKonwersji;
}

int PlikZAdresatami::sprawdzIdAdresata(string liniaTekstu)
{
    string liczbaDoKonwersji;
    int liczbaPoKonwersji;
    char znakOddzielenia = '|';
    int indeksZnakuOddzielenia = liniaTekstu.find(znakOddzielenia);
    liczbaDoKonwersji = liniaTekstu.erase(indeksZnakuOddzielenia);
    liczbaPoKonwersji = atoi(liczbaDoKonwersji.c_str());

    return liczbaPoKonwersji;
}

void PlikZAdresatami::zapiszAdresataDoPliku(Adresat adresat)
{
    string liniaZDanymiAdresata;
    fstream plik;
    plik.open(nazwaPlikuZAdresatami.c_str(), ios :: out | ios :: app);

    if (plik.good() == true)
    {
        liniaZDanymiAdresata = przypiszDaneAdresataDoLinii(adresat);
        dodajLinieDoPliku(plik, liniaZDanymiAdresata);
        plik.close();
        idOstatniegoAdresata++;
    }
    else
        cout << "Nie udalo sie otworzyc pliku " << nazwaPlikuZAdresatami << " i zapisac do niego danych." << endl;
}

int PlikZAdresatami::pobierzIdOstatniegoAdresata()
{
    return idOstatniegoAdresata;
}

bool PlikZAdresatami::zamienPlikiZKontaktami(string nazwaPlikuTymczasowego)
{
    bool czyUsunietoPlikOryginalny, czyZamienionoNazwyPlikow;

    if (remove(nazwaPlikuZAdresatami.c_str()) == 0)
        czyUsunietoPlikOryginalny = true;

    if (rename(nazwaPlikuTymczasowego.c_str(), nazwaPlikuZAdresatami.c_str()) == 0)
        czyZamienionoNazwyPlikow = true;

    if (czyUsunietoPlikOryginalny == true && czyZamienionoNazwyPlikow == true)
        return true;
    else
        return false;
}

void PlikZAdresatami::dodajLinieDoPliku(fstream &plik, string liniaTekstu)
{
    if (MetodyPomocnicze::sprawdzCzyPlikJestPusty() == true)
        plik << liniaTekstu;
    else
        plik << liniaTekstu << endl;
}

void PlikZAdresatami::usunAdresata(vector <Adresat> adresaci, int nrIdAdresataDoUsuniecia, int idZalogowanegoUzytkownika)
{
    fstream plikOryginalny, plikTymczasowy;
    string nazwaPlikuTymczasowego = "kontakty_tymczasowe.txt";
    plikOryginalny.open(nazwaPlikuZAdresatami.c_str(), ios :: in);
    plikTymczasowy.open(nazwaPlikuTymczasowego.c_str(), ios :: out);

    string liniaPlikuOryginalnego;
    int rozmiarWektoraZAdresatami = adresaci.size();
    int idUzytkownikaZLiniiPlikuOryginalnego;
    int idAdresataZLiniiPlikuOryginalnego;

    if (plikOryginalny.good() == true && plikTymczasowy.good() == true)
    {
        while (getline(plikOryginalny, liniaPlikuOryginalnego))
        {
            //sprawdzany idUzytkownika z linii tekstu
            idUzytkownikaZLiniiPlikuOryginalnego = sprawdzIdZalogowanegoUzytkownika(liniaPlikuOryginalnego);
            idAdresataZLiniiPlikuOryginalnego = sprawdzIdAdresata(liniaPlikuOryginalnego);
            //jezeli idUzytkownika z linii tekstu jest rozne od idZalogowanegoUzytkownika to wpisujemy linie do pliku tymczasowego
            if (idUzytkownikaZLiniiPlikuOryginalnego != idZalogowanegoUzytkownika)
                dodajLinieDoPliku(plikTymczasowy, liniaPlikuOryginalnego);
            //jezeli idUzytkownika z linii tekstu jest takie jak idZalogowanegoUzytkownika to...
            else if (idUzytkownikaZLiniiPlikuOryginalnego == idZalogowanegoUzytkownika)
            {
                //... sprawdzamy czy idAdresata pobrane z linii tekstu nalezy do pobranego vectora
                for (int i = 0; i < rozmiarWektoraZAdresatami; i++)
                {
                    //jezeli nalezy to wpsujemy linie do pliku tymczasowego
                    if (idAdresataZLiniiPlikuOryginalnego == adresaci[i].pobierzId())
                        dodajLinieDoPliku(plikTymczasowy, liniaPlikuOryginalnego);
                }
            }
        }
        plikOryginalny.close();
        plikTymczasowy.close();

        if (zamienPlikiZKontaktami(nazwaPlikuTymczasowego))
            cout << "Kontakty zostaly zaktualizowane!" << endl;
        else
            cout << "Blad zapisu." << endl;
    }
    else
        cout << "Nie udalo sie otworzyc pliku i zapisac do niego danych." << endl;
    cout << endl;
    system("pause");
}

void PlikZAdresatami::edytujAdresata(vector <Adresat> adresaci, int nrIdAdresataDoEdycji, int idZalogowanegoUzytkownika)
{
    fstream plikOryginalny, plikTymczasowy;
    string nazwaPlikuTymczasowego = "kontakty_tymczasowe.txt";
    plikOryginalny.open(nazwaPlikuZAdresatami.c_str(), ios :: in);
    plikTymczasowy.open(nazwaPlikuTymczasowego.c_str(), ios :: out);

    string liniaPlikuOryginalnego;
    string liniaPlikuTymczasowego;
    int rozmiarWektoraZAdresatami = adresaci.size();
    int idUzytkownikaZLiniiPlikuOryginalnego;
    int idAdresataZLiniiPlikuOryginalnego;

    if (plikOryginalny.good() == true && plikTymczasowy.good() == true)
    {
        while (getline(plikOryginalny, liniaPlikuOryginalnego))
        {
            idUzytkownikaZLiniiPlikuOryginalnego = sprawdzIdZalogowanegoUzytkownika(liniaPlikuOryginalnego);
            idAdresataZLiniiPlikuOryginalnego = sprawdzIdAdresata(liniaPlikuOryginalnego);
            if (idUzytkownikaZLiniiPlikuOryginalnego != idZalogowanegoUzytkownika)
                dodajLinieDoPliku(plikTymczasowy, liniaPlikuOryginalnego);
            else if (idUzytkownikaZLiniiPlikuOryginalnego == idZalogowanegoUzytkownika)
            {
                if (idAdresataZLiniiPlikuOryginalnego == nrIdAdresataDoEdycji)
                {
                    for (int i = 0; i < rozmiarWektoraZAdresatami; i++)
                    {
                        if (nrIdAdresataDoEdycji == adresaci[i].pobierzId())
                        {
                            liniaPlikuTymczasowego = przypiszDaneAdresataDoLinii(adresaci[i]);
                            dodajLinieDoPliku(plikTymczasowy, liniaPlikuTymczasowego);
                        }
                    }
                }
                else
                    dodajLinieDoPliku(plikTymczasowy, liniaPlikuOryginalnego);
            }
        }
        plikOryginalny.close();
        plikTymczasowy.close();

        if (zamienPlikiZKontaktami(nazwaPlikuTymczasowego))
            cout << "Kontakty zostaly zaktualizowane!" << endl;
        else
            cout << "Blad zapisu." << endl;
    }
    else
        cout << "Nie udalo sie otworzyc pliku i zapisac do niego danych." << endl;
}
