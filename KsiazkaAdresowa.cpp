#include "KsiazkaAdresowa.h"

bool KsiazkaAdresowa::czyUzytkownikJestZalogowany()
{
    if(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika() > 0)
        return true;
    else return false;
}

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego()
{
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika()
{
    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

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
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany() > 0)
    {
        adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogowanieUzytkownika()
{
    uzytkownikMenedzer.wylogowanieUzytkownika();
    delete adresatMenedzer;
    adresatMenedzer = NULL;
}

//-----------------------------ADRESACI--------------------------------------//

void KsiazkaAdresowa::dodajAdresata()
{
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany() > 0)
    {
        adresatMenedzer -> dodajAdresata();
    }
    else cout << endl << "Funkcja dostepna tylko dla zalogowanego uzytkownika" << endl;
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany() > 0)
    {
        adresatMenedzer -> wyswietlWszystkichAdresatow();
    }
    else cout << endl << "Funkcja dostepna tylko dla zalogowanego uzytkownika" << endl;
}

void KsiazkaAdresowa::wyszukajAdresatowPoImieniu()
{
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany() > 0)
    {
        adresatMenedzer -> wyszukajAdresatowPoImieniu();
    }
    else cout << endl << "Funkcja dostepna tylko dla zalogowanego uzytkownika" << endl;
}

void KsiazkaAdresowa::wyszukajAdresatowPoNazwisku()
{
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany() > 0)
    {
        adresatMenedzer -> wyszukajAdresatowPoNazwisku();
    }
    else cout << endl << "Funkcja dostepna tylko dla zalogowanego uzytkownika" << endl;
}

int KsiazkaAdresowa::usunAdresata()
{
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany() > 0)
    {
        adresatMenedzer -> usunAdresata();
    }
    else cout << endl << "Funkcja dostepna tylko dla zalogowanego uzytkownika" << endl;
}

void KsiazkaAdresowa::edytujAdresata()
{
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany() > 0)
    {
        adresatMenedzer -> edytujAdresata();
    }
    else cout << endl << "Funkcja dostepna tylko dla zalogowanego uzytkownika" << endl;
}
