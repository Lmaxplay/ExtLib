#include <iostream> // Allow IO
#include <filesystem> // Filesystem access
#include <windows.h> // Windows API
#include <direct.h> // Direct API
#include <fstream> // Filestream
#include <string> // string related functions
#include <limits> // Limits

// Time stuff
#include <chrono>
#include <ctime>
#include <thread>

// #include "lib/getExecutableName.h" // Currently unused
#include "lib/terminalstyle.hpp"
#include "lib/vector.hpp"
#include "lib/char.hpp"

using namespace std;

void clearconsole() {
    consolereset;
}

MEMORYSTATUSEX getTotalSystemMemory()
{
    MEMORYSTATUSEX status;
    status.dwLength = sizeof(status);
    GlobalMemoryStatusEx(&status);
    return status;
}

// Main function
int main() {
    std::atexit(clearconsole);
    while(true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        std::time_t result = std::time(nullptr);
        auto millisec_since_epoch = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        std::cout << ansi::clearline << "Current unix timestamp: " << millisec_since_epoch;
    }
    return 0;
}
