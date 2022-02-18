#include <iostream> // Allow IO
#include <filesystem> // Filesystem access
#include <fstream> // Filestream
#include <string> // string related functions
#include <limits> // Limits
#include <time.h>
#include <random>

// Time stuff
#include <chrono>
#include <ctime>
#include <thread>


#include <cinttypes>

// #include "lib/getExecutableName.h" // Currently unused
#include "lib/terminalstyle.hpp"
#include "lib/vector.hpp"
#include "lib/time.hpp"
#include "lib/sleep.hpp"


#include "lib/ext/betterwindows.hpp"


void clearconsole() {
    consolereset;
}


// Main function
int main() {
    std::atexit(clearconsole);

    long i = 1;    
    std::random_device dev; // for seeding
    std::default_random_engine gen{dev()};
    std::uniform_int_distribution<int> dis{1, 1000};
    vec4i a = vec4i(0, 100, 200, 300);
    vec4i b = vec4i(0, 100, 200, 300);
    vec4i c = vec4i(400, 100, 200, 300);
    while(i <= 100000000l) {
        i++;
        b = {dis(gen), dis(gen), dis(gen), dis(gen)};
        c = a + b;
    }
    std::cout << i << ansi::newline;
    return 0;
}
