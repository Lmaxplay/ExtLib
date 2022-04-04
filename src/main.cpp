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

    unsigned char i;

    while(i <= 255) {
        ansi::setForeground(i);
        std::cout << (short int)i << " ";
        i++;
        if(i == 0) {
            break;
        }
    }

    return 0;

}
