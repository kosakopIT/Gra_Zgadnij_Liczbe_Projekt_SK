#ifndef HIGHSCORES_H
#define HIGHSCORES_H

#include <string>
#include <vector>

#include "Difficulty.h"


struct ScoreEntry {
    std::string name;
    int attempts;
    bool betMode;
};

class HighScores {
public:
    HighScores();

    // Dodanie wyniku dla danej trudności i trybu (bet/no bet)
    void addScore( Difficulty diff, const std::string& name, int attempts, bool betMode);

    // Wydrukowanie tabeli Top5
    void printTable(Difficulty diff, bool betMode) const;

    // Zapis/wczytanie do/z pliku
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

    // Sprawdza, czy istnieje przynajmniej jeden wynik
    bool hasAnyScore() const;

private:
    // [6][2] – 6 poziomów trudności, 2 tryby (0 – normal, 1 – bet)
    std::vector<ScoreEntry> scores[6][2];

    int diffIndex(Difficulty diff) const;
};

#endif