#include "Game.h"
#include "Messages.h"
#include "AsciiArt.h"
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
    cin >> diffChoice;

    if (diffChoice < 1 || diffChoice > 6) {
        // Błędny wybór – komunikat + znak zapytania
        AsciiArt::printQuestionMark();
        Messages::randomMainMenuError();
        return;
    }

    Difficulty diff = difficultyFromChoice(diffChoice);

    // **JEDNO zapytanie o tryb zakładu**
    Messages::showBetModeMenu();
    int betChoice;
    cin >> betChoice;

    bool betMode = false;
    int betTries = 0;
    if (betChoice == 1) {
        betMode = true;
        // Pobieramy od gracza liczbę prób w trybie zakładu
        Messages::askBetTries();
        cin >> betTries;
        if (betTries <= 0) {
            AsciiArt::printQuestionMark();
            Messages::randomGameRangeError();
            return;
        }
    }

    // Uruchamiamy jedną rozgrywkę z już ustalonym trybem zakładu
    playSingleGame(diff, betMode, betTries);
}

// Właściwa rozgrywka (zmieniona sygnatura)
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
        // Wyświetlamy numer aktualnej próby
        cout << "\nProba nr: " << attempts << endl;
        cout << "Podaj liczbe: ";
        cin >> guess;

        // Obsługa błędnego wejścia (np. litera zamiast liczby)
        if (!cin) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            AsciiArt::printQuestionMark();
            Messages::randomGameRangeError();
            continue;
        }

        // Sprawdzenie zakresu
        if (guess < 1 || guess > maxNumber) {
            AsciiArt::printQuestionMark();
            Messages::randomOutOfRangeMessage();
            continue;
        }

        // Trafienie
        if (guess == secret) {
            AsciiArt::printTrophy();
            Messages::randomWinMessage();

            // Pobranie imienia gracza po wygranej
            cout << "\nPodaj swoje imie: ";
            std::string name;
            cin >> name;

            // Zapis wyniku do struktury Top5
            highScores.addScore(diff, name, attempts, betMode);

            return;
        }

        // Obliczamy różnicę, aby dobrać odpowiedni komunikat
        int diffVal = guess - secret;

        // Za duża / za mała i wybór zakresu różnicy
        AsciiArt::printSkull();
        if (diffVal > 0) {
            // Za duża
            if (diffVal <= 5) {
                Messages::randomTooHigh_0_5();
            } else if (diffVal <= 10) {
                Messages::randomTooHigh_5_10();
            } else if (diffVal <= 50) {
                Messages::randomTooHigh_10_50();
            } else if (diffVal <= 100) {
                Messages::randomTooHigh_50_100();
            } else {
                Messages::randomTooHigh_100plus();
            }
        } else {
            // Za mała
            diffVal = -diffVal;
            if (diffVal <= 5) {
                Messages::randomTooLow_0_5();
            } else if (diffVal <= 10) {
                Messages::randomTooLow_5_10();
            } else if (diffVal <= 50) {
                Messages::randomTooLow_10_50();
            } else if (diffVal <= 100) {
                Messages::randomTooLow_50_100();
            } else {
                Messages::randomTooLow_100plus();
            }
        }

        // Jeśli jest tryb zakładu – sprawdź, czy gracz przekroczył limit prób
        if (betMode && attempts >= betTries) {
            cout << "\nPrzekroczyles ustalona liczbe prob. Przegrales.\n";
            return;
        }
    }
}