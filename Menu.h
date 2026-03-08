// Menu.h
// Deklaracja klasy Menu odpowiedzialnej za wyświetlanie i obsługę menu głównego oraz Top5.

#ifndef MENU_H
#define MENU_H

#include "Game.h"
#include "HighScores.h"

class Menu {
public:
    Menu(Game& game, HighScores& scores);

    // Wyświetla menu główne, zwraca false jeśli użytkownik wybrał wyjście
    bool showMainMenu();

private:
    Game& game;
    HighScores& highScores;

    // Wyświetlanie i obsługa podmenu Top5
    void showTop5Menu();

    // Sprawdzenie, czy istnieją jakiekolwiek wyniki
    bool hasAnyScores() const;
};

#endif