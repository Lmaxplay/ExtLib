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


void clearconsole() {
    consolereset;
}


// Main function
int main() {
    std::atexit(clearconsole);
    long i = 0;
    vec4i a = vec4i(0, 100, 200, 300);
    vec4i b = vec4i(0, 100, 200, 300);
    while(i <= 1000000000l) {
        i = 0;
    }
    return 0;
}
