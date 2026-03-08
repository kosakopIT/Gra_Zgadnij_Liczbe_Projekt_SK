Zgadnij Liczbę - Instrukcja Gry
Gra konsolowa "Zgadnij Liczbę" - zgadnij wylosowaną liczbę z precyzyjnymi podpowiedziami!

Jak uruchomić grę
Linux/Mac:

bash
mkdir build && cd build
cmake ..
make
./main
Windows:

bash
mkdir build && cd build
cmake .. -G "MinGW Makefiles" 
mingw32-make
./main.exe
Zasady gry
Menu główne (1, 2, 3):

1 = Rozpocznij grę

2 = Top5 (najlepsze wyniki)

3 = Wyjście

Wybór trudności:

text
1. Dziecięcy (1-10)
2. Łatwy (1-50)  
3. Normalny (1-100)
4. Trudny (1-250)
5. Hardcore (1-500)
6. Boski (1-1000)
Tryb zakładu?:

1 = Normalny (nieograniczone próby)

2 = Zakład (ustaw limit prób)

Zgaduj liczbę:

text
Nr próby 1: Podaj liczbę (1-100): 50
Trochę za dużo

Nr próby 2: Podaj liczbę (1-100): 42  
Bardzo blisko, ale za wysoko!

Nr próby 3: Podaj liczbę (1-100): 37
Brawo! Trafiłeś liczbę!
Podaj swoje imię: Szymon
Podpowiedzi
Różnica	Podpowiedź
±1-5	"Bardzo blisko"
±6-10	"Trochę za (dużo/mało)"
±11-50	"Znacznie za (dużo/mało)"
±51-100	"Bardzo wysoko/nisko"
>100	"Dramatycznie za (dużo/mało)"
Top5
Automatycznie zapisuje 5 najlepszych wyników

Osobna tabela dla każdego poziomu + trybu (12 tabel)

Plik top5.txt w folderze gry

Sortowanie po najmniejszej liczbie prób

Przykład Top5:

text
TOP5 Normalny Normalny
Poz  Imie     Próby
-------------------------------------
1    Szymon   3
2    Ania     5  
3    Kuba     7
Sterowanie
Wpisz liczbę w zakresie trudności

Enter po każdej próbie

Imię po wygranej (max 8 znaków)

1-6 = poziomy trudności

1-2 = tryb zakładu/normalny

Cele
Pobić swój rekord (mniej prób = lepsze miejsce)

Zagraj na Boskim (1-1000) w <20 prób

Wygraj w trybie zakładu nie przekraczając limitu

Pliki wyników
top5.txt tworzony automatycznie w folderze gry. Nie usuwać!

Gotowy? Uruchom i wygraj Top1! 🎮
