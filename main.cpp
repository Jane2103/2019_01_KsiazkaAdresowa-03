#include <iostream>
#include <windows.h>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("uzytkownicy.txt", "kontakty.txt");
    ksiazkaAdresowa.wyswietlMenuPoStarcieProgramu();

    return 0;
}
