#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>

#include "Adresat.h"
#include "PlikZAdresatami.h"

using namespace std;

class AdresatMenedzer
{
    vector <Adresat> adresaci;
    Adresat podajDaneNowegoAdresata();
    int idZalogowanegoUzytkownika;
    PlikZAdresatami plikZAdresatami;
    void wyswietlDaneAdresata(Adresat adresat);

public:
    AdresatMenedzer(string NAZWA_PLIKU_Z_ADRESATAMI, int ID_ZALOGOWANEGO_UZYTKOWNIKA)
        : plikZAdresatami(NAZWA_PLIKU_Z_ADRESATAMI), idZalogowanegoUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA)
    {
        adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
    };
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();

};

#endif
