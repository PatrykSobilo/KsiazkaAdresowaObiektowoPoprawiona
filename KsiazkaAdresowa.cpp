#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenedzer.logowanieUzytkownika();
}

void KsiazkaAdresowa::wylogowanieUzytkownika()
{
    uzytkownikMenedzer.wylogowanieUzytkownika();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}



void KsiazkaAdresowa::dodajAdresata()
{
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany() > 0)
    {
        AdresatMenedzer adresatMenedzer("ADRESACI.txt", uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
        adresatMenedzer.dodajAdresata();
    }
    else cout << endl << "Funkcja dostepna tylko dla zalogowanego uzytkownika" << endl;
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
     if(uzytkownikMenedzer.czyUzytkownikJestZalogowany() > 0)
    {
        AdresatMenedzer adresatMenedzer("ADRESACI.txt", uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
        adresatMenedzer.wyswietlWszystkichAdresatow();
    }
    else cout << endl << "Funkcja dostepna tylko dla zalogowanego uzytkownika" << endl;
}
