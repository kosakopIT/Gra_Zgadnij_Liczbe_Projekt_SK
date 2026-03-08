// Game.h
#ifndef GAME_H
#define GAME_H

#include "HighScores.h"
#include "Difficulty.h"

// Poprawiona definicja enum class - WYNOŚ Z KLASY!


class Game {
public:
    Game(HighScores& scores);
    void start();

private:
    HighScores& highScores;

    int getMaxNumberForDifficulty(Difficulty diff);
    Difficulty difficultyFromChoice(int choice);
    void playSingleGame(Difficulty diff, bool betMode, int betTries);
    void playGuessingLoop(int secret, int maxNumber, Difficulty diff, bool betMode, int betTries);
};

#endif