#include "Messages.h"
#include <iostream>
#include <cstdlib>


using std::cout;
using std::endl;

namespace Messages {

    // Pomocnicza funkcja zwracająca losowy indeks 0..4
    int r5() {
        return std::rand() % 5;
    }

    // Menu główne – opcje
    void showMainMenuOptions(bool hasScores) {
        if (hasScores) {
            // Wyświetl pełne menu: 1.Gra, 2.Top5, 3.Wyjście
            cout << "1. Rozpocznij gre" << endl;
            cout << "2. Top5" << endl;
            cout << "3. Wyjscie" << endl;
        } else {
            // Wyświetl menu bez Top5: 1.Gra, 2.Wyjście
            cout << "1. Rozpocznij gre" << endl;
            cout << "3. Wyjscie" << endl;
        }

    }

    // Losowy komunikat błędu w menu głównym
    void randomMainMenuError() {
        switch (r5()) {
            case 0: cout << "To nie jest poprawna opcja menu!\n"; break;
            case 1: cout << "Sprobuj ponownie, wybierz 1-3.\n"; break;
            case 2: cout << "Nie rozpoznano polecenia.\n"; break;
            case 3: cout << "To menu ma tylko kilka opcji.\n"; break;
            case 4: cout << "Blad: niepoprawny wybor z menu.\n"; break;
        }
    }

    // Menu Top5 – wybór trudności
    void showTop5MenuOptions() {
        cout << "\nTOP5 Wybierz tabele trudnosci:\n";
        cout << "1) Dzieciecy\n";
        cout << "2) Latwy\n";
        cout << "3) Normalny\n";
        cout << "4) Trudny\n";
        cout << "5) Hardcore\n";
        cout << "6) Boski\n";
        cout << "7) Powrot do menu glownego\n";

    }

    // Losowy komunikat błędu w Top5
    void randomTop5Error() {
        switch (r5()) {
            case 0: cout << "Nie ma takiej opcji w menu Top5.\n"; break;
            case 1: cout << "Top5 przyjmuje tylko poprawne numery.\n"; break;
            case 2: cout << "Sprobuj innej opcji Top5.\n"; break;
            case 3: cout << "To nie jest poprawny numer tabeli.\n"; break;
            case 4: cout << "Blad w wyborze tabeli Top5.\n"; break;
        }
    }

    // Wybór tabeli Top5 z/bez zakładu
    void showTop5BetChoice() {
        cout << "1) Tabela zwykla\n";
        cout << "2) Tabela trybu zakladu\n";
    }

    // Menu wyboru trudności gry
    void showDifficultyMenu() {
        cout << "\nWybierz poziom trudnosci:\n";
        cout << "1) Dzieciecy (1-10)\n";
        cout << "2) Latwy (1-50)\n";
        cout << "3) Normalny (1-100)\n";
        cout << "4) Trudny (1-250)\n";
        cout << "5) Hardcore (1-500)\n";
        cout << "6) Boski (1-1000)\n";
    }

    // Menu wyboru trybu zakładu
    void showBetModeMenu() {
        cout << "\nCzy chcesz wlaczyc tryb zakladu?\n";
        cout << "1) Tak\n";
        cout << "2) Nie\n";
    }

    void askBetTries() {
        cout << "\n Podaj ilosc prob dla trybu zakladu: ";
    }

    // Komunikat wygranej
    void randomWinMessage() {
        switch (r5()) {
            case 0: cout << "Brawo! Trafiles liczbe!\n"; break;
            case 1: cout << "Znakomicie, zgadles!\n"; break;
            case 2: cout << "Sukces! Udalo Ci sie.\n"; break;
            case 3: cout << "Wygrana! Dobra robota.\n"; break;
            case 4: cout << "Perfekcyjnie! To byla szukana liczba.\n"; break;
        }
    }

    // Komunikaty poza zakresem trudności
    void randomOutOfRangeMessage() {
        switch (r5()) {
            case 0: cout << "Ta liczba jest poza zakresem tej trudnosci.\n"; break;
            case 1: cout << "Prosze o liczbe w dopuszczalnym zakresie.\n"; break;
            case 2: cout << "Ta gra ma swoj zakres, trzymaj sie go.\n"; break;
            case 3: cout << "Liczba za mala lub za duza dla tego poziomu.\n"; break;
            case 4: cout << "Przekroczyles zakres trudnosci.\n"; break;
        }
    }

    // Ogólny błąd zakresu
    void randomGameRangeError() {
        switch (r5()) {
            case 0: cout << "To nie jest poprawna liczba.\n"; break;
            case 1: cout << "Wprowadz prawidlowa liczbe.\n"; break;
            case 2: cout << "Nie rozumiem tej wartosci.\n"; break;
            case 3: cout << "Sprobuj jeszcze raz z poprawna liczba.\n"; break;
            case 4: cout << "Blad: nieprawidlowe dane.\n"; break;
        }
    }

