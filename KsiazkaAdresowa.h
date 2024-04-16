#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;

    //AdresatMenedzer *adresatMenedzer - gdybym potrzebowal przejsc na adresatMenedzera w klasie, od razu jako wskaznik

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami) {};
    //~KsiazkaAdresowa() - gdybym potrzebowal destruktora

    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    void wylogowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();

    void dodajAdresata();
    void wyswietlWszystkichAdresatow();

    void menuGlowne();
    void menuUzytkownika();
    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();
};

#endif
