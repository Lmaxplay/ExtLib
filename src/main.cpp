#include <iostream> // Allow IO
#include <filesystem> // Filesystem access
#include <windows.h> // Windows API
#include <direct.h> // Direct API
#include <fstream> // Filestream
#include <string> // string related functions
#include <limits> // Limits
#include <time.h>

// Time stuff
#include <chrono>
#include <ctime>
#include <thread>

// #include "lib/getExecutableName.h" // Currently unused
#include "lib/terminalstyle.hpp"
#include "lib/vector.hpp"
#include "lib/char.hpp"
#include "lib/time.hpp"
#include "lib/sleep.hpp"

using namespace std;

void clearconsole() {
    consolereset;
}

// Main function
int main() {
    std::atexit(clearconsole);
    while(true) {
        sleep::miliseconds(1);
        std::cout << ansi::clearline << "Current unix timestamp: " << getTimeUnix();
    }
    return 0;
}
