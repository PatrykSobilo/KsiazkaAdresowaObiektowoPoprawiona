#include "KsiazkaAdresowa.h"

//_________________MENU____________________

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


//_____________________UZYTKOWNIK_____________________________


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

bool KsiazkaAdresowa::czyUzytkownikJestZalogowany()
{
    if(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika() > 0)
        return true;
    else return false;
}

void KsiazkaAdresowa::wylogowanieUzytkownika()
{
    uzytkownikMenedzer.wylogowanieUzytkownika();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}


//________________________ADRESAT_____________________________


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

void KsiazkaAdresowa::wyszukajAdresatowPoImieniu()
{
     if(uzytkownikMenedzer.czyUzytkownikJestZalogowany() > 0)
    {
        adresatMenedzer -> wyszukajAdresatowPoImieniu();
    }
    else cout << endl << "Funkcja dostepna tylko dla zalogowanego uzytkownika" << endl;
}


