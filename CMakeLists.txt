# CMakeLists.txt
# CMake do projektu "Zgadnij Liczbę" w C++
# Minimalna wersja CMake wymagana: 3.10 (standardowa w większości dystrybucji Linux)

cmake_minimum_required(VERSION 3.10)
project(Gra_Zgadnij_Liczbę_-_Projekt_na_Podstawy_Programowania VERSION 1.0 LANGUAGES CXX)

# Ustawienia kompilatora C++ (C++11 wystarczy)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Lista wszystkich plików źródłowych
set(SOURCES
        main.cpp
        Game.cpp
        Menu.cpp
        Messages.cpp
        AsciiArt.cpp
        HighScores.cpp
)

# Lista plików nagłówkowych (opcjonalnie, dla IDE)
set(HEADERS
        Menu.h
        Messages.h
        AsciiArt.h
        Game.h
	Difficulty.h	
        Highscores.h
)

# Tworzenie wykonywalnego pliku
add_executable(zgadnij ${SOURCES} ${HEADERS})

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++ -static")
