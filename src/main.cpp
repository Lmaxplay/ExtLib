#include <iostream> // Allow IO
#include <filesystem> // Filesystem access
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
    consolereset;
}

// Main function
int main() {
    std::atexit(clearconsole);

    std::vector<std::string> strings(1024, std::string("A"));
    bool instrings = std::find(strings.begin(), strings.end(), "A") != strings.end();

    std::cout << instrings << ansi::newline << ansi::;

    return 0;
}
