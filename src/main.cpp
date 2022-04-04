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
    unsigned int n;

    while(i <= 255) {
        unsigned char bytes[4];

        bytes[0] = (n >> 24) & 0xFF;
        bytes[1] = (n >> 16) & 0xFF;
        bytes[2] = (n >> 8) & 0xFF;
        bytes[3] = n & 0xFF;
        ansi::setColor(bytes[0], bytes[1], bytes[2]);


        std::cout << std::string("X");// << (short int)i << " ";
        i++;
        n++;
        if(i == 0) {
            // break;
        }
    }

    return 0;

}
