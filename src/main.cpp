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

    double6 thing = double5(102, 305, 507, 231, 694);

    std::cout << "thing: (" << thing << ")" << std::endl;

    std::cout << "thing.x: " << thing.x << std::endl;
    std::cout << "thing.y: " << thing.y << std::endl;
    std::cout << "thing.z: " << thing.z << std::endl;
    std::cout << "thing.w: " << thing.w << std::endl;
    std::cout << "thing.v: " << thing.v << std::endl;
    std::cout << "thing.u: " << thing.u << std::endl;

    std::cout << "thing[0]: " << thing[0] << std::endl;
    std::cout << "thing[1]: " << thing[1] << std::endl;
    std::cout << "thing[2]: " << thing[2] << std::endl;
    std::cout << "thing[3]: " << thing[3] << std::endl;
    std::cout << "thing[4]: " << thing[4] << std::endl;
    std::cout << "thing[5]: " << thing[5] << std::endl;

    return 0;

}
