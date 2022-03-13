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
#include "lib/threadcout.hpp"
// #include "lib/time.hpp"
// #include "lib/sleep.hpp"


// #include "lib/ext/betterwindows.hpp"

void clearconsole() {
    ansi::resetconsole();
}

bool started = false;

void asyncthreadbenchmark(int input) {
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
    //// Some old docs

    std::atexit(clearconsole);

    long4 test = {0, 10, 20, 30};
    
    std::cout << test;

    return 0;
}
