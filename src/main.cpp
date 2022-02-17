#include <iostream> // Allow IO
#include <filesystem> // Filesystem access
#include <fstream> // Filestream
#include <string> // string related functions
#include <limits> // Limits
#include <time.h>

// Time stuff
#include <chrono>
#include <ctime>
#include <thread>


#include <cinttypes>

// ? The windows includes, DO NOT MOVE UP
// #include <windows.h> // Windows API
// #include <direct.h> // Direct API

// #include "lib/getExecutableName.h" // Currently unused
#include "lib/terminalstyle.hpp"
#include "lib/vector.hpp"
#include "lib/char.hpp"
#include "lib/time.hpp"
#include "lib/sleep.hpp"


#include "lib/betterwindows.hpp"

void clearconsole() {
    consolereset;
}


// Main function
int main() {
    std::atexit(clearconsole);
    std::cout << 1.1 * 1.1 << "\n";
    return 0;
}
