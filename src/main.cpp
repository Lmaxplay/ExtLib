#include <iostream> // Allow IO
// #include <filesystem> // Filesystem access
// #include <fstream> // Filestream
// #include <string> // string related functions
// #include <limits> // Limits
// #include <time.h>
// #include <random>

// Time stuff

// #include <cinttypes>

// #include "lib/getExecutableName.h" // Currently unused
#include "lib/ansi.hpp"
#include "lib/vector.hpp"
// #include "lib/time.hpp"
// #include "lib/sleep.hpp"


// #include "lib/ext/betterwindows.hpp"

void clearconsole() {
    ansi::resetconsole();
}

// Main function
int main() {
    std::atexit(clearconsole);
    

    std::cout << ansi::fg_red << "Text." << ansi::newline;

    return 0;
}
