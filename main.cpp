// main.cpp
// Główny plik programu

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>  // SetConsoleOutputCP (Windows)
#include <fstream>    // ifstream/ofstream
#include <string>
#include "ClearScreen.h"
#include "Menu.h"
#include "Game.h"
#include "HighScores.h"

using namespace std;

int main() {
    // Inicjalizacja generatora liczb losowych
    SetConsoleOutputCP(CP_UTF8);
    srand(static_cast<unsigned int>(time(nullptr)));

    HighScores highScores;

    // **SAM TWORZY top5.txt jeśli brak**
    ifstream checkFile("top5.txt");
    if (!checkFile.good()) {
        highScores.saveToFile("top5.txt");  // Tworzy pusty
        cout << "Utworzono top5.txt\n";
    }
    checkFile.close();

    // Ładuje wyniki (lub puste)
    highScores.loadFromFile("top5.txt");

    Game game(highScores);
    Menu menu(game, highScores);

    bool running = true;
    while (running) {
        running = menu.showMainMenu();
        // Zapis po wyjściu z menu (bezpieczny)
        highScores.saveToFile("top5.txt");
    }

    return 0;
}
