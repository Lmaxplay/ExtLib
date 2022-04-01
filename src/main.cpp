#include <iostream> // Allow IO
#include <string> // string related functions

// Time stuff

// #include <cinttypes>

#include "lib/getExecutableName.h" // Currently unused
#include "lib/ansi.hpp"
#include "lib/vector.hpp"
#include "lib/thread.hpp"
// #include "lib/time.hpp"
#include "lib/sleep.hpp"
#include "lib/math.hpp"

// Pi constant
const double pi = 3.14159265358979323846;

// use std::wcout instead of std::cout
using std::wcout;
using std::endl;


// Main function
int main() {

    std::atexit(ansi::resetconsole);

    std::cout << 'a' + 'b' << endl;

    return 0;
}