    // Za mala – różne zakresy
    void randomTooLow_0_5() {
        switch (r5()) {
            case 0: cout << "Bardzo blisko, liczba jest odrobine wieksza.\n"; break;
            case 1: cout << "Minimalnie za malo.\n"; break;
            case 2: cout << "Jeszcze ciut wiecej.\n"; break;
            case 3: cout << "Prawie trafiles, troszke wieksza.\n"; break;
            case 4: cout << "Odrobine za mala liczba.\n"; break;
        }
    }

    void randomTooLow_5_10() {
        switch (r5()) {
            case 0: cout << "Troche za malo.\n"; break;
            case 1: cout << "Liczba jest kilka oczek wieksza.\n"; break;
            case 2: cout << "Za nisko, ale juz niedaleko.\n"; break;
            case 3: cout << "Jeszcze kilka oczek w gore.\n"; break;
            case 4: cout << "Sprobuj wiekszej liczby.\n"; break;
        }
    }

    void randomTooLow_10_50() {
        switch (r5()) {
            case 0: cout << "Znacznie za malo.\n"; break;
            case 1: cout << "Musisz znacznie zwiekszyc liczbe.\n"; break;
            case 2: cout << "Sekret jest znacznie wyzej.\n"; break;
            case 3: cout << "Dodaj sporo do swojej liczby.\n"; break;
            case 4: cout << "Duzy dystans, idz w gore.\n"; break;
        }
    }

    void randomTooLow_50_100() {
        switch (r5()) {
            case 0: cout << "Jestes bardzo nisko.\n"; break;
            case 1: cout << "Sekretna liczba jest daleko wyzej.\n"; break;
            case 2: cout << "Podnios liczbe o dziesiatki.\n"; break;
            case 3: cout << "Zupelnie za malo.\n"; break;
            case 4: cout << "Musisz bardzo zwiekszyc liczbe.\n"; break;
        }
    }

    void randomTooLow_100plus() {
        switch (r5()) {
            case 0: cout << "Strzelasz dramatycznie za nisko.\n"; break;
            case 1: cout << "Sekretna liczba jest ponad sto oczek wyzej.\n"; break;
            case 2: cout << "Zupelnie przestrzeliles w dol.\n"; break;
            case 3: cout << "To strzal daleko pod celem.\n"; break;
            case 4: cout << "Potrzeba ogromnej zmiany w gore.\n"; break;
        }
    }

    // Za duza – różne zakresy
    void randomTooHigh_0_5() {
        switch (r5()) {
            case 0: cout << "Bardzo blisko, ale za wysoko.\n"; break;
            case 1: cout << "Minimalnie za duzo.\n"; break;
            case 2: cout << "Troszeczke za duza liczba.\n"; break;
            case 3: cout << "Prawie, ale za wysoko.\n"; break;
            case 4: cout << "Odrobine za duza liczba.\n"; break;
        }
    }

    void randomTooHigh_5_10() {
        switch (r5()) {
            case 0: cout << "Troche za duzo.\n"; break;
            case 1: cout << "Liczba jest kilka oczek mniejsza.\n"; break;
            case 2: cout << "Za wysoko, ale juz niedaleko.\n"; break;
            case 3: cout << "Zejsci troche nizej.\n"; break;
            case 4: cout << "Sprobuj mniejszej liczby.\n"; break;
        }
    }

    void randomTooHigh_10_50() {
        switch (r5()) {
            case 0: cout << "Znacznie za duzo.\n"; break;
            case 1: cout << "Musisz znacznie zmniejszyc liczbe.\n"; break;
            case 2: cout << "Sekret jest znacznie nizej.\n"; break;
            case 3: cout << "Odejmij sporo od swojej liczby.\n"; break;
            case 4: cout << "Duzy dystans, idz w dol.\n"; break;
        }
    }

    void randomTooHigh_50_100() {
        switch (r5()) {
            case 0: cout << "Jestes bardzo wysoko.\n"; break;
            case 1: cout << "Sekretna liczba jest daleko nizej.\n"; break;
            case 2: cout << "Zmniejsz liczbe o dziesiatki.\n"; break;
            case 3: cout << "Zupelnie za duzo.\n"; break;
            case 4: cout << "Musisz bardzo zmniejszyc liczbe.\n"; break;
        }
    }

    void randomTooHigh_100plus() {
        switch (r5()) {
            case 0: cout << "Strzelasz dramatycznie za wysoko.\n"; break;
            case 1: cout << "Sekretna liczba jest ponad sto oczek nizej.\n"; break;
            case 2: cout << "Zupelnie przestrzeliles w gore.\n"; break;
            case 3: cout << "To strzal daleko nad celem.\n"; break;
            case 4: cout << "Potrzeba ogromnej zmiany w dol.\n"; break;
        }
    }
}