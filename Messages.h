#ifndef MESSAGES_H
#define MESSAGES_H

namespace Messages {
    // Menu główne
    void showMainMenuOptions(bool hasScores);
    void randomMainMenuError();

    // Menu Top5
    void showTop5MenuOptions();
    void randomTop5Error();
    void showTop5BetChoice();

    // Trudności i tryb zakładu
    void showDifficultyMenu();
    void showBetModeMenu();
    void askBetTries();

    // Komunikaty gry
    void randomWinMessage();
    void randomOutOfRangeMessage();
    void randomGameRangeError();

    // Za mała
    void randomTooLow_0_5();
    void randomTooLow_5_10();
    void randomTooLow_10_50();
    void randomTooLow_50_100();
    void randomTooLow_100plus();

    // Za duża
    void randomTooHigh_0_5();
    void randomTooHigh_5_10();
    void randomTooHigh_10_50();
    void randomTooHigh_50_100();
    void randomTooHigh_100plus();
}

#endif