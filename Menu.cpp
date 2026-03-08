// Menu.cpp
// Implementacja obsługi menu.

#include "Menu.h"
#include "AsciiArt.h"
#include "Messages.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

Menu::Menu(Game& g, HighScores& scores) : game(g), highScores(scores) {}

// Sprawdza, czy są zapisane jakiekolwiek wyniki
bool Menu::hasAnyScores() const {
    return highScores.hasAnyScore();
}

// Wyświetlanie i obsługa menu głównego
bool Menu::showMainMenu() {
    int choice;

    // ASCII‑interfejs menu głównego + powitanie
    AsciiArt::printMainMenuHeader();

    // **DYNAMMICZNE menu w zależności od wyników**
    if (hasAnyScores()) {
        Messages::showMainMenuOptions(true);  // Pełne menu z Top5
    } else {
        Messages::showMainMenuOptions(false); // Menu bez Top5
    }

    cin >> choice;

    switch (choice) {
        case 1:
            // Rozpocznij grę
            game.start();
            break;
        case 2:
            // Top5 – tylko jeśli są wyniki (już sprawdzone przed wyświetleniem)
            showTop5Menu();
            break;
        case 3:
            // Wyjście z programu
            cout << "Zegnaj!\n";
            return false;
        default:
            // Niepoprawny wybór menu
            AsciiArt::printQuestionMark();
            Messages::randomMainMenuError();
            break;
    }

    return true;
}

// Podmenu Top5
void Menu::showTop5Menu() {
    bool inTop = true;

    while (inTop) {
        AsciiArt::printStar();
        Messages::showTop5MenuOptions();

        int choice;
        cin >> choice;

        if (choice >= 1 && choice <= 6) {
            bool betMode = false;
            // Wybór, czy tabela z trybem zakładu, czy bez
            Messages::showTop5BetChoice();
            int betChoice;
            cin >> betChoice;
            if (betChoice == 1) betMode = false;
            else if (betChoice == 2) betMode = true;
            else {
                AsciiArt::printQuestionMark();
                Messages::randomTop5Error();
                continue;
            }

            Difficulty diff = static_cast<Difficulty>(choice);
            AsciiArt::printStar();
            highScores.printTable(diff, betMode);
        } else if (choice == 7) {
            // Powrót do menu głównego
            inTop = false;
        } else {
            AsciiArt::printQuestionMark();
            Messages::randomTop5Error();
        }
    }
}