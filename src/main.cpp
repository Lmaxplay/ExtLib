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

    double6 thing = {102, 305, 507, 231, 694, 876};

    std::cout << "thing: (" << thing << ")" << std::endl;

    std::cout << "thing[0]: " << thing[0] << std::endl;
    std::cout << "thing[1]: " << thing[1] << std::endl;
    std::cout << "thing[2]: " << thing[2] << std::endl;
    std::cout << "thing[3]: " << thing[3] << std::endl;
    std::cout << "thing[4]: " << thing[4] << std::endl;
    std::cout << "thing[5]: " << thing[5] << std::endl;

    return 0;
}
