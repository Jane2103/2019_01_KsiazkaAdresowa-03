#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <windows.h>



using namespace std;

class MetodyPomocnicze
{
public:
    static string konwertujIntNaStr(int liczba);
    static bool sprawdzCzyPlikJestPusty();
    static void zakonczProgram();
};

#endif
