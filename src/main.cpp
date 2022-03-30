#include <iostream> // Allow IO
#include <thread>
// #include <sstream>
// #include <filesystem> // Filesystem access
// #include <fstream> // Filestream
#include <string> // string related functions
// #include <limits> // Limits
// #include <time.h>
// #include <random>

// Time stuff

// #include <cinttypes>

// #include "lib/getExecutableName.h" // Currently unused
#include "lib/ansi.hpp"
#include "lib/vector.hpp"
#include "lib/thread.hpp"
// #include "lib/time.hpp"
#include "lib/sleep.hpp"


// Main function
int main() {

    std::atexit(ansi::resetconsole);

    std::cout << "hi\n";

    return 0;
}
