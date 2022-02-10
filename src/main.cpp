#include <iostream> // Allow IO
#include <filesystem> // Filesystem access
#include <windows.h> // Windows API
#include <direct.h> // Direct API
#include <fstream> // Filestream
#include <string> // string related functions
#include <limits> // Limits

// #include "lib/getExecutableName.h" // Currently unused
#include "lib/terminalstyle.hpp"
#include "lib/vector.hpp"
#include "lib/char.hpp"

using namespace std;

void clearconsole() {
    consolereset;
}

unsigned long long getTotalSystemMemory()
{
    MEMORYSTATUSEX status;
    status.dwLength = sizeof(status);
    GlobalMemoryStatusEx(&status);
    return status.ullTotalPhys;
}

// Main function
int main() {
    std::atexit(clearconsole);

    return 0;
}
