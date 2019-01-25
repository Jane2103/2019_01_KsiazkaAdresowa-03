#include "MetodyPomocnicze.h"

string MetodyPomocnicze::konwertujIntNaStr(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

bool MetodyPomocnicze::sprawdzCzyPlikJestPusty()
{
    fstream plik;
    plik.seekg(0, ios :: end);
    if (plik.tellg() == 0)
        return true;
    else
        return false;
}

void MetodyPomocnicze::zakonczProgram()
{
    cout << endl;
    cout << "Do widzenia..." << endl;
    exit(0);
}

