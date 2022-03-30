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

// Pi constant
const double pi = 3.14159265358979323846;

// Main function
int main() {

    std::atexit(ansi::resetconsole);

    // Cout a bold red string
    std::cout << ansi::bold << ansi::red << "Hello World!" << ansi::reset << std::endl;
    // Cout a bold green string
    std::cout << ansi::bold << ansi::green << "Hello World!" << ansi::reset << std::endl;

    std::cout << "hi\n";

    return 0;
}
