// Menu.cpp
// Implementacja obsługi menu.
#include "ClearScreen.h"
#include "Menu.h"
#include "AsciiArt.h"
#include "Messages.h"
#include <iostream>
#include <limits>  // Dla numeric_limits

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
    ClearScreen::clear();
    int choice;

    // ASCII‑interfejs menu głównego + powitanie
    AsciiArt::printMainMenuHeader();

    // **DYNAMMICZNE menu w zależności od wyników**
    if (hasAnyScores()) {
        Messages::showMainMenuOptions(true);  // Pełne menu z Top5
    } else {
        Messages::showMainMenuOptions(false); // Menu bez Top5
    }

    // Bezpieczne czytanie int (1-3)
    while (!(cin >> choice) || choice < 1 || choice > 3) {
        if (!cin) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        AsciiArt::printQuestionMark();
        Messages::randomMainMenuError();
        if (hasAnyScores()) {
            Messages::showMainMenuOptions(true);
        } else {
            Messages::showMainMenuOptions(false);
        }
    }

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
            // Nieosiągalne dzięki walidacji
            break;
    }

    return true;
}

// Podmenu Top5
void Menu::showTop5Menu() {
    ClearScreen::clear();
    bool inTop = true;

    while (inTop) {
        AsciiArt::printStar();
        Messages::showTop5MenuOptions();

        int choice;
        // Bezpieczne czytanie int (1-7)
        while (!(cin >> choice) || choice < 1 || choice > 7) {
            if (!cin) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            AsciiArt::printQuestionMark();
            Messages::randomTop5Error();
            AsciiArt::printStar();
            Messages::showTop5MenuOptions();
        }

        if (choice >= 1 && choice <= 6) {
            // Wybór trybu zakładu (1-2)
            Messages::showTop5BetChoice();
            int betChoice;
            while (!(cin >> betChoice) || betChoice < 1 || betChoice > 2) {
                if (!cin) {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                AsciiArt::printQuestionMark();
                Messages::randomTop5Error();
                Messages::showTop5BetChoice();
            }

            bool betMode = (betChoice == 2);
            Difficulty diff = static_cast<Difficulty>(choice);
            AsciiArt::printStar();
            highScores.printTable(diff, betMode);
        } else if (choice == 7) {
            // Powrót do menu głównego
            inTop = false;
        }
    }
}