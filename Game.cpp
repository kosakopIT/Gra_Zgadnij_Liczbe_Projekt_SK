#include "Game.h"
#include "Messages.h"
#include "AsciiArt.h"
#include "ClearScreen.h"
#include <iostream>
#include <limits>

using std::cin;
using std::cout;
using std::endl;

Game::Game(HighScores& scores) : highScores(scores) {}

// Zwraca maksymalną liczbę dla danego poziomu trudności
int Game::getMaxNumberForDifficulty(Difficulty diff) {
    switch (diff) {
        case Difficulty::DZIECIECY: return 10;
        case Difficulty::LATWY:     return 50;
        case Difficulty::NORMALNY:  return 100;
        case Difficulty::TRUDNY:    return 250;
        case Difficulty::HARDCORE:  return 500;
        case Difficulty::BOSKI:     return 1000;
        default: return 100;
    }
}

// Konwersja wyboru z menu na enum Difficulty
Difficulty Game::difficultyFromChoice(int choice) {
    switch (choice) {
        case 1: return Difficulty::DZIECIECY;
        case 2: return Difficulty::LATWY;
        case 3: return Difficulty::NORMALNY;
        case 4: return Difficulty::TRUDNY;
        case 5: return Difficulty::HARDCORE;
        case 6: return Difficulty::BOSKI;
        default: return Difficulty::NORMALNY;
    }
}

// Główny punkt wejścia do gry

void Game::start() {
    int diffChoice;
    
    // Wyświetlenie menu wyboru trudności
    Messages::showDifficultyMenu();
    
    // Bezpieczne czytanie 1-6
    while (!(cin >> diffChoice) || diffChoice < 1 || diffChoice > 6) {
        if (!cin) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        AsciiArt::printQuestionMark();
        Messages::randomMainMenuError();
        Messages::showDifficultyMenu();
    }

    Difficulty diff = difficultyFromChoice(diffChoice);

    // **JEDNO zapytanie o tryb zakładu**
    Messages::showBetModeMenu();
    int betChoice;
    // Bezpieczne czytanie 1-2
    while (!(cin >> betChoice) || betChoice < 1 || betChoice > 2) {
        if (!cin) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        AsciiArt::printQuestionMark();
        Messages::randomGameRangeError();
        Messages::showBetModeMenu();
    }

    bool betMode = (betChoice == 1);
    int betTries = 0;
    if (betMode) {
        // Pobieramy liczbę prób w trybie zakładu (1+)
        Messages::askBetTries();
        while (!(cin >> betTries) || betTries <= 0) {
            if (!cin) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            AsciiArt::printQuestionMark();
            Messages::randomGameRangeError();
            Messages::askBetTries();
        }
    }

    // Uruchamiamy jedną rozgrywkę
    playSingleGame(diff, betMode, betTries);
}

// Właściwa rozgrywka
void Game::playSingleGame(Difficulty diff, bool betMode, int betTries) {
    int maxNumber = getMaxNumberForDifficulty(diff);
    int secret = 1 + std::rand() % maxNumber;
    playGuessingLoop(secret, maxNumber, diff, betMode, betTries);
}

// Pętla zgadywania liczb
void Game::playGuessingLoop(int secret, int maxNumber,
                            Difficulty diff, bool betMode, int betTries) {
    int attempts = 0;
    int guess;

    while (true) {
        attempts++;
        cout << "\nProba nr: " << attempts << endl;
        cout << "Podaj liczbe: ";
        
        // Bezpieczne czytanie 1-maxNumber
        while (!(cin >> guess) || guess < 1 || guess > maxNumber) {
            if (!cin) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            AsciiArt::printQuestionMark();
            Messages::randomGameRangeError();
            cout << "\nProba nr: " << attempts << endl;
            cout << "Podaj liczbe (1-" << maxNumber << "): ";
        }

        // Trafienie
        if (guess == secret) {
            AsciiArt::printTrophy();
            Messages::randomWinMessage();

            // Pobranie imienia (string - odporne na spacje via getline)
            cout << "\nPodaj swoje imie: ";
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Czyści buffer
            std::string name;
            std::getline(std::cin, name);

            highScores.addScore(diff, name, attempts, betMode);
            highScores.saveToFile("top5.txt");  // Zapis natychmiast
            return;
        }

        // Podpowiedzi (za duża / za mała)
        int diffVal = guess - secret;
        AsciiArt::printSkull();
        if (diffVal > 0) {
            // Za duża
            if (diffVal <= 5) Messages::randomTooHigh_0_5();
            else if (diffVal <= 10) Messages::randomTooHigh_5_10();
            else if (diffVal <= 50) Messages::randomTooHigh_10_50();
            else if (diffVal <= 100) Messages::randomTooHigh_50_100();
            else Messages::randomTooHigh_100plus();
        } else {
            // Za mała
            diffVal = -diffVal;
            if (diffVal <= 5) Messages::randomTooLow_0_5();
            else if (diffVal <= 10) Messages::randomTooLow_5_10();
            else if (diffVal <= 50) Messages::randomTooLow_10_50();
            else if (diffVal <= 100) Messages::randomTooLow_50_100();
            else Messages::randomTooLow_100plus();
        }

        // Limit prób w trybie zakładu
        if (betMode && attempts >= betTries) {
            cout << "\nPrzekroczyles limit prob. Przegrales.\n";
            return;
        }
    }
}