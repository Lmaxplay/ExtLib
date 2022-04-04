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


// Main function
int main() {

    std::atexit(ansi::resetconsole);

    ansi::setForeground(213);

    double6 thing = double5(102, 305, 507, 231, 694);

    std::cout << "thing: (" << thing << ")" << std::endl;

    return 0;

}
