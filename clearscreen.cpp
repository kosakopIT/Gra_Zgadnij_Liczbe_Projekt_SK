#include "ClearScreen.h"
#include <iostream>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <cstdlib>
#endif

namespace ClearScreen {
    void clear() {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }
}