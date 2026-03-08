// main.cpp
// Główny plik programu, inicjuje grę i uruchamia pętlę menu.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Menu.h"
#include "Game.h"
#include "HighScores.h"

int main() {
    // Inicjowanie generatora liczb losowych
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    HighScores highScores;

    highScores.loadFromFile("top5.txt");

    Game game(highScores);

    Menu menu(game, highScores);

    bool running = true;
    while (running) {
        running = menu.showMainMenu();
    }

    highScores.saveToFile("top5.txt");

    return 0;
}