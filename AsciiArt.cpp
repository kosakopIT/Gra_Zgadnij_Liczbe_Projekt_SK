// AsciiArt.cpp
// Implementacja prostych grafik ASCII.

#include "AsciiArt.h"
#include <iostream>

using std::cout;
using std::endl;

namespace AsciiArt {

    void printMainMenuHeader() {
        cout << "============================\n";
        cout << "   Witaj w ZGADNIJ LICZBE   \n";
        cout << "============================\n";
    }

    void printTrophy() {
        cout << "      ___________   \n";
        cout << "     '._==_==_=_.'  \n";
        cout << "     .-\\:      /-. \n";
        cout << "    | (|:.     |) |\n";
        cout << "     '-|:.     |-'\n";
        cout << "       \\::.    /  \n";
        cout << "        '::. .'   \n";
        cout << "          ) (     \n";
        cout << "        _.' '._   \n";
        cout << "       '-------'  \n";
    }

    void printSkull() {
        cout << "      .-\"\"\"-.\n";
        cout << "     / -   - \\\n";
        cout << "    |  .-. .-|\n";
        cout << "    |  \\o| |o|\n";
        cout << "    \\     ^ /\n";
        cout << "     '.  -.'\n";
        cout << "       '---'\n";
    }

    void printStar() {
        cout << "      *\n";
        cout << "     ***\n";
        cout << "    *****\n";
        cout << "   *******\n";
        cout << "    *****\n";
        cout << "     ***\n";
        cout << "      *\n";
    }

    void printQuestionMark() {
        cout << "   ____  \n";
        cout << "  / __ \\ \n";
        cout << " | |  | |\n";
        cout << " | |  | |\n";
        cout << " | |__| |\n";
        cout << "  \\____/ \n";
        cout << "    ??   \n";
    }
}