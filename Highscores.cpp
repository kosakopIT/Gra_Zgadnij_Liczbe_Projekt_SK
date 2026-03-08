// HighScores.cpp
// Implementacja obsługi Top5 – sortowanie, ograniczanie do 5, zapis/odczyt z pliku.

#include "HighScores.h"
#include <algorithm>
#include <fstream>
#include <iostream>


using std::cout;
using std::endl;

HighScores::HighScores() {}

// Mapa Difficulty -> indeks 0..5
int HighScores::diffIndex(Difficulty diff) const {
    switch (diff) {
        case Difficulty::DZIECIECY: return 0;
        case Difficulty::LATWY:     return 1;
        case Difficulty::NORMALNY:  return 2;
        case Difficulty::TRUDNY:    return 3;
        case Difficulty::HARDCORE:  return 4;
        case Difficulty::BOSKI:     return 5;
        default: return 2;
    }
}

void HighScores::addScore(Difficulty diff, const std::string& name,
                          int attempts, bool betMode) {
    int d = diffIndex(diff);
    int m = betMode ? 1 : 0;

    ScoreEntry e{name, attempts, betMode};
    scores[d][m].push_back(e);

    // Sortujemy po liczbie prób rosnąco
    std::sort(scores[d][m].begin(), scores[d][m].end(),
              [](const ScoreEntry& a, const ScoreEntry& b) {
                  return a.attempts < b.attempts;
              });

    // Ograniczamy do 5 najlepszych
    if (scores[d][m].size() > 5) {
        scores[d][m].resize(5);
    }
}

void HighScores::printTable(Difficulty diff, bool betMode) const {
    int d = diffIndex(diff);
    int m = betMode ? 1 : 0;

    static const char* diffNames[6] = {
        "Dzieciecy", "Latwy", "Normalny",
        "Trudny", "Hardcore", "Boski"
    };

    cout << "=====================================\n";
    cout << "Top5 – " << diffNames[d]
         << (betMode ? " (Tryb zakladu)" : " (Normalny)") << "\n";
    cout << "=====================================\n";
    cout << "| Poz | Imie        | Proby |\n";
    cout << "-------------------------------------\n";

    const auto& v = scores[d][m];
    for (std::size_t i = 0; i < v.size(); ++i) {
        cout << "| " << (i + 1) << "   | "
             << v[i].name << "\t\t| "
             << v[i].attempts << "    |\n";
    }

    if (v.empty()) {
        cout << "Brak wynikow dla tej kombinacji.\n";
    }
}

void HighScores::saveToFile(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out) return;

    // Nagłówek pliku
    out << "=== ZGADNIJ LICZBĘ - TOP5 ===\n\n";

    static const char* diffNames[6] = {"Dzieciecy", "Latwy", "Normalny", "Trudny", "Hardcore", "Boski"};

    // Dla każdego poziomu trudności i trybu
    for (int d = 0; d < 6; ++d) {
        for (int m = 0; m < 2; ++m) {
            const auto& v = scores[d][m];
            if (v.empty()) continue;

            // Tytuł tabeli (jak printTable)
            out << "Top5 " << diffNames[d];
            if (m == 1) out << " (Tryb zakladu)";
            else out << " (Normalny)";
            out << "\n";
            out << "Poz | Imie     | Proby\n";
            out << "-------------------------------------\n";

            // Top5 wyników (posortowane)
            for (std::size_t i = 0; i < v.size(); ++i) {
                out << (i+1) << "  | "
                    << v[i].name.substr(0,8) << " | "  // Imię max 8 znaków
                    << v[i].attempts << "\n";
            }
            out << "\n";
        }
    }
    out.close();
}

void HighScores::loadFromFile(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) return;

    // Czyscimy aktualne wyniki
    for (int d = 0; d < 6; ++d) {
        for (int m = 0; m < 2; ++m) {
            scores[d][m].clear();
        }
    }

    int d, m, attempts;
    std::string name;
    while (in >> d >> m >> name >> attempts) {
        if (d < 0 || d >= 6 || m < 0 || m >= 2) continue;
        ScoreEntry e{name, attempts, m == 1};
        scores[d][m].push_back(e);
    }

    // Ograniczamy do 5 i sortujemy
    for (int d2 = 0; d2 < 6; ++d2) {
        for (int m2 = 0; m2 < 2; ++m2) {
            auto& v = scores[d2][m2];
            std::sort(v.begin(), v.end(),
                      [](const ScoreEntry& a, const ScoreEntry& b) {
                          return a.attempts < b.attempts;
                      });
            if (v.size() > 5) v.resize(5);
        }
    }
}

bool HighScores::hasAnyScore() const {
    for (int d = 0; d < 6; ++d) {
        for (int m = 0; m < 2; ++m) {
            if (!scores[d][m].empty()) return true;
        }
    }
    return false;
}