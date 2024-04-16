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

void KsiazkaAdresowa::menuGlowne()
{
    char wybor;

    if (uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika() == 0)
    {
        wybor = wybierzOpcjeZMenuGlownego();

        switch (wybor)
        {
        case '1':
            KsiazkaAdresowa::rejestracjaUzytkownika();
            break;
        case '2':
            KsiazkaAdresowa::logowanieUzytkownika();
            break;
        case '9':
            exit(0);
            break;
        default:
            cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
            system("pause");
            break;
        }
    }
}


void KsiazkaAdresowa::menuUzytkownika()
{
    if (adresaci.empty() == true)
        // Pobieramy idOstatniegoAdresata, po to aby zoptymalizowac program.
        // Dzieki temu, kiedy uztykwonik bedzie dodawal nowego adresata
        // to nie bedziemy musieli jeszcze raz ustalac idOstatniegoAdresata
        idOstatniegoAdresata = wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresaci, idZalogowanegoUzytkownika);

    wybor = wybierzOpcjeZMenuUzytkownika();

    switch (wybor)
    {
    case '1':
        idOstatniegoAdresata = dodajAdresata(adresaci, idZalogowanegoUzytkownika, idOstatniegoAdresata);
        break;
    case '2':
        wyszukajAdresatowPoImieniu(adresaci);
        break;
    case '3':
        wyszukajAdresatowPoNazwisku(adresaci);
        break;
    case '4':
        wyswietlWszystkichAdresatow(adresaci);
        break;
    case '5':
        idUsunietegoAdresata = usunAdresata(adresaci);
        idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
        break;
    case '6':
        edytujAdresata(adresaci);
        break;
    case '7':
        zmianaHaslaZalogowanegoUzytkownika(uzytkownicy, idZalogowanegoUzytkownika);
        break;
    case '8':
        idZalogowanegoUzytkownika = 0;
        adresaci.clear();
        break;
    }
}

char wybierzOpcjeZMenuGlownego()
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
    wybor = wczytajZnak();

    return wybor;
}

char wybierzOpcjeZMenuUzytkownika()
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
    wybor = wczytajZnak();

    return wybor;
}

