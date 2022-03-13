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


// #include "lib/ext/betterwindows.hpp"

void asyncthreadbenchmark(int input, bool started) {
    while(!started) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    synccout << "Thread " << input << " starting\n";

    long counter;
    vec4l item = {100, 100, 100, 100};
    while(counter <= 1000000000l) {
        counter++;
        //std::cout << counter << "\n";
        item = item + vec4l(counter, counter, counter, counter);
        // std::cout << counter << "    " << item << "\n";
    }

    synccout << "Thread " << input << " finished\n";
    //std::this_thread::yield();
    return;
}

// Main function
int main() {

    std::atexit(ansi::resetconsole);

    return 0;
}
