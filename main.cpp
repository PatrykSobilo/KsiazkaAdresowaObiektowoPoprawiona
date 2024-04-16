#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");




    return 0;
}




/*
#include "AdresatMenedzer.h"

int main()
{
    AdresatMenedzer adresatMenedzer("Adresaci.txt", 2);
    adresatMenedzer.wyswietlWszystkichAdresatow();

    return 0;
}

#include "AdresatMenedzer.h"
#include "PlikZAdresatami.h"

int main()
{
    PlikZAdresatami plikZAdresatami("Adresaci-test.txt");
    Adresat adresat(1, 9, "Janek", "Twardowski", "111 222 333", "janek@o2.pl", "ul. Jana 1");
    plikZAdresatami.dopiszAdresataDoPliku(adresat);

    cout << plikZAdresatami.pobierzIdOstatniegoAdresata();

    return 0;
}
*/
