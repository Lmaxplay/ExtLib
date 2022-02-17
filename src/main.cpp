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
    std::cout << "Hello World\n";
    sleeps::miliseconds(1000);
    std::cout << ansi::upline << "Hello worl \n";
    sleeps::miliseconds(1000);
    std::cout << ansi::upline << "Hello wor  \n";
    sleeps::miliseconds(1000);
    std::cout << ansi::upline << "Hello wo   \n";
    sleeps::miliseconds(1000);
    std::cout << ansi::upline << "Hello w    \n";
    sleeps::miliseconds(1000);
    std::cout << ansi::upline << "Hello      \n";
    sleeps::miliseconds(1000);
    std::cout << ansi::upline << "Hell       \n";
    sleeps::miliseconds(1000);
    std::cout << ansi::upline << "Hel        \n";
    sleeps::miliseconds(1000);
    std::cout << ansi::upline << "He         \n";
    sleeps::miliseconds(1000);
    std::cout << ansi::upline << "H          \n";
    sleeps::miliseconds(1000);
    std::cout << ansi::upline << "           \n";
    return 0;
}
